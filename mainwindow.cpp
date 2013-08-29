#include <stdio.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>
#include <QDateTime>
#include <QtSql/QSqlError>
#include <QFile>
#include <QDir>
#include <QProcess>
#include <QTimer>
#include <stdlib.h>
#include "qtools.h"
#include "tools.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qrig.h"

// Constructor
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow),
    SignalUpdateTimer(this), FrequencyUpdateTimer(this)
{      
  // Init user interface.
  ignore_frequency_list_changes=false;
  ui->setupUi(this);
  statusBar()->showMessage(tr("Not connected to radio."));
  PreviousDialPosition = ui->dial->value();
  CurrentFrequency = 0;
  TuneStep = 5;
  LogSignalCounter = 0;
  LogSignalTotal = 0;
  logging_on = false;
  recording = false;
  output = new QFile();
  ui->CmbModes->addItem(tr("SAM"),QRig::MODE_NAM);
  ui->CmbModes->addItem(tr("AM"),QRig::MODE_AM);
  ui->CmbModes->addItem(tr("WAM"),QRig::MODE_WAM);
  ui->CmbModes->addItem(tr("SFM"),QRig::MODE_SFM);
  ui->CmbModes->addItem(tr("NFM"),QRig::MODE_NFM);
  ui->CmbModes->addItem(tr("WFM"),QRig::MODE_WFM);
  ui->CmbModes->addItem(tr("LSB"),QRig::MODE_LSB);
  ui->CmbModes->addItem(tr("USB"),QRig::MODE_USB);
  ui->CmbModes->addItem(tr("CW/DATA"),QRig::MODE_CW);  
  ui->CmbVfoScanMode->addItem(tr("SAM"),QRig::MODE_NAM);
  ui->CmbVfoScanMode->addItem(tr("AM"),QRig::MODE_AM);
  ui->CmbVfoScanMode->addItem(tr("WAM"),QRig::MODE_WAM);
  ui->CmbVfoScanMode->addItem(tr("SFM"),QRig::MODE_SFM);
  ui->CmbVfoScanMode->addItem(tr("NFM"),QRig::MODE_NFM);
  ui->CmbVfoScanMode->addItem(tr("WFM"),QRig::MODE_WFM);
  ui->CmbVfoScanMode->addItem(tr("LSB"),QRig::MODE_LSB);
  ui->CmbVfoScanMode->addItem(tr("USB"),QRig::MODE_USB);
  ui->CmbVfoScanMode->addItem(tr("CW/DATA"),QRig::MODE_CW);
  ui->CmbVfoScanStep->addItem(tr("50 Hz"),QVariant(50));
  ui->CmbVfoScanStep->addItem(tr("100 Hz"),QVariant(100));
  ui->CmbVfoScanStep->addItem(tr("200 Hz"),QVariant(200));
  ui->CmbVfoScanStep->addItem(tr("500 Hz"),QVariant(500));
  ui->CmbVfoScanStep->addItem(tr("1 kHz"),QVariant(1000));
  ui->CmbVfoScanStep->addItem(tr("2 kHz"),QVariant(2000));
  ui->CmbVfoScanStep->addItem(tr("5 kHz"),QVariant(5000));
  ui->CmbVfoScanStep->addItem(tr("6.25 kHz"),QVariant(6250));
  ui->CmbVfoScanStep->addItem(tr("8.33 kHz"),QVariant(8330));
  ui->CmbVfoScanStep->addItem(tr("9 kHz"),QVariant(9000));
  ui->CmbVfoScanStep->addItem(tr("10 kHz"),QVariant(10000));
  ui->CmbVfoScanStep->addItem(tr("12.5 kHz"),QVariant(12500));
  ui->CmbVfoScanStep->addItem(tr("20 kHz"),QVariant(20000));
  ui->CmbVfoScanStep->addItem(tr("25 kHz"),QVariant(25000));
  ui->CmbVfoScanStep->addItem(tr("30 kHz"),QVariant(30000));
  ui->CmbVfoScanStep->addItem(tr("50 kHz"),QVariant(50000));
  ui->CmbVfoScanStep->addItem(tr("100 kHz"),QVariant(100000));
  frequency_category_menu = new QMenu(ui->TreeFrequencyCategories);
  frequency_category_menu->addAction(this->ui->actionNew_category);
  frequency_category_menu->addAction(this->ui->actionRemove_Category);
  frequency_category_menu->addAction(this->ui->actionRe_name_category);
  frequency_list_menu = new QMenu(ui->LstFrequencies);
  // Init audio
  QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
  QAudioFormat format;
  format.setFrequency(8000);
  format.setChannels(1);
  format.setSampleSize(8);
  format.setCodec("audio/pcm");
  format.setByteOrder(QAudioFormat::LittleEndian);
  format.setSampleType(QAudioFormat::UnSignedInt);
  if (!info.isFormatSupported(format))
  {
    QMessageBox msg(QMessageBox::Warning,"audio input","Default format supported. try to use neareset",0,this,0);
    msg.exec();
    format = info.nearestFormat(format);
  }
  audio_in = new QAudioInput(info.preferredFormat(),this);
  audio_out = new QAudioOutput(info.preferredFormat(),this);
  // Init database.
  db = QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName("localhost");
  db.setUserName("qtar8200");
  db.setDatabaseName("qtar8200");
  db.setPassword("qtar8200");
  db.setConnectOptions("MYSQL_OPT_RECONNECT=1");
  frequencies = new QFrequencyDatabase(&db,this);
  if (!db.open())
  {
      QMessageBox msg(QMessageBox::Warning,"Could not connect to database",db.lastError().text(),0,this,0);
      msg.exec();
  }
  // Connect slots.
  connect(&SignalUpdateTimer,SIGNAL(timeout()),this,SLOT(UpdateSignal()));
  connect(&FrequencyUpdateTimer,SIGNAL(timeout()),this,SLOT(UpdateFrequency()));
  connect(&LogTimer,SIGNAL(timeout()),this,SLOT(UpdateLog()));
  // Init UI elements that depend on database.
  FillFrequencyCategoryTreeView();
  ui->TreeFrequencyCategories->expandAll();
}

