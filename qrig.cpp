#include <assert.h>
#include <iostream>
#include <string>
#include <QApplication>
#include <QMessageBox>
#include <QTimer>
#include "qrig.h"

// Constructor
QRig::QRig()
{
  Rig = 0;
}

// Destructor
QRig::~QRig()
{
  if (Rig)
  {
    if (IsConnected)
    {
      Disconnect();
    }
  }
}

// Connect to radio.
bool QRig::Connect()
{

  // Set up port settings.
  rig_set_debug(RIG_DEBUG_WARN);
  hamlib_port_t myport;
  std::string serial_port_file;
  myport.type.rig = RIG_PORT_SERIAL;
  myport.parm.serial.rate = 19200;
  myport.parm.serial.data_bits = 8;
  myport.parm.serial.stop_bits = 2;
  myport.parm.serial.parity = RIG_PARITY_NONE;
  myport.parm.serial.handshake = RIG_HANDSHAKE_XONXOFF;
  serial_port_file = "/dev/ttyS0";
  strncpy(myport.pathname,serial_port_file.c_str(),serial_port_file.length());
  rig_load_all_backends();
  rig_model_t myrig_model = 501; // 501 = AOR AR8200

  // Initialize and connect.
  Rig = rig_init(myrig_model);
  if (!Rig)
  {
    QMessageBox msg(QMessageBox::Critical,"Error","Could not initialize hamlib radio.");
    msg.exec();
    return false;
  }
  if (rig_open(Rig) != RIG_OK)
  {
    QMessageBox msg(QMessageBox::Critical,"Error","Could not connect to radio.");
    msg.exec();
    IsConnected = false;
    return false;
  }
  else
  {
    IsConnected = true;
    return true;
  }
}

// Disconnect from radio.
void QRig::Disconnect()
{
  rig_close(Rig);
  IsConnected = false;
}

// Get signal strength from radio.
float QRig::GetSignalStrength()
{
  // Sanity checks.
  if (!Rig) return -999;
  if (!Connected()) return -999;
  // Get signal strength and return it.
  int signal_strength = 0;
  int retcode = rig_get_strength(Rig,RIG_VFO_CURR,&signal_strength);
  if (retcode == RIG_OK)
  {
    return signal_strength;
  }
  return -999;
}

// Get frequency of active vfo in hz
int QRig::GetActiveFrequency()
{
  // Sanity checks.
  if (!Rig)
  {
    std::cerr << "Attempting to get frequency but rig is not initialized." << std::endl;
    return -1;
  }
  if (!Connected())
  {
    std::cerr << "Attempting to get frequency but not connected" << std::endl;
    return -1;
  }
  // Get freq. and return it.
  freq_t frequency = 0;
  int retcode = rig_get_freq(Rig,RIG_VFO_CURR,&frequency);
  if (retcode == RIG_OK)
  {
    return frequency;
  }
  else
  {
    std::cerr << "Communication error with radio when fetching frequency." << std::endl;
    return -1;
  }
}

bool QRig::SetActiveFrequency(freq_t Hz)
{
  // Sanity checks.
  if (!Rig) return false;
  if (!Connected()) return false;
  if (Hz <= 0) return false;
  // Set frequency.
  freq_t frequency = Hz;
  int retcode = rig_set_freq(Rig,RIG_VFO_CURR,frequency);
  if (retcode == RIG_OK)
  {
    return true;
  }
  return false;
}

// Sets radio tuning step in Hz.
bool QRig::SetTuningStep(shortfreq_t Hz)
{
  // Sanity checks.
  if (!Rig) return false;
  if (!Connected()) return false;
  if (Hz <= 0) return false;
  if (rig_set_ts(Rig,RIG_VFO_CURR,Hz) != RIG_OK)
  {
    return false;
  }
  if (rig_set_ts(Rig,RIG_VFO_A,Hz) != RIG_OK)
  {
    return false;
  }
  if (rig_set_ts(Rig,RIG_VFO_B,Hz) != RIG_OK)
  {
    return false;
  }
  return true;
}

