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
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QSpinBox *intMaxVoltage;
    QSpinBox *intMinVoltage;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *btnScanV;
    QLabel *label_7;
    QDoubleSpinBox *dblVoltSec;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QLabel *label_9;
    QDoubleSpinBox *dblVoltSec_2;
    QLabel *label_5;
    QSpinBox *intMaxCurrent;
    QLabel *label_6;
    QSpinBox *intMinCurrent;
    QPushButton *btnScanI;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QPushButton *btnRun;
    QSpinBox *intMilligrams;
    QPushButton *btnGraphVIT;
    QPushButton *btnGraphVI;
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
        btnNewSession->setGeometry(QRect(10, 0, 71, 71));
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(590, 150, 301, 191));
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

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 210, 191, 130));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        intMaxVoltage = new QSpinBox(layoutWidget);
        intMaxVoltage->setObjectName(QStringLiteral("intMaxVoltage"));
        sizePolicy.setHeightForWidth(intMaxVoltage->sizePolicy().hasHeightForWidth());
        intMaxVoltage->setSizePolicy(sizePolicy);
        intMaxVoltage->setMinimum(1);
        intMaxVoltage->setMaximum(55);

        gridLayout_3->addWidget(intMaxVoltage, 2, 1, 1, 1);

        intMinVoltage = new QSpinBox(layoutWidget);
        intMinVoltage->setObjectName(QStringLiteral("intMinVoltage"));
        sizePolicy.setHeightForWidth(intMinVoltage->sizePolicy().hasHeightForWidth());
        intMinVoltage->setSizePolicy(sizePolicy);
        intMinVoltage->setMinimum(1);
        intMinVoltage->setMaximum(55);

        gridLayout_3->addWidget(intMinVoltage, 3, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_3->addWidget(label_2, 3, 0, 1, 1);

        btnScanV = new QPushButton(layoutWidget);
        btnScanV->setObjectName(QStringLiteral("btnScanV"));
        btnScanV->setFont(font);

        gridLayout_3->addWidget(btnScanV, 5, 0, 1, 2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        dblVoltSec = new QDoubleSpinBox(layoutWidget);
        dblVoltSec->setObjectName(QStringLiteral("dblVoltSec"));

        gridLayout_3->addWidget(dblVoltSec, 1, 1, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(210, 210, 181, 131));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_4->setVerticalSpacing(4);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        dblVoltSec_2 = new QDoubleSpinBox(layoutWidget1);
        dblVoltSec_2->setObjectName(QStringLiteral("dblVoltSec_2"));

        gridLayout_4->addWidget(dblVoltSec_2, 0, 1, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_4->addWidget(label_5, 1, 0, 1, 1);

        intMaxCurrent = new QSpinBox(layoutWidget1);
        intMaxCurrent->setObjectName(QStringLiteral("intMaxCurrent"));
        sizePolicy.setHeightForWidth(intMaxCurrent->sizePolicy().hasHeightForWidth());
        intMaxCurrent->setSizePolicy(sizePolicy);
        intMaxCurrent->setMaximum(4000);

        gridLayout_4->addWidget(intMaxCurrent, 1, 1, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_4->addWidget(label_6, 2, 0, 1, 1);

        intMinCurrent = new QSpinBox(layoutWidget1);
        intMinCurrent->setObjectName(QStringLiteral("intMinCurrent"));
        sizePolicy.setHeightForWidth(intMinCurrent->sizePolicy().hasHeightForWidth());
        intMinCurrent->setSizePolicy(sizePolicy);
        intMinCurrent->setMaximum(4000);

        gridLayout_4->addWidget(intMinCurrent, 2, 1, 1, 1);

        btnScanI = new QPushButton(layoutWidget1);
        btnScanI->setObjectName(QStringLiteral("btnScanI"));
        btnScanI->setFont(font);

        gridLayout_4->addWidget(btnScanI, 3, 0, 1, 2);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(400, 270, 181, 71));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        btnRun = new QPushButton(layoutWidget2);
        btnRun->setObjectName(QStringLiteral("btnRun"));
        btnRun->setFont(font);

        gridLayout->addWidget(btnRun, 1, 0, 1, 2);

        intMilligrams = new QSpinBox(layoutWidget2);
        intMilligrams->setObjectName(QStringLiteral("intMilligrams"));
        sizePolicy.setHeightForWidth(intMilligrams->sizePolicy().hasHeightForWidth());
        intMilligrams->setSizePolicy(sizePolicy);
        intMilligrams->setMaximum(4000);

        gridLayout->addWidget(intMilligrams, 0, 1, 1, 1);

        btnGraphVIT = new QPushButton(centralWidget);
        btnGraphVIT->setObjectName(QStringLiteral("btnGraphVIT"));
        btnGraphVIT->setGeometry(QRect(440, 0, 71, 71));
        btnGraphVI = new QPushButton(centralWidget);
        btnGraphVI->setObjectName(QStringLiteral("btnGraphVI"));
        btnGraphVI->setGeometry(QRect(530, 0, 71, 71));
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
        label_4->setText(QApplication::translate("MainWindow", "VOLTAGE MAX", 0));
        label_2->setText(QApplication::translate("MainWindow", "VOLTAGE MIN", 0));
        btnScanV->setText(QApplication::translate("MainWindow", "SCAN_V", 0));
        label_7->setText(QApplication::translate("MainWindow", "Volts/Sec", 0));
        label_9->setText(QApplication::translate("MainWindow", "mA/Sec", 0));
        label_5->setText(QApplication::translate("MainWindow", "CURRENT MAX", 0));
        label_6->setText(QApplication::translate("MainWindow", "CURRENT MIN", 0));
        btnScanI->setText(QApplication::translate("MainWindow", "SCAN_I", 0));
        label_8->setText(QApplication::translate("MainWindow", "mg to Transfer", 0));
        btnRun->setText(QApplication::translate("MainWindow", "DC_RUN", 0));
        btnGraphVIT->setText(QApplication::translate("MainWindow", "GRAPH \n"
" VI-Time", 0));
        btnGraphVI->setText(QApplication::translate("MainWindow", "GRAPH \n"
" V vs I", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