// Destructor
MainWindow::~MainWindow()
{
  delete ui;
  delete frequencies;
}

// Fill frequency database treeview.
void MainWindow::FillFrequencyCategoryTreeView(QTreeWidgetItem* parent)
{
  int category_id = 0;
  if (parent != 0)
  {
    category_id = parent->data(0,Qt::UserRole).toInt();
  }
  QFrequencyDatabase::categories categories_to_add = frequencies->GetCategories(category_id);
  for (
       QFrequencyDatabase::categories::iterator it = categories_to_add.begin();
       it != categories_to_add.end();
       ++it
      )
  {
    // Add tree item for current item.
    QFrequencyDatabase::category* current_category = (*it);
    QTreeWidgetItem* category = 0;
    if (parent==0)
    {
      category = new QTreeWidgetItem(ui->TreeFrequencyCategories,0);
    }
    else
    {
      category = new QTreeWidgetItem(parent,0);
    }
    category->setText(0,current_category->name.c_str());
    category->setData(0,Qt::UserRole,current_category->id);
    current_category->tree_item = category;
    // Add children.
    FillFrequencyCategoryTreeView(category);
  }
}

// Connect menu clicked.
void MainWindow::on_action_Connect_to_rig_triggered()
{
  if (Radio.Connect())
  {
    statusBar()->showMessage(tr("Connected to AR8200."));
    SignalUpdateTimer.start(250);
    FrequencyUpdateTimer.start(500);
  }
  else
  {
    statusBar()->showMessage(tr("Error connecting to AR8200..."));
  }
}

void MainWindow::UpdateLog()
{
  LogSignalCounter++;
  LogSignalTotal += CurrentSignal;
  float signal = LogSignalTotal / LogSignalCounter;
  if (LogSignalCounter > 4)
  {
    LogSignalTotal = 0;
    LogSignalCounter = 0;
  }
  // Update signal and frequency _once_
  UpdateFrequency();
  UpdateSignal();
  // Handle logging
  if (logging_on == true)
  {
    signal = 54.0f + signal;
    if (signal > ui->TxtLogSquelch->text().toFloat())
    {
      if (recording == false)
      {
        ui->statusBar->showMessage(tr("Logging new signal."));
        recording = true;
        // Generate filename
        QString filename = QDir::homePath();
        filename += tr("/.qtar8200/");
        filename += QDateTime::currentDateTime().toString(tr("yyyy-mm-dd_hh-mm-ss"));
        filename += tr(".wav");
        // Open output file
        output->setFileName(filename);
        output->open(QIODevice::WriteOnly|QIODevice::Truncate);
        frequencies->Log(ui->Frequency->text().toUtf8().constData(),Radio.GetMode(),filename.toUtf8().constData());
        UpdateLogTable();
        // Begin recording audio.
        audio_in->setNotifyInterval(100);
        audio_in->start(output);
      }
      else
      {
        ui->statusBar->showMessage(tr("Recording..."));
      }
    }
    else
    {
      std::ostringstream ss;
      ss << signal;
      ui->statusBar->showMessage(tr("No signal detected. ( Level: ") + ss.str().c_str() + tr(" )"));
      if (recording)
      {
        audio_in->stop();
        recording = false;
        output->close();
        // Encode file.
        QString filename = output->fileName();
        QString basename = QFileInfo(filename).baseName();
        QString path = QFileInfo(filename).path();
        QString params = "-r -b44100 ";
        params += filename;
        params += " ";
        params += path;
        params += "/";
        params += basename;
        params += ".mp3 ; rm ";
        params += filename;
        QProcess* proc = new QProcess(this);
        proc->start(tr("/usr/bin/lame"),QStringList() << params);
        connect(proc,SIGNAL(finished(int)),this,SLOT(CleanupProcs()));
        processes.push_back(proc);

      }
    }
  }
}

