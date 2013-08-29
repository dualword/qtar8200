/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Oct 7 01:32:28 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDial>
#include <QtGui/QDockWidget>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qfrequencycategorytree.h"
#include "qsmeter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Connect_to_rig;
    QAction *action_Disconnect_from_rig;
    QAction *actionNew_category;
    QAction *actionRemove_Category;
    QAction *actionRe_name_category;
    QAction *action_Quit;
    QAction *action_Delete;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *TabRadioControl;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *FrequencyEdit;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QRadioButton *CmdFiftyHz;
    QRadioButton *CmdHundredHz;
    QRadioButton *CmdTwoHundredHz;
    QRadioButton *CmdFiveHundredHz;
    QRadioButton *CmdOneKHz;
    QRadioButton *CmdTwoKHz;
    QRadioButton *CmdFiveKHz;
    QRadioButton *CmdSixAndOneQuartKHz;
    QRadioButton *CmdEightPointThirtyThreeKHz;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *CmdNineKHz;
    QRadioButton *CmdTenKHz;
    QRadioButton *CmdTwelvePointFiveKHz;
    QRadioButton *CmdTwentyKHz;
    QRadioButton *CmdTwentyFiveKHz;
    QRadioButton *CmdThirtyKHz;
    QRadioButton *CmdFiftyKHz;
    QRadioButton *CmdHundredKHz;
    QDial *dial;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *CmdSAM;
    QPushButton *CmdAM;
    QPushButton *CmdWAM;
    QPushButton *CmdSFM;
    QPushButton *CmdNFM;
    QPushButton *CmdWFM;
    QPushButton *CmdLSB;
    QPushButton *CmdUSB;
    QPushButton *CmdCW;
    QPushButton *CmdATT;
    QWidget *TabFrequencyDatabase;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *TxtDescription;
    QLabel *label_3;
    QLineEdit *TxtFrequency;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *CmbModes;
    QCheckBox *ChkAttenuator;
    QLabel *label_5;
    QLineEdit *TxtSquelch;
    QPushButton *CmdAddFrequency;
    QPushButton *CmdClearForm;
    QSplitter *splitter;
    QFrequencyCategoryTree *TreeFrequencyCategories;
    QTableWidget *LstFrequencies;
    QCheckBox *ChkTuneOnSelect;
    QWidget *TabVFOScan;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_11;
    QSplitter *splitter_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QLabel *label_6;
    QLineEdit *TxtVfoA;
    QLabel *label_7;
    QLineEdit *TxtVfoB;
    QLabel *label_9;
    QComboBox *CmbVfoScanMode;
    QLabel *label_10;
    QComboBox *CmbVfoScanStep;
    QCheckBox *ChkVfoScanAttenuator;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *CmdBeginVFOScan;
    QPushButton *CmdEndVFOScan;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QLineEdit *lineEdit;
    QPushButton *CmdVfoScanSaveRange;
    QTableWidget *LstFrequencies_2;
    QWidget *TabMemory;
    QTableWidget *LstMemory;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *CmdMemoryDownload;
    QPushButton *CmdMemoryUpload;
    QWidget *TabLog;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *CmdStartLog;
    QPushButton *CmdStopLog;
    QLabel *label_13;
    QLineEdit *TxtLogSquelch;
    QTableWidget *LstLogEntries;
    QMenuBar *menuBar;
    QMenu *menu_QtAR8200;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout_6;
    QSMeter *SMeter;
    QLabel *Frequency;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;
    QHBoxLayout *horizontalLayout_9;
    QGridLayout *gridLayout_3;
    QPushButton *CmdVfoUp;
    QPushButton *CmdVfoLeft;
    QPushButton *CmdVfoRight;
    QPushButton *CmdVfoDown;
    QLabel *label_11;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1106, 751);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        action_Connect_to_rig = new QAction(MainWindow);
        action_Connect_to_rig->setObjectName(QString::fromUtf8("action_Connect_to_rig"));
        action_Disconnect_from_rig = new QAction(MainWindow);
        action_Disconnect_from_rig->setObjectName(QString::fromUtf8("action_Disconnect_from_rig"));
        actionNew_category = new QAction(MainWindow);
        actionNew_category->setObjectName(QString::fromUtf8("actionNew_category"));
        actionRemove_Category = new QAction(MainWindow);
        actionRemove_Category->setObjectName(QString::fromUtf8("actionRemove_Category"));
        actionRe_name_category = new QAction(MainWindow);
        actionRe_name_category->setObjectName(QString::fromUtf8("actionRe_name_category"));
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Delete = new QAction(MainWindow);
        action_Delete->setObjectName(QString::fromUtf8("action_Delete"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setMovable(true);
        TabRadioControl = new QWidget();
        TabRadioControl->setObjectName(QString::fromUtf8("TabRadioControl"));
        gridLayout = new QGridLayout(TabRadioControl);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(TabRadioControl);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        FrequencyEdit = new QLineEdit(TabRadioControl);
        FrequencyEdit->setObjectName(QString::fromUtf8("FrequencyEdit"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(219, 224, 201, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(237, 239, 228, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(109, 112, 100, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(146, 149, 134, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        FrequencyEdit->setPalette(palette);

        horizontalLayout_4->addWidget(FrequencyEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(TabRadioControl);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(170, 0));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 20, 220, 225));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        CmdFiftyHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdFiftyHz->setObjectName(QString::fromUtf8("CmdFiftyHz"));

        verticalLayout->addWidget(CmdFiftyHz);

        CmdHundredHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdHundredHz->setObjectName(QString::fromUtf8("CmdHundredHz"));

        verticalLayout->addWidget(CmdHundredHz);

        CmdTwoHundredHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdTwoHundredHz->setObjectName(QString::fromUtf8("CmdTwoHundredHz"));

        verticalLayout->addWidget(CmdTwoHundredHz);

        CmdFiveHundredHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdFiveHundredHz->setObjectName(QString::fromUtf8("CmdFiveHundredHz"));

        verticalLayout->addWidget(CmdFiveHundredHz);

        CmdOneKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdOneKHz->setObjectName(QString::fromUtf8("CmdOneKHz"));

        verticalLayout->addWidget(CmdOneKHz);

        CmdTwoKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdTwoKHz->setObjectName(QString::fromUtf8("CmdTwoKHz"));

        verticalLayout->addWidget(CmdTwoKHz);

        CmdFiveKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdFiveKHz->setObjectName(QString::fromUtf8("CmdFiveKHz"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CmdFiveKHz->sizePolicy().hasHeightForWidth());
        CmdFiveKHz->setSizePolicy(sizePolicy2);
        CmdFiveKHz->setMaximumSize(QSize(80, 16777215));
        CmdFiveKHz->setChecked(true);

        verticalLayout->addWidget(CmdFiveKHz);

        CmdSixAndOneQuartKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdSixAndOneQuartKHz->setObjectName(QString::fromUtf8("CmdSixAndOneQuartKHz"));

        verticalLayout->addWidget(CmdSixAndOneQuartKHz);

        CmdEightPointThirtyThreeKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdEightPointThirtyThreeKHz->setObjectName(QString::fromUtf8("CmdEightPointThirtyThreeKHz"));

        verticalLayout->addWidget(CmdEightPointThirtyThreeKHz);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        CmdNineKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdNineKHz->setObjectName(QString::fromUtf8("CmdNineKHz"));

        verticalLayout_3->addWidget(CmdNineKHz);

        CmdTenKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdTenKHz->setObjectName(QString::fromUtf8("CmdTenKHz"));
        sizePolicy2.setHeightForWidth(CmdTenKHz->sizePolicy().hasHeightForWidth());
        CmdTenKHz->setSizePolicy(sizePolicy2);
        CmdTenKHz->setMaximumSize(QSize(80, 16777215));

        verticalLayout_3->addWidget(CmdTenKHz);

        CmdTwelvePointFiveKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdTwelvePointFiveKHz->setObjectName(QString::fromUtf8("CmdTwelvePointFiveKHz"));

        verticalLayout_3->addWidget(CmdTwelvePointFiveKHz);

        CmdTwentyKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdTwentyKHz->setObjectName(QString::fromUtf8("CmdTwentyKHz"));
        sizePolicy2.setHeightForWidth(CmdTwentyKHz->sizePolicy().hasHeightForWidth());
        CmdTwentyKHz->setSizePolicy(sizePolicy2);
        CmdTwentyKHz->setMaximumSize(QSize(80, 16777215));

        verticalLayout_3->addWidget(CmdTwentyKHz);

        CmdTwentyFiveKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdTwentyFiveKHz->setObjectName(QString::fromUtf8("CmdTwentyFiveKHz"));
        sizePolicy2.setHeightForWidth(CmdTwentyFiveKHz->sizePolicy().hasHeightForWidth());
        CmdTwentyFiveKHz->setSizePolicy(sizePolicy2);
        CmdTwentyFiveKHz->setMaximumSize(QSize(80, 16777215));

        verticalLayout_3->addWidget(CmdTwentyFiveKHz);

        CmdThirtyKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdThirtyKHz->setObjectName(QString::fromUtf8("CmdThirtyKHz"));
        sizePolicy2.setHeightForWidth(CmdThirtyKHz->sizePolicy().hasHeightForWidth());
        CmdThirtyKHz->setSizePolicy(sizePolicy2);
        CmdThirtyKHz->setMaximumSize(QSize(80, 16777215));

        verticalLayout_3->addWidget(CmdThirtyKHz);

        CmdFiftyKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdFiftyKHz->setObjectName(QString::fromUtf8("CmdFiftyKHz"));
        sizePolicy2.setHeightForWidth(CmdFiftyKHz->sizePolicy().hasHeightForWidth());
        CmdFiftyKHz->setSizePolicy(sizePolicy2);
        CmdFiftyKHz->setMaximumSize(QSize(80, 16777215));

        verticalLayout_3->addWidget(CmdFiftyKHz);

        CmdHundredKHz = new QRadioButton(horizontalLayoutWidget_2);
        CmdHundredKHz->setObjectName(QString::fromUtf8("CmdHundredKHz"));
        sizePolicy2.setHeightForWidth(CmdHundredKHz->sizePolicy().hasHeightForWidth());
        CmdHundredKHz->setSizePolicy(sizePolicy2);
        CmdHundredKHz->setMaximumSize(QSize(80, 16777215));

        verticalLayout_3->addWidget(CmdHundredKHz);


        horizontalLayout_5->addLayout(verticalLayout_3);


        horizontalLayout_3->addWidget(groupBox);

        dial = new QDial(TabRadioControl);
        dial->setObjectName(QString::fromUtf8("dial"));
        sizePolicy.setHeightForWidth(dial->sizePolicy().hasHeightForWidth());
        dial->setSizePolicy(sizePolicy);
        dial->setMinimum(-50000000);
        dial->setMaximum(50000000);
        dial->setValue(1);
        dial->setTracking(true);
        dial->setOrientation(Qt::Horizontal);
        dial->setInvertedAppearance(false);
        dial->setWrapping(true);
        dial->setNotchesVisible(false);

        horizontalLayout_3->addWidget(dial);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        CmdSAM = new QPushButton(TabRadioControl);
        CmdSAM->setObjectName(QString::fromUtf8("CmdSAM"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(CmdSAM->sizePolicy().hasHeightForWidth());
        CmdSAM->setSizePolicy(sizePolicy3);
        CmdSAM->setMinimumSize(QSize(30, 25));
        CmdSAM->setMaximumSize(QSize(16777215, 25));
        CmdSAM->setAutoFillBackground(false);
        CmdSAM->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #595\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #5f5\n"
"}"));
        CmdSAM->setCheckable(true);
        CmdSAM->setChecked(false);
        CmdSAM->setFlat(true);

        horizontalLayout_2->addWidget(CmdSAM);

        CmdAM = new QPushButton(TabRadioControl);
        CmdAM->setObjectName(QString::fromUtf8("CmdAM"));
        sizePolicy3.setHeightForWidth(CmdAM->sizePolicy().hasHeightForWidth());
        CmdAM->setSizePolicy(sizePolicy3);
        CmdAM->setMinimumSize(QSize(30, 25));
        CmdAM->setMaximumSize(QSize(16777215, 25));
        CmdAM->setAutoFillBackground(false);
        CmdAM->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #595\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #5f5\n"
"}"));
        CmdAM->setCheckable(true);
        CmdAM->setFlat(true);

        horizontalLayout_2->addWidget(CmdAM);

        CmdWAM = new QPushButton(TabRadioControl);
        CmdWAM->setObjectName(QString::fromUtf8("CmdWAM"));
        sizePolicy3.setHeightForWidth(CmdWAM->sizePolicy().hasHeightForWidth());
        CmdWAM->setSizePolicy(sizePolicy3);
        CmdWAM->setMinimumSize(QSize(30, 25));
        CmdWAM->setMaximumSize(QSize(16777215, 25));
        CmdWAM->setAutoFillBackground(false);
        CmdWAM->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #595\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #5f5\n"
"}"));
        CmdWAM->setCheckable(true);
        CmdWAM->setFlat(true);

        horizontalLayout_2->addWidget(CmdWAM);

        CmdSFM = new QPushButton(TabRadioControl);
        CmdSFM->setObjectName(QString::fromUtf8("CmdSFM"));
        sizePolicy3.setHeightForWidth(CmdSFM->sizePolicy().hasHeightForWidth());
        CmdSFM->setSizePolicy(sizePolicy3);
        CmdSFM->setMinimumSize(QSize(30, 25));
        CmdSFM->setMaximumSize(QSize(16777215, 25));
        CmdSFM->setAutoFillBackground(false);
        CmdSFM->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #595\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #5f5\n"
"}"));
        CmdSFM->setCheckable(true);
        CmdSFM->setFlat(true);

        horizontalLayout_2->addWidget(CmdSFM);

        CmdNFM = new QPushButton(TabRadioControl);
        CmdNFM->setObjectName(QString::fromUtf8("CmdNFM"));
        sizePolicy3.setHeightForWidth(CmdNFM->sizePolicy().hasHeightForWidth());
        CmdNFM->setSizePolicy(sizePolicy3);
        CmdNFM->setMinimumSize(QSize(30, 25));
        CmdNFM->setMaximumSize(QSize(16777215, 25));
        CmdNFM->setAutoFillBackground(false);
        CmdNFM->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #595\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #5f5\n"
"}"));
        CmdNFM->setCheckable(true);
        CmdNFM->setFlat(true);

        horizontalLayout_2->addWidget(CmdNFM);

        CmdWFM = new QPushButton(TabRadioControl);
        CmdWFM->setObjectName(QString::fromUtf8("CmdWFM"));
        sizePolicy3.setHeightForWidth(CmdWFM->sizePolicy().hasHeightForWidth());
        CmdWFM->setSizePolicy(sizePolicy3);
        CmdWFM->setMinimumSize(QSize(30, 25));
        CmdWFM->setMaximumSize(QSize(16777215, 25));
        CmdWFM->setAutoFillBackground(false);
        CmdWFM->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #595\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #5f5\n"
