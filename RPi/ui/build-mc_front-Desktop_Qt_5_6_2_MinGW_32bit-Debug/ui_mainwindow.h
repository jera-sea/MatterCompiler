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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
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
    QLabel *label_3;
    QSlider *sldScanVI;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QScrollBar *scrlMaxV;
    QSpinBox *spinBox;
    QLabel *label_2;
    QScrollBar *scrlMaxV_2;
    QSpinBox *spinBox_2;
    QLabel *label_5;
    QScrollBar *scrlMaxV_3;
    QSpinBox *spinBox_3;
    QLabel *label_6;
    QScrollBar *scrlMaxV_4;
    QSpinBox *spinBox_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnNewSession = new QPushButton(centralWidget);
        btnNewSession->setObjectName(QStringLiteral("btnNewSession"));
        btnNewSession->setGeometry(QRect(10, 0, 71, 71));
        btnScanV = new QPushButton(centralWidget);
        btnScanV->setObjectName(QStringLiteral("btnScanV"));
        btnScanV->setGeometry(QRect(930, 30, 71, 71));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(790, 0, 171, 20));
        QFont font;
        font.setFamily(QStringLiteral("MS PMincho"));
        font.setPointSize(16);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_3->setFont(font);
        sldScanVI = new QSlider(centralWidget);
        sldScanVI->setObjectName(QStringLiteral("sldScanVI"));
        sldScanVI->setGeometry(QRect(760, 110, 211, 61));
        sldScanVI->setContextMenuPolicy(Qt::ActionsContextMenu);
        sldScanVI->setAutoFillBackground(false);
        sldScanVI->setMaximum(1);
        sldScanVI->setSingleStep(0);
        sldScanVI->setSliderPosition(0);
        sldScanVI->setOrientation(Qt::Horizontal);
        sldScanVI->setTickInterval(1);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 210, 991, 241));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setPointSize(12);
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        scrlMaxV = new QScrollBar(widget);
        scrlMaxV->setObjectName(QStringLiteral("scrlMaxV"));
        scrlMaxV->setStyleSheet(QLatin1String("selection-color: rgb(0, 0, 255);\n"
"background-color: rgb(0, 0, 0);\n"
""));
        scrlMaxV->setMaximum(55);
        scrlMaxV->setValue(0);
        scrlMaxV->setOrientation(Qt::Horizontal);
        scrlMaxV->setInvertedAppearance(false);

        gridLayout_2->addWidget(scrlMaxV, 0, 1, 1, 1);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMinimum(1);
        spinBox->setMaximum(55);

        gridLayout_2->addWidget(spinBox, 0, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        scrlMaxV_2 = new QScrollBar(widget);
        scrlMaxV_2->setObjectName(QStringLiteral("scrlMaxV_2"));
        scrlMaxV_2->setStyleSheet(QLatin1String("selection-color: rgb(0, 0, 255);\n"
"background-color: rgb(0, 0, 0);\n"
""));
        scrlMaxV_2->setMaximum(55);
        scrlMaxV_2->setValue(0);
        scrlMaxV_2->setOrientation(Qt::Horizontal);
        scrlMaxV_2->setInvertedAppearance(false);

        gridLayout_2->addWidget(scrlMaxV_2, 1, 1, 1, 1);

        spinBox_2 = new QSpinBox(widget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        sizePolicy.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy);
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(55);

        gridLayout_2->addWidget(spinBox_2, 1, 2, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        scrlMaxV_3 = new QScrollBar(widget);
        scrlMaxV_3->setObjectName(QStringLiteral("scrlMaxV_3"));
        scrlMaxV_3->setStyleSheet(QLatin1String("selection-color: rgb(0, 0, 255);\n"
"background-color: rgb(0, 0, 0);\n"
""));
        scrlMaxV_3->setMaximum(4000);
        scrlMaxV_3->setValue(0);
        scrlMaxV_3->setOrientation(Qt::Horizontal);
        scrlMaxV_3->setInvertedAppearance(false);

        gridLayout_2->addWidget(scrlMaxV_3, 2, 1, 1, 1);

        spinBox_3 = new QSpinBox(widget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        sizePolicy.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy);
        spinBox_3->setMaximum(4000);

        gridLayout_2->addWidget(spinBox_3, 2, 2, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        scrlMaxV_4 = new QScrollBar(widget);
        scrlMaxV_4->setObjectName(QStringLiteral("scrlMaxV_4"));
        scrlMaxV_4->setStyleSheet(QLatin1String("selection-color: rgb(0, 0, 255);\n"
"background-color: rgb(0, 0, 0);\n"
""));
        scrlMaxV_4->setMaximum(4000);
        scrlMaxV_4->setValue(0);
        scrlMaxV_4->setOrientation(Qt::Horizontal);
        scrlMaxV_4->setInvertedAppearance(false);

        gridLayout_2->addWidget(scrlMaxV_4, 3, 1, 1, 1);

        spinBox_4 = new QSpinBox(widget);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        sizePolicy.setHeightForWidth(spinBox_4->sizePolicy().hasHeightForWidth());
        spinBox_4->setSizePolicy(sizePolicy);
        spinBox_4->setMaximum(4000);

        gridLayout_2->addWidget(spinBox_4, 3, 2, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 10);
        gridLayout_2->setColumnStretch(2, 1);
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
        QObject::connect(scrlMaxV, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), scrlMaxV, SLOT(setValue(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), scrlMaxV_2, SLOT(setValue(int)));
        QObject::connect(scrlMaxV_2, SIGNAL(valueChanged(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), scrlMaxV_3, SLOT(setValue(int)));
        QObject::connect(scrlMaxV_3, SIGNAL(valueChanged(int)), spinBox_3, SLOT(setValue(int)));
        QObject::connect(spinBox_4, SIGNAL(valueChanged(int)), scrlMaxV_4, SLOT(setValue(int)));
        QObject::connect(scrlMaxV_4, SIGNAL(valueChanged(int)), spinBox_4, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnNewSession->setText(QApplication::translate("MainWindow", "NEW \n"
" SESSION", 0));
        btnScanV->setText(QApplication::translate("MainWindow", "SCAN", 0));
        label_3->setText(QApplication::translate("MainWindow", "SCAN SETTINGS", 0));
#ifndef QT_NO_TOOLTIP
        sldScanVI->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("MainWindow", "VOLTAGE MAX", 0));
        label_2->setText(QApplication::translate("MainWindow", "VOLTAGE MIN", 0));
        label_5->setText(QApplication::translate("MainWindow", "CURRENT MAX", 0));
        label_6->setText(QApplication::translate("MainWindow", "CURRENT MIN", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