// SignalUpdateTimer triggered.
void MainWindow::UpdateSignal()
{
  if (Radio.Connected())
  {
    QString str;
    float signal = Radio.GetSignalStrength();
    if ((signal < -100) || (signal > 100))
    {
      // Probably read error. Ignore and don't update.
      return;
    }
    ui->SMeter->SetDb(signal);
    CurrentSignal = signal;
  }
}

// FrequencyUpdateTimer triggered.
void MainWindow::UpdateFrequency()
{
  if (Radio.Connected())
  {
    float curr_MHz = Radio.GetActiveFrequency()/1000.0f/1000.0f;
    // Don't update if data is not valid.
    if (curr_MHz < 0)
    {
      std::cerr << "Invalid freq received.";
      return;
    }
    std::ostringstream  ostr_label_text;
    ostr_label_text << curr_MHz << " MHz";
    ui->Frequency->setText(ostr_label_text.str().c_str());
    CurrentFrequency = curr_MHz;
  }
}

// Quit menu item clicked.
void MainWindow::on_action_Quit_triggered()
{
  close();
}

// VFO Dial changed.
void MainWindow::on_dial_valueChanged(int value)
{
  std::ostringstream text;
  if (Radio.Connected())
  {
    freq_t OldFrequency = Radio.GetActiveFrequency();
    freq_t NewFrequency = OldFrequency;
    bool changed = false;
    int difference = value - PreviousDialPosition;
    double change = TuneStep * 10;
    // tune the difference.
    if (difference == 0) return;
    if (difference > 0)
    {
      NewFrequency += change;
    }
    if (difference < 0)
    {
      NewFrequency -= change;
    }
    changed = Radio.SetActiveFrequency(NewFrequency);
    if (changed)
    {
      UpdateFrequency();
    }
    PreviousDialPosition = value;
  }
}