// Set radio operating mode.
bool QRig::SetMode(QRig::MODE mode)
{
  // Sanity checks.
  if (!Rig) return false;
  if (!Connected()) return false;
  // Set mode
  int result;
  switch(mode)
  {
    case QRig::MODE_NAM:
      result = rig_set_mode(Rig,RIG_VFO_CURR,RIG_MODE_AM,rig_passband_narrow(Rig,RIG_MODE_AM));
      break;
    case QRig::MODE_AM:
      result = rig_set_mode(Rig,RIG_VFO_CURR,RIG_MODE_AM,RIG_PASSBAND_NORMAL);
      break;
    case QRig::MODE_WAM:
      result = rig_set_mode(Rig,RIG_VFO_CURR,RIG_MODE_AM,rig_passband_wide(Rig,RIG_MODE_AM));
      break;
    case QRig::MODE_SFM:
      result = rig_set_mode(Rig,RIG_VFO_CURR,RIG_MODE_FM,rig_passband_narrow(Rig,RIG_MODE_FM));
      break;
    case QRig::MODE_NFM:
      result = rig_set_mode(Rig,RIG_VFO_CURR,RIG_MODE_FM,RIG_PASSBAND_NORMAL);
      break;
    case QRig::MODE_WFM:
      result = rig_set_mode(Rig,RIG_VFO_CURR,RIG_MODE_WFM,RIG_PASSBAND_NORMAL);
      break;
    case QRig::MODE_LSB:
      result = rig_set_mode(Rig,RIG_VFO_CURR,RIG_MODE_LSB,RIG_PASSBAND_NORMAL);
      break;
    case QRig::MODE_USB:
      result = rig_set_mode(Rig,RIG_VFO_CURR,RIG_MODE_USB,RIG_PASSBAND_NORMAL);
      break;
    case QRig::MODE_CW:
      result = rig_set_mode(Rig,RIG_VFO_CURR,RIG_MODE_CW,RIG_PASSBAND_NORMAL);
      break;
    case QRig::MODE_NONE:
      return false;
      break;
    default:
      return false;
      break;
  }
  if (result == RIG_OK)
  {
    return true;
  }
  return false;
}

// Sets attenuator on or off.
bool QRig::SetAttenuator(bool state)
{
  // Sanity checks.
  if (!Rig) return false;
  if (!Connected()) return false;
  // Set attenuator.
  int result = 0;
  if (state)
  {
    value_t val;
    val.i = 20;
    result = rig_set_level(Rig,RIG_VFO_CURR,RIG_LEVEL_ATT,val);
  }
  else
  {
    value_t val;
    val.i = 0;
    result = rig_set_level(Rig,RIG_VFO_CURR,RIG_LEVEL_ATT,val);
  }
  if (result == RIG_OK)
  {
    return true;
  }
  return false;
}

// Get attenuator value
/// \todo This doesn't seem to work on AR8200 with hamlib?
///       'Unsupported att aor_get_level -35'
bool QRig::GetAttenuator()
{
  // Sanity checks.
  if (!Rig) return false;
  if (!Connected()) return false;
  // Get attenuator value.
  value_t val;
  rig_get_level(Rig,RIG_VFO_CURR,RIG_LEVEL_ATT,&val);
  if (val.i == 20)
  {
    return true;
  }
  else
  {
    return false;
  }
}


// Gets current mode
QRig::MODE QRig::GetMode()
{
  // Sanity checks.
  if (!Rig) return MODE_NONE;
  if (!Connected()) return MODE_NONE;
  // Get mode
  rmode_t mode;
  pbwidth_t width;
  QRig::MODE result;
  rig_get_mode(Rig,RIG_VFO_CURR,&mode,&width);
  // Convert to QRig::MODE
  switch(mode)
  {
    case RIG_MODE_AM:
      if (width == rig_passband_narrow(Rig,RIG_MODE_AM))
      {
        result = MODE_NAM;
      }
      else if (width == rig_passband_normal(Rig,RIG_MODE_AM))
      {
        result = MODE_AM;
      }
      else if (width == rig_passband_wide(Rig,RIG_MODE_AM))
      {
        result = MODE_WAM;
      }
      else
      {
        result = MODE_NONE;
      }
      break;
    case RIG_MODE_FM:
      if (width == rig_passband_narrow(Rig,RIG_MODE_FM))
      {
        result = MODE_SFM;
      }
      else if (width == rig_passband_normal(Rig,RIG_MODE_FM))
      {
        result = MODE_NFM;
      }
      else
      {
        result = MODE_NONE;
      }
      break;
    case RIG_MODE_WFM:
      result = MODE_WFM;
      break;
    case RIG_MODE_LSB:
      result = MODE_LSB;
      break;
    case RIG_MODE_USB:
      result = MODE_USB;
      break;
    case RIG_MODE_CW:
      result = MODE_CW;
      break;
    default:
      result = MODE_NONE;
      break;
  }
  return result;
}