"}"));
        CmdWFM->setCheckable(true);
        CmdWFM->setFlat(true);

        horizontalLayout_2->addWidget(CmdWFM);

        CmdLSB = new QPushButton(TabRadioControl);
        CmdLSB->setObjectName(QString::fromUtf8("CmdLSB"));
        sizePolicy3.setHeightForWidth(CmdLSB->sizePolicy().hasHeightForWidth());
        CmdLSB->setSizePolicy(sizePolicy3);
        CmdLSB->setMinimumSize(QSize(30, 25));
        CmdLSB->setMaximumSize(QSize(16777215, 25));
        CmdLSB->setAutoFillBackground(false);
        CmdLSB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #595\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #5f5\n"
"}"));
        CmdLSB->setCheckable(true);
        CmdLSB->setFlat(true);

        horizontalLayout_2->addWidget(CmdLSB);

        CmdUSB = new QPushButton(TabRadioControl);
        CmdUSB->setObjectName(QString::fromUtf8("CmdUSB"));
        sizePolicy3.setHeightForWidth(CmdUSB->sizePolicy().hasHeightForWidth());
        CmdUSB->setSizePolicy(sizePolicy3);
        CmdUSB->setMinimumSize(QSize(30, 25));
        CmdUSB->setMaximumSize(QSize(16777215, 25));
        CmdUSB->setAutoFillBackground(false);
        CmdUSB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #595\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #5f5\n"