void MainWindow::on_CmdFiveKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(5 * 1000))
    {
      TuneStep = 500;
      statusBar()->showMessage(tr("Tune step set to 5 KHz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdTenKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(10 * 1000))
    {
      TuneStep = 1000;
      statusBar()->showMessage(tr("Tune step set to 10 KHz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdTwentyKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(20 * 1000))
    {
      TuneStep = 2000;
      statusBar()->showMessage(tr("Tune step set to 20."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdTwentyFiveKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(25 * 1000))
    {
      TuneStep = 2500;
      statusBar()->showMessage(tr("Tune step set to 25."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdThirtyKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(30 * 1000))
    {
      TuneStep = 3000;
      statusBar()->showMessage(tr("Tune step set to 30."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdFiftyKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(50 * 1000))
    {
      TuneStep = 5000;
      statusBar()->showMessage(tr("Tune step set to 50."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdHundredKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(100 * 1000))
    {
      TuneStep = 10000;
      statusBar()->showMessage(tr("Tune step set to 100."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_FrequencyEdit_returnPressed()
{
  // Default is MHz, so 1000*1000
  double multiplier = 1000*1000;
  float frequency = ui->FrequencyEdit->text().toFloat();
  if (frequency > 3000)
  {
    // Guess that user is trying to use KHz instead of MHz.
    multiplier = 1000;
  }
  if (frequency > 3000000)
  {
    // Guess that user is trying to use Hz.
    multiplier = 1;
  }
  if (Radio.SetActiveFrequency(frequency * multiplier))
  {
    statusBar()->showMessage(tr("Frequency updated."));
    UpdateFrequency();
    ui->FrequencyEdit->selectAll();
    ui->FrequencyEdit->setFocus();
  }
  else
  {
    statusBar()->showMessage(tr("Could not set frequency."));
  }
}

void MainWindow::on_CmdAM_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetMode(QRig::MODE_AM))
    {
      statusBar()->showMessage(tr("Mode Set to AM."));
      ui->CmdSAM->setChecked(false);
      ui->CmdAM->setChecked(true);
      ui->CmdWAM->setChecked(false);
      ui->CmdSFM->setChecked(false);
      ui->CmdNFM->setChecked(false);
      ui->CmdWFM->setChecked(false);
      ui->CmdLSB->setChecked(false);
      ui->CmdUSB->setChecked(false);
      ui->CmdCW->setChecked(false);
      ui->FrequencyEdit->selectAll();
      ui->FrequencyEdit->setFocus();
    }
    else
    {
      statusBar()->showMessage(tr("Could not set mode."));
      ui->CmdAM->setChecked(false);
    }
  }
}

void MainWindow::on_CmdSAM_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetMode(QRig::MODE_NAM))
    {
      statusBar()->showMessage(tr("Mode Set to NAM."));
      ui->CmdSAM->setChecked(true);
      ui->CmdAM->setChecked(false);
      ui->CmdWAM->setChecked(false);
      ui->CmdSFM->setChecked(false);
      ui->CmdNFM->setChecked(false);
      ui->CmdWFM->setChecked(false);
      ui->CmdLSB->setChecked(false);
      ui->CmdUSB->setChecked(false);
      ui->CmdCW->setChecked(false);
      ui->FrequencyEdit->selectAll();
      ui->FrequencyEdit->setFocus();
    }
    else
    {
      statusBar()->showMessage(tr("Could not set mode."));
      ui->CmdSAM->setChecked(false);
    }
  }
}

void MainWindow::on_CmdWAM_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetMode(QRig::MODE_WAM))
    {
      statusBar()->showMessage(tr("Mode Set to WAM."));
      ui->CmdSAM->setChecked(false);
      ui->CmdAM->setChecked(false);
      ui->CmdWAM->setChecked(true);
      ui->CmdSFM->setChecked(false);
      ui->CmdNFM->setChecked(false);
      ui->CmdWFM->setChecked(false);
      ui->CmdLSB->setChecked(false);
      ui->CmdUSB->setChecked(false);
      ui->CmdCW->setChecked(false);
      ui->FrequencyEdit->selectAll();
      ui->FrequencyEdit->setFocus();
    }
    else
    {
      statusBar()->showMessage(tr("Could not set mode."));
      ui->CmdWAM->setChecked(false);
    }
  }
}

void MainWindow::on_CmdSFM_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetMode(QRig::MODE_SFM))
    {
      statusBar()->showMessage(tr("Mode Set to SFM."));
      ui->CmdSAM->setChecked(false);
      ui->CmdAM->setChecked(false);
      ui->CmdWAM->setChecked(false);
      ui->CmdSFM->setChecked(true);
      ui->CmdNFM->setChecked(false);
      ui->CmdWFM->setChecked(false);
      ui->CmdLSB->setChecked(false);
      ui->CmdUSB->setChecked(false);
      ui->CmdCW->setChecked(false);
      ui->FrequencyEdit->selectAll();
      ui->FrequencyEdit->setFocus();
    }
    else
    {
      statusBar()->showMessage(tr("Could not set mode."));
      ui->CmdSFM->setChecked(false);
    }
  }
}

void MainWindow::on_CmdNFM_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetMode(QRig::MODE_NFM))
    {
      statusBar()->showMessage(tr("Mode Set to NFM."));
      ui->CmdSAM->setChecked(false);
      ui->CmdAM->setChecked(false);
      ui->CmdWAM->setChecked(false);
      ui->CmdSFM->setChecked(false);
      ui->CmdNFM->setChecked(true);
      ui->CmdWFM->setChecked(false);
      ui->CmdLSB->setChecked(false);
      ui->CmdUSB->setChecked(false);
      ui->CmdCW->setChecked(false);
      ui->FrequencyEdit->selectAll();
      ui->FrequencyEdit->setFocus();
    }
    else
    {
      statusBar()->showMessage(tr("Could not set mode."));
      ui->CmdNFM->setChecked(false);
    }
  }
}

void MainWindow::on_CmdWFM_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetMode(QRig::MODE_WFM))
    {
      statusBar()->showMessage(tr("Mode Set to WFM."));
      ui->CmdSAM->setChecked(false);
      ui->CmdAM->setChecked(false);
      ui->CmdWAM->setChecked(false);
      ui->CmdSFM->setChecked(false);
      ui->CmdNFM->setChecked(false);
      ui->CmdWFM->setChecked(true);
      ui->CmdLSB->setChecked(false);
      ui->CmdUSB->setChecked(false);
      ui->CmdCW->setChecked(false);
      ui->FrequencyEdit->selectAll();
      ui->FrequencyEdit->setFocus();
    }
    else
    {
      statusBar()->showMessage(tr("Could not set mode."));
      ui->CmdWFM->setChecked(false);
    }
  }
}


void MainWindow::on_CmdLSB_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetMode(QRig::MODE_LSB))
    {
      statusBar()->showMessage(tr("Mode Set to LSB."));
      ui->CmdSAM->setChecked(false);
      ui->CmdAM->setChecked(false);
      ui->CmdWAM->setChecked(false);
      ui->CmdSFM->setChecked(false);
      ui->CmdNFM->setChecked(false);
      ui->CmdWFM->setChecked(false);
      ui->CmdLSB->setChecked(true);
      ui->CmdUSB->setChecked(false);
      ui->CmdCW->setChecked(false);
      ui->FrequencyEdit->selectAll();
      ui->FrequencyEdit->setFocus();
    }
    else
    {
      statusBar()->showMessage(tr("Could not set mode."));
      ui->CmdLSB->setChecked(false);
    }
  }
}

void MainWindow::on_CmdUSB_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetMode(QRig::MODE_USB))
    {
      statusBar()->showMessage(tr("Mode Set to USB."));
      ui->CmdSAM->setChecked(false);
      ui->CmdAM->setChecked(false);
      ui->CmdWAM->setChecked(false);
      ui->CmdSFM->setChecked(false);
      ui->CmdNFM->setChecked(false);
      ui->CmdWFM->setChecked(false);
      ui->CmdLSB->setChecked(false);
      ui->CmdUSB->setChecked(true);
      ui->CmdCW->setChecked(false);
      ui->FrequencyEdit->selectAll();
      ui->FrequencyEdit->setFocus();
    }
    else
    {
      statusBar()->showMessage(tr("Could not set mode."));
      ui->CmdUSB->setChecked(false);
    }
  }
}