QRig::MODE QRig::StrToMode(std::string mode)
{
  QRig::MODE result = QRig::MODE_NONE;
  if (mode == "AM") result = QRig::MODE_AM;
  if (mode == "CW/DATA") result = QRig::MODE_CW;
  if (mode == "LSB") result = QRig::MODE_LSB;
  if (mode == "NAM") result = QRig::MODE_NAM;
  if (mode == "NFM") result = QRig::MODE_NFM;
  if (mode == "SFM") result = QRig::MODE_SFM;
  if (mode == "USB") result = QRig::MODE_USB;
  if (mode == "WAM") result = QRig::MODE_WAM;
  if (mode == "WFM") result = QRig::MODE_WFM;
  return result;
}

QString QRig::ModeToStr(QRig::MODE mode)
{
  std::string modestr;
  switch(mode)
  {
    case QRig::MODE_AM:
      modestr="AM";
      break;
    case QRig::MODE_CW:
      modestr="CW/DATA";
      break;
    case QRig::MODE_LSB:
      modestr="LSB";
      break;
    case QRig::MODE_NAM:
      modestr="SAM";
      break;
    case QRig::MODE_NFM:
      modestr="NFM";
      break;
    case QRig::MODE_SFM:
      modestr="SFM";
      break;
    case QRig::MODE_USB:
      modestr="USB";
      break;
    case QRig::MODE_WAM:
      modestr="WAM";
      break;
    case QRig::MODE_WFM:
      modestr="WFM";
      break;
    default:
      modestr="";
      break;
  }
  return QString(modestr.c_str());
}

QRig::MODE QRig::StrToMode(QString mode)
{
  std::string strmode = mode.toUtf8().constData();
  return StrToMode(strmode);
}

// Begin a VFO scan between two given frequencies.
bool QRig::VFOScan(freq_t VFO1, freq_t VFO2, shortfreq_t step)
{  
  if (!Rig) return false;
  if (!Connected()) return false;  
  qtools::sleep(250);
  rig_set_freq(Rig, RIG_VFO_A, VFO1);
  qtools::sleep(250);
  rig_set_ts(Rig,RIG_VFO_A,step);
  qtools::sleep(250);
  rig_set_freq(Rig, RIG_VFO_B, VFO2);
  qtools::sleep(250);
  rig_set_ts(Rig,RIG_VFO_B,step);
  qtools::sleep(250);
  int result = rig_scan(Rig,RIG_VFO_CURR,RIG_SCAN_PROG,0);
  return (result == RIG_OK);
}

bool QRig::StopScan()
{
  if (!Rig) return false;
  if (!Connected()) return false;
  int result = rig_scan(Rig,RIG_VFO_CURR,RIG_SCAN_STOP,0);
  return (result == RIG_OK);
}


// Vfo right button.
bool QRig::VfoRight()
{
  if (!Rig) return false;
  if (!Connected()) return false;
  return (rig_vfo_op(Rig,RIG_VFO_CURR,RIG_OP_RIGHT) == RIG_OK);
}

// Vfo left button.
bool QRig::VfoLeft()
{
  if (!Rig) return false;
  if (!Connected()) return false;
  return (rig_vfo_op(Rig,RIG_VFO_CURR,RIG_OP_LEFT) == RIG_OK);
}

// Vfo up button.
bool QRig::VfoUp()
{
  if (!Rig) return false;
  if (!Connected()) return false;
  return (rig_vfo_op(Rig,RIG_VFO_CURR,RIG_OP_UP) == RIG_OK);
}

// Vfo down button.
bool QRig::VfoDown()
{
  if (!Rig) return false;
  if (!Connected()) return false;
  return (rig_vfo_op(Rig,RIG_VFO_CURR,RIG_OP_DOWN) == RIG_OK);
}

// Get memory information.
bool QRig::GetMemory(channel_t* chan)
{
  if (!Rig) return false;
  if (!Connected()) return false;
  assert(chan);
  return rig_get_channel(Rig,chan);
}

