/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnNewSession;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    QPushButton *btnScanPulseA;
    QSpinBox *intMaxPulseC;
    QLabel *label_3;
    QSpinBox *intDeadTimeAC;
    QLabel *label_14;
    QSpinBox *intMinPulseA;
    QSpinBox *intMaxPulseA;
    QLabel *label_15;
    QPushButton *btnGraphVIT;
    QPushButton *btnGraphVI;
    QLabel *label_7;
    QSpinBox *intMaxVoltage;
    QSpinBox *intMinVoltage;
    QDoubleSpinBox *dblVoltSec;
    QPushButton *btnScanV;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_6;
    QDoubleSpinBox *dblVoltSec_2;
    QSpinBox *intMinCurrent;
    QLabel *label_5;
    QPushButton *btnScanI;
    QLabel *label_9;
    QSpinBox *intMaxCurrent;
    QLabel *label_8;
    QSpinBox *intMilligrams;
    QPushButton *btnRun;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnNewSession = new QPushButton(centralWidget);
        btnNewSession->setObjectName(QStringLiteral("btnNewSession"));
        btnNewSession->setGeometry(QRect(950, 70, 71, 71));
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(700, 150, 301, 191));
        gridLayout_2 = new QGridLayout(layoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        QFont font;
        font.setPointSize(12);
        label_10->setFont(font);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        btnScanPulseA = new QPushButton(layoutWidget_2);
        btnScanPulseA->setObjectName(QStringLiteral("btnScanPulseA"));
        btnScanPulseA->setFont(font);

        gridLayout_2->addWidget(btnScanPulseA, 6, 0, 1, 2);

        intMaxPulseC = new QSpinBox(layoutWidget_2);
        intMaxPulseC->setObjectName(QStringLiteral("intMaxPulseC"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(intMaxPulseC->sizePolicy().hasHeightForWidth());
        intMaxPulseC->setSizePolicy(sizePolicy);
        intMaxPulseC->setMaximum(4000);

        gridLayout_2->addWidget(intMaxPulseC, 5, 1, 1, 1);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        intDeadTimeAC = new QSpinBox(layoutWidget_2);
        intDeadTimeAC->setObjectName(QStringLiteral("intDeadTimeAC"));
        sizePolicy.setHeightForWidth(intDeadTimeAC->sizePolicy().hasHeightForWidth());
        intDeadTimeAC->setSizePolicy(sizePolicy);
        intDeadTimeAC->setMaximum(4000);

        gridLayout_2->addWidget(intDeadTimeAC, 2, 1, 1, 1);

        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        gridLayout_2->addWidget(label_14, 2, 0, 1, 1);

        intMinPulseA = new QSpinBox(layoutWidget_2);
        intMinPulseA->setObjectName(QStringLiteral("intMinPulseA"));
        sizePolicy.setHeightForWidth(intMinPulseA->sizePolicy().hasHeightForWidth());
        intMinPulseA->setSizePolicy(sizePolicy);
        intMinPulseA->setMinimum(1);
        intMinPulseA->setMaximum(55);

        gridLayout_2->addWidget(intMinPulseA, 1, 1, 1, 1);

        intMaxPulseA = new QSpinBox(layoutWidget_2);
        intMaxPulseA->setObjectName(QStringLiteral("intMaxPulseA"));
        sizePolicy.setHeightForWidth(intMaxPulseA->sizePolicy().hasHeightForWidth());
        intMaxPulseA->setSizePolicy(sizePolicy);
        intMaxPulseA->setMinimum(1);
        intMaxPulseA->setMaximum(55);

        gridLayout_2->addWidget(intMaxPulseA, 0, 1, 1, 1);

        label_15 = new QLabel(layoutWidget_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        gridLayout_2->addWidget(label_15, 5, 0, 1, 1);

        btnGraphVIT = new QPushButton(centralWidget);
        btnGraphVIT->setObjectName(QStringLiteral("btnGraphVIT"));
        btnGraphVIT->setGeometry(QRect(950, 0, 71, 71));
        btnGraphVI = new QPushButton(centralWidget);
        btnGraphVI->setObjectName(QStringLiteral("btnGraphVI"));
        btnGraphVI->setGeometry(QRect(860, 0, 71, 71));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 70, 108, 19));
        label_7->setFont(font);
        intMaxVoltage = new QSpinBox(centralWidget);
        intMaxVoltage->setObjectName(QStringLiteral("intMaxVoltage"));
        intMaxVoltage->setGeometry(QRect(124, 119, 121, 75));
        sizePolicy.setHeightForWidth(intMaxVoltage->sizePolicy().hasHeightForWidth());
        intMaxVoltage->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(24);
        intMaxVoltage->setFont(font1);
        intMaxVoltage->setMinimum(1);
        intMaxVoltage->setMaximum(55);
        intMinVoltage = new QSpinBox(centralWidget);
        intMinVoltage->setObjectName(QStringLiteral("intMinVoltage"));
        intMinVoltage->setGeometry(QRect(124, 200, 121, 74));
        sizePolicy.setHeightForWidth(intMinVoltage->sizePolicy().hasHeightForWidth());
        intMinVoltage->setSizePolicy(sizePolicy);
        intMinVoltage->setFont(font1);
        intMinVoltage->setMinimum(1);
        intMinVoltage->setMaximum(55);
        dblVoltSec = new QDoubleSpinBox(centralWidget);
        dblVoltSec->setObjectName(QStringLiteral("dblVoltSec"));
        dblVoltSec->setGeometry(QRect(94, 42, 151, 71));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dblVoltSec->sizePolicy().hasHeightForWidth());
        dblVoltSec->setSizePolicy(sizePolicy1);
        dblVoltSec->setFont(font1);
        btnScanV = new QPushButton(centralWidget);
        btnScanV->setObjectName(QStringLiteral("btnScanV"));
        btnScanV->setGeometry(QRect(60, 280, 189, 61));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnScanV->sizePolicy().hasHeightForWidth());
        btnScanV->setSizePolicy(sizePolicy2);
        btnScanV->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 119, 108, 75));
        label_4->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 200, 108, 74));
        label_2->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(250, 220, 108, 35));
        label_6->setFont(font);
        dblVoltSec_2 = new QDoubleSpinBox(centralWidget);
        dblVoltSec_2->setObjectName(QStringLiteral("dblVoltSec_2"));
        dblVoltSec_2->setGeometry(QRect(334, 50, 131, 61));
        dblVoltSec_2->setFont(font1);
        intMinCurrent = new QSpinBox(centralWidget);
        intMinCurrent->setObjectName(QStringLiteral("intMinCurrent"));
        intMinCurrent->setGeometry(QRect(360, 200, 121, 71));
        sizePolicy.setHeightForWidth(intMinCurrent->sizePolicy().hasHeightForWidth());
        intMinCurrent->setSizePolicy(sizePolicy);
        intMinCurrent->setFont(font1);
        intMinCurrent->setMaximum(4000);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 140, 108, 35));
        label_5->setFont(font);
        btnScanI = new QPushButton(centralWidget);
        btnScanI->setObjectName(QStringLiteral("btnScanI"));
        btnScanI->setGeometry(QRect(310, 280, 179, 61));
        btnScanI->setFont(font);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(260, 70, 108, 20));
        label_9->setFont(font);
        intMaxCurrent = new QSpinBox(centralWidget);
        intMaxCurrent->setObjectName(QStringLiteral("intMaxCurrent"));
        intMaxCurrent->setGeometry(QRect(360, 120, 121, 71));
        sizePolicy.setHeightForWidth(intMaxCurrent->sizePolicy().hasHeightForWidth());
        intMaxCurrent->setSizePolicy(sizePolicy);
        intMaxCurrent->setFont(font1);
        intMaxCurrent->setMaximum(4000);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(540, 160, 106, 36));
        label_8->setFont(font);
        intMilligrams = new QSpinBox(centralWidget);
        intMilligrams->setObjectName(QStringLiteral("intMilligrams"));
        intMilligrams->setGeometry(QRect(506, 190, 151, 71));
        sizePolicy.setHeightForWidth(intMilligrams->sizePolicy().hasHeightForWidth());
        intMilligrams->setSizePolicy(sizePolicy);
        intMilligrams->setFont(font1);
        intMilligrams->setMaximum(4000);
        btnRun = new QPushButton(centralWidget);
        btnRun->setObjectName(QStringLiteral("btnRun"));
        btnRun->setGeometry(QRect(500, 280, 179, 61));
        btnRun->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnNewSession->setText(QApplication::translate("MainWindow", "NEW \n"
" SESSION", 0));
        label_10->setText(QApplication::translate("MainWindow", "MAX PULSE WIDTH", 0));
        btnScanPulseA->setText(QApplication::translate("MainWindow", "SCAN_ANODIC_PULSE", 0));
        label_3->setText(QApplication::translate("MainWindow", "MIN PULSE WIDTH", 0));
        label_14->setText(QApplication::translate("MainWindow", "DEAD_TIME", 0));
        label_15->setText(QApplication::translate("MainWindow", "CATHODE PULSE", 0));
        btnGraphVIT->setText(QApplication::translate("MainWindow", "GRAPH \n"
" VI-Time", 0));
        btnGraphVI->setText(QApplication::translate("MainWindow", "GRAPH \n"
" V vs I", 0));
        label_7->setText(QApplication::translate("MainWindow", "Volts/Sec", 0));
        btnScanV->setText(QApplication::translate("MainWindow", "SCAN_V", 0));
        label_4->setText(QApplication::translate("MainWindow", "VOLTAGE MAX", 0));
        label_2->setText(QApplication::translate("MainWindow", "VOLTAGE MIN", 0));
        label_6->setText(QApplication::translate("MainWindow", "CURRENT MIN", 0));
        label_5->setText(QApplication::translate("MainWindow", "CURRENT MAX", 0));
        btnScanI->setText(QApplication::translate("MainWindow", "SCAN_I", 0));
        label_9->setText(QApplication::translate("MainWindow", "mA/Sec", 0));
        label_8->setText(QApplication::translate("MainWindow", "mg to Transfer", 0));
        btnRun->setText(QApplication::translate("MainWindow", "DC_RUN", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