void MainWindow::on_CmdCW_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetMode(QRig::MODE_CW))
    {
      statusBar()->showMessage(tr("Mode Set to CW."));
      ui->CmdSAM->setChecked(false);
      ui->CmdAM->setChecked(false);
      ui->CmdWAM->setChecked(false);
      ui->CmdSFM->setChecked(false);
      ui->CmdNFM->setChecked(false);
      ui->CmdWFM->setChecked(false);
      ui->CmdLSB->setChecked(false);
      ui->CmdUSB->setChecked(false);
      ui->CmdCW->setChecked(true);
      ui->FrequencyEdit->selectAll();
      ui->FrequencyEdit->setFocus();
    }
    else
    {
      statusBar()->showMessage(tr("Could not set mode."));
      ui->CmdCW->setChecked(false);
    }
  }
}

void MainWindow::on_action_Disconnect_from_rig_triggered()
{
  Radio.Disconnect();
  statusBar()->showMessage(tr("Disconnected from radio."));
}


void MainWindow::on_CmdTwelvePointFiveKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(12.5 * 1000))
    {
      TuneStep = 1250;
      statusBar()->showMessage(tr("Tune step set to 12.5 KHz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdNineKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(9 * 1000))
    {
      TuneStep = 900;
      statusBar()->showMessage(tr("Tune step set to 9 KHz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdEightPointThirtyThreeKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(8.33 * 1000))
    {
      TuneStep = 833;
      statusBar()->showMessage(tr("Tune step set to 8.33 KHz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdSixAndOneQuartKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(6.25 * 1000))
    {
      TuneStep = 625;
      statusBar()->showMessage(tr("Tune step set to 6.25 KHz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdTwoKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(2 * 1000))
    {
      TuneStep = 200;
      statusBar()->showMessage(tr("Tune step set to 2 KHz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdOneKHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(1000))
    {
      TuneStep = 100;
      statusBar()->showMessage(tr("Tune step set to 1 KHz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdFiveHundredHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(500))
    {
      TuneStep = 50;
      statusBar()->showMessage(tr("Tune step set to 500 Hz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdTwoHundredHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(200))
    {
      TuneStep = 20;
      statusBar()->showMessage(tr("Tune step set to 200 Hz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdHundredHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(100))
    {
      TuneStep = 10;
      statusBar()->showMessage(tr("Tune step set to 100 Hz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdFiftyHz_toggled(bool checked)
{
  if (checked)
  {
    if (Radio.SetTuningStep(50))
    {
      TuneStep = 5;
      statusBar()->showMessage(tr("Tune step set to 50 Hz."));
    }
    else
    {
      ui->CmdFiveKHz->setChecked(false);
      statusBar()->showMessage(tr("Could not set tune step."));
    }
  }
}

void MainWindow::on_CmdATT_toggled(bool checked)
{
  if (Radio.Connected())
  {
    if (Radio.SetAttenuator(checked))
    {
      statusBar()->showMessage(tr("Attenuator toggled."));
    }
    else
    {
      statusBar()->showMessage(tr("Could not set attenuator."));
    }
  }
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
  /* // Uncomment if you want to debug what the current tab is.
  std::ostringstream ostr;
  ostr << "Index = ";
  ostr << index;
  QMessageBox msg(QMessageBox::Question,"Close",ostr.str().c_str(),0,this,0);
  msg.exec(); */
  if (index == 0)
  {
    // Start GUI update timers for tuning tab.
    if (!logging_on)
    {
      SignalUpdateTimer.start(250);
      FrequencyUpdateTimer.start(500);
    }
  }
  else
  {
    // No more need to update gui for tuning tab.
    //SignalUpdateTimer.stop();
    //FrequencyUpdateTimer.stop();
  }
  if (index == 1)
  {
    if (Radio.Connected())
    {
      // Fill out current radio settings into form.
      QRig::MODE current_mode = Radio.GetMode();
      SetModeComboMode(current_mode);
      float curr_MHz = Radio.GetActiveFrequency()/1000.0f/1000.0f;
      // Don't update if data is not valid.
      if (curr_MHz < 0)
      {
        std::cerr << "Invalid freq received.";
        return;
      }
      std::ostringstream  ostr_label_text;
      ostr_label_text << curr_MHz;
      ui->TxtFrequency->setText(ostr_label_text.str().c_str());
      //ui->ChkAttenuator->setChecked(Radio.GetAttenuator());
      ui->ChkAttenuator->setChecked(ui->CmdATT->isChecked());
    }
  }
  // log tab, update log table.
  if (index == 4)
  {
    UpdateLogTable();
  }
}

// Sets mode combo mode to given qrig mode value.
void MainWindow::SetModeComboMode(QRig::MODE mode)
{
  switch(mode)
  {
    case QRig::MODE_NAM:
      ui->CmbModes->setCurrentIndex(ui->CmbModes->findText(tr("SAM")));
      break;
    case QRig::MODE_AM:
      ui->CmbModes->setCurrentIndex(ui->CmbModes->findText(tr("AM")));
      break;
    case QRig::MODE_WAM:
      ui->CmbModes->setCurrentIndex(ui->CmbModes->findText(tr("WAM")));
      break;
    case QRig::MODE_SFM:
      ui->CmbModes->setCurrentIndex(ui->CmbModes->findText(tr("SFM")));
      break;
    case QRig::MODE_NFM:
      ui->CmbModes->setCurrentIndex(ui->CmbModes->findText(tr("NFM")));
      break;
    case QRig::MODE_WFM:
      ui->CmbModes->setCurrentIndex(ui->CmbModes->findText(tr("WFM")));
      break;
    case QRig::MODE_LSB:
      ui->CmbModes->setCurrentIndex(ui->CmbModes->findText(tr("LSB")));
      break;
    case QRig::MODE_USB:
      ui->CmbModes->setCurrentIndex(ui->CmbModes->findText(tr("USB")));
      break;
    case QRig::MODE_CW:
      ui->CmbModes->setCurrentIndex(ui->CmbModes->findText(tr("CW/DATA")));
      break;
    default:
      break;
  }
}


void MainWindow::on_TreeFrequencyCategories_clicked(const QModelIndex &index)
{
  // Clear table.
  for (int i=ui->LstFrequencies->rowCount(); --i >= 0;)
    ui->LstFrequencies->removeRow(i);
  // Add new frequencies.
  QFrequencyDatabase::frequencies freqs = frequencies->GetFrequenciesForCategory(index.data(Qt::UserRole).toInt());
  for (QFrequencyDatabase::frequencies::iterator it = freqs.begin(); it != freqs.end(); ++it)
  {
    QFrequencyDatabase::frequency* current_freq = (*it);
    add_frequency_to_list(current_freq);
  }
}

void MainWindow::on_TreeFrequencyCategories_customContextMenuRequested(const QPoint &pos)
{
  frequency_category_menu->popup(ui->TreeFrequencyCategories->mapToGlobal(pos));
}

void MainWindow::on_LstFrequencies_customContextMenuRequested(const QPoint &pos)
{
  frequency_list_menu->popup(ui->TreeFrequencyCategories->mapToGlobal(pos));
}

void MainWindow::on_actionNew_category_triggered()
{
  // Ask for name of the new category.
  QString category_name = QInputDialog::getText(this,tr("QtAR8200"),tr("Category name?"), QLineEdit::Normal);
  if (category_name.isEmpty()) return;
  // Create category object
  QFrequencyDatabase::category* new_category = frequencies->AllocCategory();
  new_category->name = category_name.toUtf8().constData();
  QList<QTreeWidgetItem*> selected_items = ui->TreeFrequencyCategories->selectedItems();
  QTreeWidgetItem* selected_item = 0;
  for (QList<QTreeWidgetItem*>::iterator it = selected_items.begin() ; it != selected_items.end(); ++it)
  {
    selected_item = (*it);
    break;
  }
  if (selected_item)
  {
    new_category->parent_id = selected_item->data(0,Qt::UserRole).toInt();
  }
  // Add it to the tree and database.
  QTreeWidgetItem* new_tree_item=0;
  if (selected_item)
  {
    new_tree_item = new QTreeWidgetItem(selected_item,0);
  }
  else
  {
    new_tree_item = new QTreeWidgetItem(ui->TreeFrequencyCategories,0);
  }
  new_tree_item->setText(0,category_name);
  int id = frequencies->CreateCategory(new_category);
  new_tree_item->setData(0,Qt::UserRole,id);
  new_category->id = id;
}

void MainWindow::add_frequency_to_list(QFrequencyDatabase::frequency* current_freq)
{
  if (current_freq)
  {
    ignore_frequency_list_changes = true;
    int row = ui->LstFrequencies->rowCount();
    ui->LstFrequencies->insertRow(row);
    QString freqstr = current_freq->freq.c_str();
    // store frequency object id along with frequency table item text.
    QTableWidgetItem* new_freq_table_item = new QTableWidgetItem(freqstr);
    new_freq_table_item->setData(Qt::UserRole,current_freq->id);
    ui->LstFrequencies->setItem(row,0,new QTableWidgetItem(current_freq->description.c_str()));
    ui->LstFrequencies->setItem(row,1,new_freq_table_item);
    QString modestr = "";
    switch(current_freq->mode)
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
    ui->LstFrequencies->setItem(row,2,new QTableWidgetItem(modestr));
    QTableWidgetItem* AttState = new QTableWidgetItem();
    if (current_freq->attenuator)
    {
      AttState->setCheckState(Qt::Checked);
    }
    else
    {
      AttState->setCheckState(Qt::Unchecked);
    }
    ui->LstFrequencies->setItem(row,3,AttState);
    QVariant Squelch(current_freq->squelch);
    ui->LstFrequencies->setItem(row,4,new QTableWidgetItem(Squelch.toString()));
    ui->LstFrequencies->setItem(row,5,new QTableWidgetItem(current_freq->notes.c_str()));
    ignore_frequency_list_changes = false;
  }
}

void MainWindow::on_CmdAddFrequency_clicked()
{
  // Get selected frequency category id.
  int category_id = 0;
  QList<QTreeWidgetItem*> selected_items = ui->TreeFrequencyCategories->selectedItems();
  QTreeWidgetItem* selected_item = 0;
  for (QList<QTreeWidgetItem*>::iterator it = selected_items.begin() ; it != selected_items.end(); ++it)
  {
    selected_item = (*it);
    break;
  }
  if (selected_item)
  {
    category_id = selected_item->data(0,Qt::UserRole).toInt();
  }
  if (category_id == 0) return;
  // Create frequency data object.
  QFrequencyDatabase::frequency* freq = frequencies->AllocFrequency();
  freq->attenuator = ui->ChkAttenuator->isChecked();
  freq->description = ui->TxtDescription->text().toUtf8().constData();
  freq->freq = ui->TxtFrequency->text().toUtf8().constData();
  freq->id_category = category_id;
  QRig::MODE mode = Radio.StrToMode(ui->CmbModes->currentText());
  freq->mode = mode;
  freq->squelch = atoi(ui->TxtSquelch->text().toUtf8().constData());
  // Save freq object to database.
  int id = frequencies->CreateFrequency(freq);
  if (id)
  {
    freq->id = id;
    // Add frequency to list view.
    add_frequency_to_list(freq);
  }
}

void MainWindow::on_LstFrequencies_itemChanged(QTableWidgetItem *item)
{
  if (ignore_frequency_list_changes) return;
  int col = item->column();
  int row = item->row();
  QTableWidgetItem* description_item = ui->LstFrequencies->item(row,0);
  QTableWidgetItem* frequency_item = ui->LstFrequencies->item(row,1);
  QTableWidgetItem* mode_item = ui->LstFrequencies->item(row,2);
  QTableWidgetItem* attenuator_item = ui->LstFrequencies->item(row,3);
  QTableWidgetItem* squelch_item = ui->LstFrequencies->item(row,4);
  QTableWidgetItem* note_item = ui->LstFrequencies->item(row,5);
  int frequency_object_id = frequency_item->data(Qt::UserRole).toInt();
  if (!frequency_object_id) return;
  switch(col)
  {
    case 0:
      // Edited description
      frequencies->UpdateDescription(frequency_object_id,description_item->text().toUtf8().constData());
      break;
    case 1:
      // Edited frequency
      break;
    case 2:
      // Edited mode
      break;
    case 3:
      // Edited attenuator
      break;
    case 4:
      // Edited squelch.
      break;
    case 5:
      // Edited note.
      frequencies->UpdateNote(frequency_object_id,note_item->text().toUtf8().constData());
      break;
    default:
      break;
  }
}

void MainWindow::on_LstFrequencies_clicked(const QModelIndex &index)
{
  if (Radio.Connected() && ui->ChkTuneOnSelect->isChecked())
  {
    QList<QTableWidgetItem*> selected_items = ui->LstFrequencies->selectedItems();
    for (QList<QTableWidgetItem*>::iterator it = selected_items.begin() ; it != selected_items.end() ; ++it)
    {
      QTableWidgetItem* selected_item = (*it);
      int row = selected_item->row();
      QTableWidgetItem* frequency_item = ui->LstFrequencies->item(row,1);
      QTableWidgetItem* mode_item = ui->LstFrequencies->item(row,2);
      QTableWidgetItem* attenuator_item = ui->LstFrequencies->item(row,3);
      if (frequency_item)
      {
        ui->FrequencyEdit->setText(frequency_item->text());
        on_FrequencyEdit_returnPressed();
        Radio.SetMode(Radio.StrToMode(mode_item->text()));
        if (attenuator_item->checkState() == Qt::Checked)
        {
          Radio.SetAttenuator(true);
        }
        else
        {
          Radio.SetAttenuator(false);
        }
      }
    }
  }
}

void MainWindow::on_CmdBeginVFOScan_clicked()
{
  // set mode
  QRig::MODE mode = Radio.StrToMode(ui->CmbVfoScanMode->currentText());
  Radio.SetMode(mode);  
  // set vfo's
  int freq_a_mhz = ui->TxtVfoA->text().toInt();
  freq_t freq_a = freq_a_mhz * 1000 * 1000; // MHz to Hz
  int freq_b_mhz = ui->TxtVfoB->text().toInt();
  freq_t freq_b = freq_b_mhz * 1000 * 1000; // MHz to Hz
  // set step
  shortfreq_t step = ui->CmbVfoScanStep->itemData(ui->CmbVfoScanStep->currentIndex()).toInt();
  qtools::sleep(250);
  qtools::message("test");
  // begin scan
  Radio.VFOScan(freq_a,freq_b,step);

}

void MainWindow::on_CmdEndVFOScan_clicked()
{
  Radio.StopScan();
}

void MainWindow::on_CmdVfoRight_clicked()
{
  Radio.VfoRight();
}

void MainWindow::on_CmdVfoLeft_clicked()
{
  Radio.VfoLeft();
}

void MainWindow::on_CmdVfoUp_clicked()
{
  Radio.VfoUp();
}

void MainWindow::on_CmdVfoDown_clicked()
{
  Radio.VfoDown();
}

void MainWindow::on_CmdMemoryDownload_clicked()
{

  strvector banks =
  {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n",
    "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
  };
  for (auto it = banks.begin(); it != banks.end() ; ++it)
  {
    for (int chan = 0; chan < 50 ; ++chan)
    {
      channel_t chandata;
      //chandata.
    }
  }

    /*

      int row = ui->LstFrequencies->rowCount();
      ui->LstFrequencies->insertRow(row);
      QString freqstr = current_freq->freq.c_str();
      // store frequency object id along with frequency table item text.
      QTableWidgetItem* new_freq_table_item = new QTableWidgetItem(freqstr);
      new_freq_table_item->setData(Qt::UserRole,current_freq->id);
      ui->LstFrequencies->setItem(row,0,new QTableWidgetItem(current_freq->description.c_str()));
      ui->LstFrequencies->setItem(row,1,new_freq_table_item);
      QString modestr = "";
      switch(current_freq->mode)
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
      ui->LstFrequencies->setItem(row,2,new QTableWidgetItem(modestr));
      QTableWidgetItem* AttState = new QTableWidgetItem();
      if (current_freq->attenuator)
      {
        AttState->setCheckState(Qt::Checked);
      }
      else
      {
        AttState->setCheckState(Qt::Unchecked);
      }
      ui->LstFrequencies->setItem(row,3,AttState);
      QVariant Squelch(current_freq->squelch);
      ui->LstFrequencies->setItem(row,4,new QTableWidgetItem(Squelch.toString()));
      ui->LstFrequencies->setItem(row,5,new QTableWidgetItem(current_freq->notes.c_str()));
      ignore_frequency_list_changes = false;
    }
    */
}

void MainWindow::on_LstFrequencies_3_doubleClicked(const QModelIndex &index)
{

}

void MainWindow::on_CmdStartLog_clicked()
{
  logging_on = true;
  // stop updating signal and freq because too many radio at this time will cause audio to skip.
  // the only solution would be to use a separate thread for recording.
  SignalUpdateTimer.stop();
  FrequencyUpdateTimer.stop();
  // Start log timer.
  LogTimer.start(500);
}

void MainWindow::on_CmdStopLog_clicked()
{
  logging_on = false;
  LogTimer.stop();
  SignalUpdateTimer.start();
  FrequencyUpdateTimer.start();
}

void MainWindow::UpdateLogTable()
{
  ui->LstLogEntries->clearContents();

  for (int i=ui->LstLogEntries->rowCount(); --i >= 0;)
    ui->LstLogEntries->removeRow(i);

  QFrequencyDatabase::logentries entries = frequencies->GetLogEntries();
  for (QFrequencyDatabase::logentries::iterator it = entries.begin() ; it != entries.end(); ++it)
  {
    QFrequencyDatabase::logentry* curr_entry = (*it);
    int row = ui->LstLogEntries->rowCount();
    ui->LstLogEntries->insertRow(row);
    QTableWidgetItem* time = new QTableWidgetItem(curr_entry->time.c_str());
    time->setData(Qt::UserRole,QString(curr_entry->filename.c_str()));
    ui->LstLogEntries->setItem(row,0,time);
    ui->LstLogEntries->setItem(row,1,new QTableWidgetItem(curr_entry->freq.c_str()));
    ui->LstLogEntries->setItem(row,2,new QTableWidgetItem(Radio.ModeToStr(curr_entry->mode)));
    ui->LstLogEntries->setItem(row,3,new QTableWidgetItem(curr_entry->note.c_str()));
    ui->LstLogEntries->scrollToBottom();
  }
}

void MainWindow::on_LstLogEntries_doubleClicked(const QModelIndex &index)
{
  QList<QTableWidgetItem*> selected_items = ui->LstLogEntries->selectedItems();
  int row=0;

  for (QList<QTableWidgetItem*>::iterator it = selected_items.begin() ; it != selected_items.end() ; ++it)
  {
    QTableWidgetItem* selected_item = (*it);
    row = selected_item->row();
    QString filename = ui->LstLogEntries->item(row,0)->data(Qt::UserRole).toString();
    PlayLogEntry(filename);
    break;
  }
}

void MainWindow::PlayLogEntry(QString filename)
{
  ui->statusBar->showMessage(filename);
  QFile* input = new QFile(filename);
  input->open(QIODevice::ReadOnly|QIODevice::Truncate);
  if (input->isOpen())
  {
    input->setFileName(filename);
    audio_out->start(input);
  }
}

void MainWindow::CleanupProcs()
{
  for( std::vector<QProcess*>::iterator it = processes.begin() ; it != processes.end() ; ++it)
  {
    QProcess* proc = (*it);
    if (proc)
    {
      if ( ! proc->isOpen())
      {
        proc->kill();
        delete proc;
        proc = 0;
      }
    }
  }
}

