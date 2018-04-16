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
    QPushButton *btnScanV;
    QPushButton *btnRun;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QSpinBox *intMinVoltage;
    QLabel *label_5;
    QLabel *label_2;
    QSpinBox *intMinCurrent;
    QLabel *label_6;
    QSpinBox *intMaxCurrent;
    QLabel *label_4;
    QSpinBox *intMaxVoltage;
    QDoubleSpinBox *dblVoltSec;
    QLabel *label_7;
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
        btnScanV = new QPushButton(centralWidget);
        btnScanV->setObjectName(QStringLiteral("btnScanV"));
        btnScanV->setGeometry(QRect(940, 260, 71, 71));
        QFont font;
        font.setPointSize(12);
        btnScanV->setFont(font);
        btnRun = new QPushButton(centralWidget);
        btnRun->setObjectName(QStringLiteral("btnRun"));
        btnRun->setGeometry(QRect(700, 260, 71, 71));
        btnRun->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 10, 311, 241));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        intMinVoltage = new QSpinBox(layoutWidget);
        intMinVoltage->setObjectName(QStringLiteral("intMinVoltage"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(intMinVoltage->sizePolicy().hasHeightForWidth());
        intMinVoltage->setSizePolicy(sizePolicy);
        intMinVoltage->setMinimum(1);
        intMinVoltage->setMaximum(55);

        gridLayout_2->addWidget(intMinVoltage, 1, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        intMinCurrent = new QSpinBox(layoutWidget);
        intMinCurrent->setObjectName(QStringLiteral("intMinCurrent"));
        sizePolicy.setHeightForWidth(intMinCurrent->sizePolicy().hasHeightForWidth());
        intMinCurrent->setSizePolicy(sizePolicy);
        intMinCurrent->setMaximum(4000);

        gridLayout_2->addWidget(intMinCurrent, 3, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        intMaxCurrent = new QSpinBox(layoutWidget);
        intMaxCurrent->setObjectName(QStringLiteral("intMaxCurrent"));
        sizePolicy.setHeightForWidth(intMaxCurrent->sizePolicy().hasHeightForWidth());
        intMaxCurrent->setSizePolicy(sizePolicy);
        intMaxCurrent->setMaximum(4000);

        gridLayout_2->addWidget(intMaxCurrent, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        intMaxVoltage = new QSpinBox(layoutWidget);
        intMaxVoltage->setObjectName(QStringLiteral("intMaxVoltage"));
        sizePolicy.setHeightForWidth(intMaxVoltage->sizePolicy().hasHeightForWidth());
        intMaxVoltage->setSizePolicy(sizePolicy);
        intMaxVoltage->setMinimum(1);
        intMaxVoltage->setMaximum(55);

        gridLayout_2->addWidget(intMaxVoltage, 0, 1, 1, 1);

        dblVoltSec = new QDoubleSpinBox(centralWidget);
        dblVoltSec->setObjectName(QStringLiteral("dblVoltSec"));
        dblVoltSec->setGeometry(QRect(460, 20, 101, 41));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(320, 10, 152, 55));
        label_7->setFont(font);
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
        btnScanV->setText(QApplication::translate("MainWindow", "SCAN", 0));
        btnRun->setText(QApplication::translate("MainWindow", "RUN", 0));
        label_5->setText(QApplication::translate("MainWindow", "CURRENT MAX", 0));
        label_2->setText(QApplication::translate("MainWindow", "VOLTAGE MIN", 0));
        label_6->setText(QApplication::translate("MainWindow", "CURRENT MIN", 0));
        label_4->setText(QApplication::translate("MainWindow", "VOLTAGE MAX", 0));
        label_7->setText(QApplication::translate("MainWindow", "Volts/Sec", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
