#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QAudioInput>
#include <QAudioOutput>
#include <QFile>
#include <QProcess>
#include "qfrequencycategorytree.h"
#include "qrig.h"
#include "qfrequencydatabase.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{

  Q_OBJECT

  public:
    QFile* output;
    /// Constructor
    explicit MainWindow(QWidget *parent = 0);

    /// Destructor
    ~MainWindow();    

    /// Sets mode combo mode to given qrig mode value.
    /// \param mode Mode to set.
    void SetModeComboMode(QRig::MODE mode);
    
    /// Fill frequency category treeview.
    void FillFrequencyCategoryTreeView(QTreeWidgetItem* parent=0);

    /// Adds a frequency to the frequency list (second tab)
    void add_frequency_to_list(QFrequencyDatabase::frequency* current_freq);

    /// Play audio file with given filename.
    void PlayLogEntry(QString filename);

  private slots:

    /// Clean up processes.
    void CleanupProcs();
    /// User clicked qtar8200->connect
    void on_action_Connect_to_rig_triggered();
    /// SignalUpdateTimer triggered.
    /// Get signal from radio and make signal needle move.
    void UpdateSignal();
    /// Log handling timer.
    void UpdateLog();
    /// FrequencyUpdateTimer triggered.
    /// Get frequency from radio and update frequency label in gui.
    void UpdateFrequency();
    /// Update log table
    void UpdateLogTable();

    void on_action_Quit_triggered();

    void on_dial_valueChanged(int value);

    void on_CmdFiveKHz_toggled(bool checked);

    void on_CmdTenKHz_toggled(bool checked);

    void on_CmdTwentyKHz_toggled(bool checked);

    void on_CmdTwentyFiveKHz_toggled(bool checked);

    void on_CmdThirtyKHz_toggled(bool checked);

    void on_CmdFiftyKHz_toggled(bool checked);

    void on_CmdHundredKHz_toggled(bool checked);

    void on_FrequencyEdit_returnPressed();

    void on_CmdAM_toggled(bool checked);

    void on_CmdSAM_toggled(bool checked);

    void on_CmdWAM_toggled(bool checked);

    void on_CmdSFM_toggled(bool checked);

    void on_CmdNFM_toggled(bool checked);

    void on_CmdWFM_toggled(bool checked);

    void on_CmdLSB_toggled(bool checked);

    void on_CmdUSB_toggled(bool checked);

    void on_CmdCW_toggled(bool checked);

    void on_action_Disconnect_from_rig_triggered();


    void on_CmdTwelvePointFiveKHz_toggled(bool checked);

    void on_CmdNineKHz_toggled(bool checked);

    void on_CmdEightPointThirtyThreeKHz_toggled(bool checked);

    void on_CmdSixAndOneQuartKHz_toggled(bool checked);

    void on_CmdTwoKHz_toggled(bool checked);

    void on_CmdOneKHz_toggled(bool checked);

    void on_CmdFiveHundredHz_toggled(bool checked);

    void on_CmdTwoHundredHz_toggled(bool checked);

    void on_CmdHundredHz_toggled(bool checked);

    void on_CmdFiftyHz_toggled(bool checked);

    void on_CmdATT_toggled(bool checked);

    void on_tabWidget_currentChanged(int index);

    void on_TreeFrequencyCategories_clicked(const QModelIndex &index);

    void on_TreeFrequencyCategories_customContextMenuRequested(const QPoint &pos);

    void on_actionNew_category_triggered();

    void on_CmdAddFrequency_clicked();

    void on_LstFrequencies_customContextMenuRequested(const QPoint &pos);

    void on_LstFrequencies_itemChanged(QTableWidgetItem *item);

    void on_LstFrequencies_clicked(const QModelIndex &index);

    void on_CmdBeginVFOScan_clicked();

    void on_CmdEndVFOScan_clicked();

    void on_CmdVfoRight_clicked();

    void on_CmdVfoLeft_clicked();

    void on_CmdVfoUp_clicked();

    void on_CmdVfoDown_clicked();

    void on_CmdMemoryDownload_clicked();

    void on_LstFrequencies_3_doubleClicked(const QModelIndex &index);

    void on_CmdStartLog_clicked();

    void on_CmdStopLog_clicked();

    void on_LstLogEntries_doubleClicked(const QModelIndex &index);

private:

    /// Popup menu for frequency category list.
    QMenu* frequency_category_menu;
    /// Popup menu for frequency list.
    QMenu* frequency_list_menu;
    /// Pointer to the main window user interface class.
    Ui::MainWindow *ui;
    /// Frequency category data
    QFrequencyDatabase::categories CategoryData;
    /// Pointer to our radio object.
    QRig Radio;
    /// Pointer to our frequency database model.
    QFrequencyDatabase* frequencies;
    /// Database connection object.
    QSqlDatabase db;
    /// Timer to fetch the signal level from the radio at regular intervals.
    QTimer SignalUpdateTimer;
    /// Timer to fetch the current frequency from the radio at regular intervals.
    QTimer FrequencyUpdateTimer;
    /// Timer for logging
    QTimer LogTimer;
    /// Previous dial position to detect up or down tuning.
    int PreviousDialPosition;
    /// Current active frequency.
    freq_t CurrentFrequency;
    /// Current signal.
    float CurrentSignal;
    /// These are for calculating log average signal.
    int LogSignalCounter;
    float LogSignalTotal;
    /// Tuning step increment.
    int TuneStep;
    /// Ignore changes to frequency list? (eg: during adding of rows)
    bool ignore_frequency_list_changes;
    /// Is logging on?
    bool logging_on;
    /// Is a frequency currently being recorded/logged ?
    bool recording;
    /// Used for recording audio.
    QAudioInput* audio_in;
    /// Used for playing back audio.
    QAudioOutput* audio_out;
    /// Process management
    std::vector<QProcess*> processes;

};

#endif // MAINWINDOW_H