"}"));
        CmdUSB->setCheckable(true);
        CmdUSB->setFlat(true);

        horizontalLayout_2->addWidget(CmdUSB);

        CmdCW = new QPushButton(TabRadioControl);
        CmdCW->setObjectName(QString::fromUtf8("CmdCW"));
        sizePolicy3.setHeightForWidth(CmdCW->sizePolicy().hasHeightForWidth());
        CmdCW->setSizePolicy(sizePolicy3);
        CmdCW->setMinimumSize(QSize(30, 25));
        CmdCW->setMaximumSize(QSize(16777215, 25));
        CmdCW->setAutoFillBackground(false);
        CmdCW->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #595\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #5f5\n"
"}"));
        CmdCW->setCheckable(true);
        CmdCW->setFlat(true);

        horizontalLayout_2->addWidget(CmdCW);

        CmdATT = new QPushButton(TabRadioControl);
        CmdATT->setObjectName(QString::fromUtf8("CmdATT"));
        CmdATT->setMaximumSize(QSize(16777215, 25));
        CmdATT->setAutoFillBackground(false);
        CmdATT->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #595\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"  border: 2px solid #555;\n"
"  border-radius: 2px;\n"
"  background-color: #5f5\n"
"}"));
        CmdATT->setCheckable(true);
        CmdATT->setFlat(true);

        horizontalLayout_2->addWidget(CmdATT);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(TabRadioControl, QString());
        TabFrequencyDatabase = new QWidget();
        TabFrequencyDatabase->setObjectName(QString::fromUtf8("TabFrequencyDatabase"));
        verticalLayout_4 = new QVBoxLayout(TabFrequencyDatabase);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        splitter_2 = new QSplitter(TabFrequencyDatabase);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        TxtDescription = new QLineEdit(layoutWidget);
        TxtDescription->setObjectName(QString::fromUtf8("TxtDescription"));

        formLayout->setWidget(0, QFormLayout::FieldRole, TxtDescription);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        TxtFrequency = new QLineEdit(layoutWidget);
        TxtFrequency->setObjectName(QString::fromUtf8("TxtFrequency"));

        formLayout->setWidget(1, QFormLayout::FieldRole, TxtFrequency);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        CmbModes = new QComboBox(layoutWidget);
        CmbModes->setObjectName(QString::fromUtf8("CmbModes"));

        horizontalLayout_7->addWidget(CmbModes);

        ChkAttenuator = new QCheckBox(layoutWidget);
        ChkAttenuator->setObjectName(QString::fromUtf8("ChkAttenuator"));

        horizontalLayout_7->addWidget(ChkAttenuator);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_7);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        TxtSquelch = new QLineEdit(layoutWidget);
        TxtSquelch->setObjectName(QString::fromUtf8("TxtSquelch"));

        formLayout->setWidget(3, QFormLayout::FieldRole, TxtSquelch);

        CmdAddFrequency = new QPushButton(layoutWidget);
        CmdAddFrequency->setObjectName(QString::fromUtf8("CmdAddFrequency"));

        formLayout->setWidget(4, QFormLayout::LabelRole, CmdAddFrequency);

        CmdClearForm = new QPushButton(layoutWidget);
        CmdClearForm->setObjectName(QString::fromUtf8("CmdClearForm"));

        formLayout->setWidget(4, QFormLayout::FieldRole, CmdClearForm);

        splitter_2->addWidget(layoutWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        TreeFrequencyCategories = new QFrequencyCategoryTree(splitter);
        TreeFrequencyCategories->setObjectName(QString::fromUtf8("TreeFrequencyCategories"));
        TreeFrequencyCategories->setContextMenuPolicy(Qt::CustomContextMenu);
        TreeFrequencyCategories->setSelectionMode(QAbstractItemView::SingleSelection);
        TreeFrequencyCategories->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter->addWidget(TreeFrequencyCategories);
        LstFrequencies = new QTableWidget(splitter);
        if (LstFrequencies->columnCount() < 6)
            LstFrequencies->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        LstFrequencies->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        LstFrequencies->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        LstFrequencies->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        LstFrequencies->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        LstFrequencies->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        LstFrequencies->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        LstFrequencies->setObjectName(QString::fromUtf8("LstFrequencies"));
        splitter->addWidget(LstFrequencies);
        splitter_2->addWidget(splitter);
        ChkTuneOnSelect = new QCheckBox(splitter_2);
        ChkTuneOnSelect->setObjectName(QString::fromUtf8("ChkTuneOnSelect"));
        splitter_2->addWidget(ChkTuneOnSelect);

        verticalLayout_4->addWidget(splitter_2);

        tabWidget->addTab(TabFrequencyDatabase, QString());
        TabVFOScan = new QWidget();
        TabVFOScan->setObjectName(QString::fromUtf8("TabVFOScan"));
        verticalLayout_7 = new QVBoxLayout(TabVFOScan);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        widget = new QWidget(TabVFOScan);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_11 = new QHBoxLayout(widget);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        splitter_3 = new QSplitter(widget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter_3);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_8);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        TxtVfoA = new QLineEdit(verticalLayoutWidget);
        TxtVfoA->setObjectName(QString::fromUtf8("TxtVfoA"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, TxtVfoA);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_7);

        TxtVfoB = new QLineEdit(verticalLayoutWidget);
        TxtVfoB->setObjectName(QString::fromUtf8("TxtVfoB"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, TxtVfoB);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_9);

        CmbVfoScanMode = new QComboBox(verticalLayoutWidget);
        CmbVfoScanMode->setObjectName(QString::fromUtf8("CmbVfoScanMode"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, CmbVfoScanMode);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_10);

        CmbVfoScanStep = new QComboBox(verticalLayoutWidget);
        CmbVfoScanStep->setObjectName(QString::fromUtf8("CmbVfoScanStep"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, CmbVfoScanStep);

        ChkVfoScanAttenuator = new QCheckBox(verticalLayoutWidget);
        ChkVfoScanAttenuator->setObjectName(QString::fromUtf8("ChkVfoScanAttenuator"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, ChkVfoScanAttenuator);


        verticalLayout_5->addLayout(formLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        CmdBeginVFOScan = new QPushButton(verticalLayoutWidget);
        CmdBeginVFOScan->setObjectName(QString::fromUtf8("CmdBeginVFOScan"));

        horizontalLayout_8->addWidget(CmdBeginVFOScan);

        CmdEndVFOScan = new QPushButton(verticalLayoutWidget);
        CmdEndVFOScan->setObjectName(QString::fromUtf8("CmdEndVFOScan"));

        horizontalLayout_8->addWidget(CmdEndVFOScan);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy4);

        horizontalLayout_10->addWidget(label_12);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_10->addWidget(lineEdit);


        verticalLayout_5->addLayout(horizontalLayout_10);

        CmdVfoScanSaveRange = new QPushButton(verticalLayoutWidget);
        CmdVfoScanSaveRange->setObjectName(QString::fromUtf8("CmdVfoScanSaveRange"));

        verticalLayout_5->addWidget(CmdVfoScanSaveRange);

        splitter_3->addWidget(verticalLayoutWidget);
        LstFrequencies_2 = new QTableWidget(splitter_3);
        if (LstFrequencies_2->columnCount() < 7)
            LstFrequencies_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        LstFrequencies_2->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        LstFrequencies_2->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        LstFrequencies_2->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        LstFrequencies_2->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        LstFrequencies_2->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        LstFrequencies_2->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        LstFrequencies_2->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        LstFrequencies_2->setObjectName(QString::fromUtf8("LstFrequencies_2"));
        LstFrequencies_2->setMinimumSize(QSize(0, 0));
        splitter_3->addWidget(LstFrequencies_2);

        horizontalLayout_11->addWidget(splitter_3);


        verticalLayout_7->addWidget(widget);

        tabWidget->addTab(TabVFOScan, QString());
        TabMemory = new QWidget();
        TabMemory->setObjectName(QString::fromUtf8("TabMemory"));
        LstMemory = new QTableWidget(TabMemory);
        if (LstMemory->columnCount() < 5)
            LstMemory->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        LstMemory->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        LstMemory->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        LstMemory->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        LstMemory->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        LstMemory->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        LstMemory->setObjectName(QString::fromUtf8("LstMemory"));
        LstMemory->setGeometry(QRect(30, 50, 911, 491));
        LstMemory->setMinimumSize(QSize(0, 0));
        horizontalLayoutWidget = new QWidget(TabMemory);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 10, 881, 32));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        CmdMemoryDownload = new QPushButton(horizontalLayoutWidget);
        CmdMemoryDownload->setObjectName(QString::fromUtf8("CmdMemoryDownload"));

        horizontalLayout_12->addWidget(CmdMemoryDownload);

        CmdMemoryUpload = new QPushButton(horizontalLayoutWidget);
        CmdMemoryUpload->setObjectName(QString::fromUtf8("CmdMemoryUpload"));

        horizontalLayout_12->addWidget(CmdMemoryUpload);

        tabWidget->addTab(TabMemory, QString());
        TabLog = new QWidget();
        TabLog->setObjectName(QString::fromUtf8("TabLog"));
        verticalLayout_9 = new QVBoxLayout(TabLog);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        CmdStartLog = new QPushButton(TabLog);
        CmdStartLog->setObjectName(QString::fromUtf8("CmdStartLog"));

        horizontalLayout_13->addWidget(CmdStartLog);

        CmdStopLog = new QPushButton(TabLog);
        CmdStopLog->setObjectName(QString::fromUtf8("CmdStopLog"));

        horizontalLayout_13->addWidget(CmdStopLog);

        label_13 = new QLabel(TabLog);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy5);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(label_13);

        TxtLogSquelch = new QLineEdit(TabLog);
        TxtLogSquelch->setObjectName(QString::fromUtf8("TxtLogSquelch"));
        TxtLogSquelch->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_13->addWidget(TxtLogSquelch);


        verticalLayout_8->addLayout(horizontalLayout_13);

        LstLogEntries = new QTableWidget(TabLog);
        if (LstLogEntries->columnCount() < 4)
            LstLogEntries->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        LstLogEntries->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        LstLogEntries->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        LstLogEntries->setHorizontalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        LstLogEntries->setHorizontalHeaderItem(3, __qtablewidgetitem21);
        LstLogEntries->setObjectName(QString::fromUtf8("LstLogEntries"));
        LstLogEntries->setMinimumSize(QSize(0, 0));

        verticalLayout_8->addWidget(LstLogEntries);


        verticalLayout_9->addLayout(verticalLayout_8);

        tabWidget->addTab(TabLog, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1106, 27));
        menu_QtAR8200 = new QMenu(menuBar);
        menu_QtAR8200->setObjectName(QString::fromUtf8("menu_QtAR8200"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        horizontalLayout_6 = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        SMeter = new QSMeter(dockWidgetContents_2);
        SMeter->setObjectName(QString::fromUtf8("SMeter"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(SMeter->sizePolicy().hasHeightForWidth());
        SMeter->setSizePolicy(sizePolicy6);
        SMeter->setMinimumSize(QSize(160, 80));
        SMeter->setMaximumSize(QSize(160, 80));
        SMeter->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        SMeter->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_6->addWidget(SMeter);

        Frequency = new QLabel(dockWidgetContents_2);
        Frequency->setObjectName(QString::fromUtf8("Frequency"));
        Frequency->setMinimumSize(QSize(0, 80));
        Frequency->setMaximumSize(QSize(16777215, 80));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush7(QColor(115, 145, 117, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush7);
        QBrush brush8(QColor(3, 42, 3, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush8);
        QBrush brush9(QColor(2, 35, 2, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        QBrush brush10(QColor(1, 14, 1, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(1, 18, 1, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush12(QColor(116, 139, 116, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush13(QColor(2, 28, 2, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Frequency->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Terminus"));
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        Frequency->setFont(font);
        Frequency->setAutoFillBackground(true);
        Frequency->setFrameShape(QFrame::Panel);
        Frequency->setFrameShadow(QFrame::Sunken);
        Frequency->setLineWidth(2);
        Frequency->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(Frequency);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dockWidget_2);
        dockWidget_3 = new QDockWidget(MainWindow);
        dockWidget_3->setObjectName(QString::fromUtf8("dockWidget_3"));
        dockWidget_3->setMaximumSize(QSize(150, 150));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        horizontalLayout_9 = new QHBoxLayout(dockWidgetContents_3);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        CmdVfoUp = new QPushButton(dockWidgetContents_3);
        CmdVfoUp->setObjectName(QString::fromUtf8("CmdVfoUp"));

        gridLayout_3->addWidget(CmdVfoUp, 0, 1, 1, 1);

        CmdVfoLeft = new QPushButton(dockWidgetContents_3);
        CmdVfoLeft->setObjectName(QString::fromUtf8("CmdVfoLeft"));

        gridLayout_3->addWidget(CmdVfoLeft, 1, 0, 1, 1);

        CmdVfoRight = new QPushButton(dockWidgetContents_3);
        CmdVfoRight->setObjectName(QString::fromUtf8("CmdVfoRight"));

        gridLayout_3->addWidget(CmdVfoRight, 1, 2, 1, 1);

        CmdVfoDown = new QPushButton(dockWidgetContents_3);
        CmdVfoDown->setObjectName(QString::fromUtf8("CmdVfoDown"));

        gridLayout_3->addWidget(CmdVfoDown, 2, 1, 1, 1);

        label_11 = new QLabel(dockWidgetContents_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy7);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_11, 1, 1, 1, 1);


        horizontalLayout_9->addLayout(gridLayout_3);

        dockWidget_3->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_3);

        menuBar->addAction(menu_QtAR8200->menuAction());
        menu_QtAR8200->addAction(action_Connect_to_rig);
        menu_QtAR8200->addAction(action_Disconnect_from_rig);
        menu_QtAR8200->addSeparator();
        menu_QtAR8200->addAction(action_Quit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_Connect_to_rig->setText(QApplication::translate("MainWindow", "&Connect to rig", 0, QApplication::UnicodeUTF8));
        action_Disconnect_from_rig->setText(QApplication::translate("MainWindow", "&Disconnect from rig", 0, QApplication::UnicodeUTF8));
        actionNew_category->setText(QApplication::translate("MainWindow", "&New category", 0, QApplication::UnicodeUTF8));
        actionRemove_Category->setText(QApplication::translate("MainWindow", "&Remove category", 0, QApplication::UnicodeUTF8));
        actionRe_name_category->setText(QApplication::translate("MainWindow", "Re&name category", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Delete->setText(QApplication::translate("MainWindow", "&Delete", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Set frequency:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Tuning step:", 0, QApplication::UnicodeUTF8));
        CmdFiftyHz->setText(QApplication::translate("MainWindow", "50 Hz", 0, QApplication::UnicodeUTF8));
        CmdHundredHz->setText(QApplication::translate("MainWindow", "100 Hz", 0, QApplication::UnicodeUTF8));
        CmdTwoHundredHz->setText(QApplication::translate("MainWindow", "200 Hz", 0, QApplication::UnicodeUTF8));
        CmdFiveHundredHz->setText(QApplication::translate("MainWindow", "500 Hz", 0, QApplication::UnicodeUTF8));
        CmdOneKHz->setText(QApplication::translate("MainWindow", "1 kHz", 0, QApplication::UnicodeUTF8));
        CmdTwoKHz->setText(QApplication::translate("MainWindow", "2 kHz", 0, QApplication::UnicodeUTF8));
        CmdFiveKHz->setText(QApplication::translate("MainWindow", "5 kHz", 0, QApplication::UnicodeUTF8));
        CmdSixAndOneQuartKHz->setText(QApplication::translate("MainWindow", "6.25 kHz", 0, QApplication::UnicodeUTF8));
        CmdEightPointThirtyThreeKHz->setText(QApplication::translate("MainWindow", "8.33 kHz", 0, QApplication::UnicodeUTF8));
        CmdNineKHz->setText(QApplication::translate("MainWindow", "9 kHz", 0, QApplication::UnicodeUTF8));
        CmdTenKHz->setText(QApplication::translate("MainWindow", "10 kHz", 0, QApplication::UnicodeUTF8));
        CmdTwelvePointFiveKHz->setText(QApplication::translate("MainWindow", "12.5 kHz", 0, QApplication::UnicodeUTF8));
        CmdTwentyKHz->setText(QApplication::translate("MainWindow", "20 kHz", 0, QApplication::UnicodeUTF8));
        CmdTwentyFiveKHz->setText(QApplication::translate("MainWindow", "25 kHz", 0, QApplication::UnicodeUTF8));
        CmdThirtyKHz->setText(QApplication::translate("MainWindow", "30 kHz", 0, QApplication::UnicodeUTF8));
        CmdFiftyKHz->setText(QApplication::translate("MainWindow", "50 kHz", 0, QApplication::UnicodeUTF8));
        CmdHundredKHz->setText(QApplication::translate("MainWindow", "100 kHz", 0, QApplication::UnicodeUTF8));
        CmdSAM->setText(QApplication::translate("MainWindow", "SAM", 0, QApplication::UnicodeUTF8));
        CmdAM->setText(QApplication::translate("MainWindow", "AM", 0, QApplication::UnicodeUTF8));
        CmdWAM->setText(QApplication::translate("MainWindow", "WAM", 0, QApplication::UnicodeUTF8));
        CmdSFM->setText(QApplication::translate("MainWindow", "SFM", 0, QApplication::UnicodeUTF8));
        CmdNFM->setText(QApplication::translate("MainWindow", "NFM", 0, QApplication::UnicodeUTF8));
        CmdWFM->setText(QApplication::translate("MainWindow", "WFM", 0, QApplication::UnicodeUTF8));
        CmdLSB->setText(QApplication::translate("MainWindow", "LSB", 0, QApplication::UnicodeUTF8));
        CmdUSB->setText(QApplication::translate("MainWindow", "USB", 0, QApplication::UnicodeUTF8));
        CmdCW->setText(QApplication::translate("MainWindow", "CW/DATA", 0, QApplication::UnicodeUTF8));
        CmdATT->setText(QApplication::translate("MainWindow", "ATT", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(TabRadioControl), QApplication::translate("MainWindow", "Radio Control", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Description:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Frequency:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Mode:", 0, QApplication::UnicodeUTF8));
        ChkAttenuator->setText(QApplication::translate("MainWindow", "Attenuator", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Scanning Squelch (dB)", 0, QApplication::UnicodeUTF8));
        CmdAddFrequency->setText(QApplication::translate("MainWindow", "Add frequency", 0, QApplication::UnicodeUTF8));
        CmdClearForm->setText(QApplication::translate("MainWindow", "Clear form", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = TreeFrequencyCategories->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Category", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = LstFrequencies->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Description", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = LstFrequencies->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Frequency", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = LstFrequencies->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = LstFrequencies->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "ATT", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = LstFrequencies->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Squelch", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = LstFrequencies->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        ChkTuneOnSelect->setText(QApplication::translate("MainWindow", "Tune selected frequencies", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(TabFrequencyDatabase), QApplication::translate("MainWindow", "Frequency Database", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "VFO frequencies in MHz : ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "VFO 1:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "VFO 2:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Mode:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Step:", 0, QApplication::UnicodeUTF8));
        ChkVfoScanAttenuator->setText(QApplication::translate("MainWindow", "Attenuator", 0, QApplication::UnicodeUTF8));
        CmdBeginVFOScan->setText(QApplication::translate("MainWindow", "Begin scan", 0, QApplication::UnicodeUTF8));
        CmdEndVFOScan->setText(QApplication::translate("MainWindow", "Stop scan", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Description:", 0, QApplication::UnicodeUTF8));
        CmdVfoScanSaveRange->setText(QApplication::translate("MainWindow", "Save range ->", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = LstFrequencies_2->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Description", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = LstFrequencies_2->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Start Freq.", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = LstFrequencies_2->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "End Freq.", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = LstFrequencies_2->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Step", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = LstFrequencies_2->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = LstFrequencies_2->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "ATT", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = LstFrequencies_2->horizontalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(TabVFOScan), QApplication::translate("MainWindow", "VFO Scan", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = LstMemory->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Bank", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = LstMemory->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Description", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = LstMemory->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Frequency", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = LstMemory->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Attenuator", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = LstMemory->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Tuning step", 0, QApplication::UnicodeUTF8));
        CmdMemoryDownload->setText(QApplication::translate("MainWindow", "Download", 0, QApplication::UnicodeUTF8));
        CmdMemoryUpload->setText(QApplication::translate("MainWindow", "Upload", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(TabMemory), QApplication::translate("MainWindow", "Memory", 0, QApplication::UnicodeUTF8));
        CmdStartLog->setText(QApplication::translate("MainWindow", "Start Logging", 0, QApplication::UnicodeUTF8));
        CmdStopLog->setText(QApplication::translate("MainWindow", "Stop Logging", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Signal level threshold: ", 0, QApplication::UnicodeUTF8));
        TxtLogSquelch->setText(QApplication::translate("MainWindow", "30", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = LstLogEntries->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Date/Time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = LstLogEntries->horizontalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Frequency", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = LstLogEntries->horizontalHeaderItem(2);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = LstLogEntries->horizontalHeaderItem(3);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(TabLog), QApplication::translate("MainWindow", "Log/Record", 0, QApplication::UnicodeUTF8));
        menu_QtAR8200->setTitle(QApplication::translate("MainWindow", "&QtAR8200", 0, QApplication::UnicodeUTF8));
        Frequency->setText(QApplication::translate("MainWindow", "0000.000 MHz", 0, QApplication::UnicodeUTF8));
        CmdVfoUp->setText(QApplication::translate("MainWindow", "^", 0, QApplication::UnicodeUTF8));
        CmdVfoLeft->setText(QApplication::translate("MainWindow", "<-", 0, QApplication::UnicodeUTF8));
        CmdVfoRight->setText(QApplication::translate("MainWindow", "->", 0, QApplication::UnicodeUTF8));
        CmdVfoDown->setText(QApplication::translate("MainWindow", "v", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Arrow\n"
"keys", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
