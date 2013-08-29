#ifndef QRIG_H
#define QRIG_H

#include <hamlib/rig.h>
#include "qtools.h"

class QRig
{

  public:

    /// Different radio operating modes to be used with SetMode().
    enum MODE
    {
      MODE_NONE = 0,
      MODE_NAM = 1,
      MODE_AM = 2,
      MODE_WAM = 4,
      MODE_SFM = 8,
      MODE_NFM = 16,
      MODE_WFM = 32,
      MODE_LSB = 64,
      MODE_USB = 128,
      MODE_CW = 256
    };

public:

  /// Constructor.
  QRig();

  /// Destructor.
  ~QRig();

  /// Connect to rig.
  /// \return Returns true on success, false on error.
  bool Connect();

  /// Disconnect from rig.
  void Disconnect();

  /// Check if rig is currently in connected state.
  /// \return Returns true if connected, and false if disconnected.
  bool Connected(){ return IsConnected; }

  /// Returns the signal strength in Db units.
  float GetSignalStrength();

  /// Returns the frequency of the currently active vfo on the radio.
  /// \return Returns the active frequency in Hz.
  int GetActiveFrequency();

  /// Sets active frequency of the currently active vfo on the radio.
  /// \param Hz New frequency for currently active vfo in Hz.
  /// \return Returns true on success, false on error.
  bool SetActiveFrequency(freq_t Hz);

  /// Sets radio tuning step in Hz.
  /// \param Hz New tuning step in Hz.
  /// \return Returns true on success, false on error.
  bool SetTuningStep(shortfreq_t Hz);

  /// Sets mode to given mode.
  /// \return bool Returns true on success, false on error.
  bool SetMode(MODE mode);

  /// Begin a VFO scan between two given frequencies.
  /// \return bool Returns true on success, false on error.
  bool VFOScan(freq_t VFO1, freq_t VFO2, shortfreq_t step);

  /// Stops any scan in progress.
  bool StopScan();

  /// Get mode for given mode as text.
  /// \return bool Returns parsed mode.
  MODE StrToMode(std::string mode);

  /// Get mode for given mode as text.
  /// \return bool Returns parsed mode.
  MODE StrToMode(QString mode);

  /// Gets current mode
  /// \return Active mode on the radio.
  MODE GetMode();

  /// Convert given mode to text.
  QString ModeToStr(MODE mode);

  /// Sets attenuator on or off.
  /// \param state Attenuator state to set.
  /// \return Returns true on success, false on error.
  bool SetAttenuator(bool state);

  /// Gets the attenuator state.
  /// \return Returns true if the attenuator is on, false if off (or unknown).
  bool GetAttenuator();

  /// Vfo right button.
  /// \return Returns true on success, false on error.
  bool VfoRight();

  /// Vfo left button.
  /// \return Returns true on success, false on error.
  bool VfoLeft();

  /// Vfo up button.
  /// \return Returns true on success, false on error.
  bool VfoUp();

  /// Vfo down button.
  /// \return Returns true on success, false on error.
  bool VfoDown();

  /// Get memory information.
  /// \param chan Fill in the channel bank_base and channel_num*100 into this object, and additional info will be filled into it if this call completes successfully.
  /// \return returns true on success, false on error.
  bool GetMemory(channel_t* chan);

private:

  /// Pointer to hamlib rig.
  RIG *Rig;
  /// Keeps track of rig connection state.
  bool IsConnected;
  /// Pointer to applicaiton


};

#endif // QRIG_H
