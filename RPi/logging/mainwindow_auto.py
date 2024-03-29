# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.6
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1024, 400)
        self.centralWidget = QtWidgets.QWidget(MainWindow)
        self.centralWidget.setObjectName("centralWidget")
        self.btnNewSession = QtWidgets.QPushButton(self.centralWidget)
        self.btnNewSession.setGeometry(QtCore.QRect(950, 70, 71, 71))
        self.btnNewSession.setObjectName("btnNewSession")
        self.layoutWidget_2 = QtWidgets.QWidget(self.centralWidget)
        self.layoutWidget_2.setGeometry(QtCore.QRect(700, 150, 301, 191))
        self.layoutWidget_2.setObjectName("layoutWidget_2")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.layoutWidget_2)
        self.gridLayout_2.setContentsMargins(11, 11, 11, 11)
        self.gridLayout_2.setSpacing(6)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.label_10 = QtWidgets.QLabel(self.layoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_10.setFont(font)
        self.label_10.setObjectName("label_10")
        self.gridLayout_2.addWidget(self.label_10, 0, 0, 1, 1)
        self.btnScanPulseA = QtWidgets.QPushButton(self.layoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.btnScanPulseA.setFont(font)
        self.btnScanPulseA.setObjectName("btnScanPulseA")
        self.gridLayout_2.addWidget(self.btnScanPulseA, 6, 0, 1, 2)
        self.intMaxPulseC = QtWidgets.QSpinBox(self.layoutWidget_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.intMaxPulseC.sizePolicy().hasHeightForWidth())
        self.intMaxPulseC.setSizePolicy(sizePolicy)
        self.intMaxPulseC.setMaximum(4000)
        self.intMaxPulseC.setObjectName("intMaxPulseC")
        self.gridLayout_2.addWidget(self.intMaxPulseC, 5, 1, 1, 1)
        self.label_3 = QtWidgets.QLabel(self.layoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.gridLayout_2.addWidget(self.label_3, 1, 0, 1, 1)
        self.intDeadTimeAC = QtWidgets.QSpinBox(self.layoutWidget_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.intDeadTimeAC.sizePolicy().hasHeightForWidth())
        self.intDeadTimeAC.setSizePolicy(sizePolicy)
        self.intDeadTimeAC.setMaximum(4000)
        self.intDeadTimeAC.setObjectName("intDeadTimeAC")
        self.gridLayout_2.addWidget(self.intDeadTimeAC, 2, 1, 1, 1)
        self.label_14 = QtWidgets.QLabel(self.layoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_14.setFont(font)
        self.label_14.setObjectName("label_14")
        self.gridLayout_2.addWidget(self.label_14, 2, 0, 1, 1)
        self.intMinPulseA = QtWidgets.QSpinBox(self.layoutWidget_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.intMinPulseA.sizePolicy().hasHeightForWidth())
        self.intMinPulseA.setSizePolicy(sizePolicy)
        self.intMinPulseA.setMinimum(1)
        self.intMinPulseA.setMaximum(55)
        self.intMinPulseA.setObjectName("intMinPulseA")
        self.gridLayout_2.addWidget(self.intMinPulseA, 1, 1, 1, 1)
        self.intMaxPulseA = QtWidgets.QSpinBox(self.layoutWidget_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.intMaxPulseA.sizePolicy().hasHeightForWidth())
        self.intMaxPulseA.setSizePolicy(sizePolicy)
        self.intMaxPulseA.setMinimum(1)
        self.intMaxPulseA.setMaximum(55)
        self.intMaxPulseA.setObjectName("intMaxPulseA")
        self.gridLayout_2.addWidget(self.intMaxPulseA, 0, 1, 1, 1)
        self.label_15 = QtWidgets.QLabel(self.layoutWidget_2)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_15.setFont(font)
        self.label_15.setObjectName("label_15")
        self.gridLayout_2.addWidget(self.label_15, 5, 0, 1, 1)
        self.btnGraphVIT = QtWidgets.QPushButton(self.centralWidget)
        self.btnGraphVIT.setGeometry(QtCore.QRect(950, 0, 71, 71))
        self.btnGraphVIT.setObjectName("btnGraphVIT")
        self.btnGraphVI = QtWidgets.QPushButton(self.centralWidget)
        self.btnGraphVI.setGeometry(QtCore.QRect(860, 0, 71, 71))
        self.btnGraphVI.setObjectName("btnGraphVI")
        self.label_7 = QtWidgets.QLabel(self.centralWidget)
        self.label_7.setGeometry(QtCore.QRect(10, 70, 108, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_7.setFont(font)
        self.label_7.setObjectName("label_7")
        self.intMaxVoltage = QtWidgets.QSpinBox(self.centralWidget)
        self.intMaxVoltage.setGeometry(QtCore.QRect(124, 119, 121, 75))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.intMaxVoltage.sizePolicy().hasHeightForWidth())
        self.intMaxVoltage.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(24)
        self.intMaxVoltage.setFont(font)
        self.intMaxVoltage.setMinimum(1)
        self.intMaxVoltage.setMaximum(55)
        self.intMaxVoltage.setObjectName("intMaxVoltage")
        self.intMinVoltage = QtWidgets.QSpinBox(self.centralWidget)
        self.intMinVoltage.setGeometry(QtCore.QRect(124, 200, 121, 74))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.intMinVoltage.sizePolicy().hasHeightForWidth())
        self.intMinVoltage.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(24)
        self.intMinVoltage.setFont(font)
        self.intMinVoltage.setMinimum(1)
        self.intMinVoltage.setMaximum(55)
        self.intMinVoltage.setObjectName("intMinVoltage")
        self.dblVoltSec = QtWidgets.QDoubleSpinBox(self.centralWidget)
        self.dblVoltSec.setGeometry(QtCore.QRect(94, 42, 151, 71))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.dblVoltSec.sizePolicy().hasHeightForWidth())
        self.dblVoltSec.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(24)
        self.dblVoltSec.setFont(font)
        self.dblVoltSec.setObjectName("dblVoltSec")
        self.btnScanV = QtWidgets.QPushButton(self.centralWidget)
        self.btnScanV.setGeometry(QtCore.QRect(60, 280, 189, 61))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.MinimumExpanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.btnScanV.sizePolicy().hasHeightForWidth())
        self.btnScanV.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.btnScanV.setFont(font)
        self.btnScanV.setObjectName("btnScanV")
        self.label_4 = QtWidgets.QLabel(self.centralWidget)
        self.label_4.setGeometry(QtCore.QRect(10, 119, 108, 75))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_4.setFont(font)
        self.label_4.setObjectName("label_4")
        self.label_2 = QtWidgets.QLabel(self.centralWidget)
        self.label_2.setGeometry(QtCore.QRect(10, 200, 108, 74))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.label_6 = QtWidgets.QLabel(self.centralWidget)
        self.label_6.setGeometry(QtCore.QRect(250, 220, 108, 35))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_6.setFont(font)
        self.label_6.setObjectName("label_6")
        self.dblVoltSec_2 = QtWidgets.QDoubleSpinBox(self.centralWidget)
        self.dblVoltSec_2.setGeometry(QtCore.QRect(334, 50, 131, 61))
        font = QtGui.QFont()
        font.setPointSize(24)
        self.dblVoltSec_2.setFont(font)
        self.dblVoltSec_2.setObjectName("dblVoltSec_2")
        self.intMinCurrent = QtWidgets.QSpinBox(self.centralWidget)
        self.intMinCurrent.setGeometry(QtCore.QRect(360, 200, 121, 71))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.intMinCurrent.sizePolicy().hasHeightForWidth())
        self.intMinCurrent.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(24)
        self.intMinCurrent.setFont(font)
        self.intMinCurrent.setMaximum(4000)
        self.intMinCurrent.setObjectName("intMinCurrent")
        self.label_5 = QtWidgets.QLabel(self.centralWidget)
        self.label_5.setGeometry(QtCore.QRect(250, 140, 108, 35))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_5.setFont(font)
        self.label_5.setObjectName("label_5")
        self.btnScanI = QtWidgets.QPushButton(self.centralWidget)
        self.btnScanI.setGeometry(QtCore.QRect(310, 280, 179, 61))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.btnScanI.setFont(font)
        self.btnScanI.setObjectName("btnScanI")
        self.label_9 = QtWidgets.QLabel(self.centralWidget)
        self.label_9.setGeometry(QtCore.QRect(260, 70, 108, 20))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_9.setFont(font)
        self.label_9.setObjectName("label_9")
        self.intMaxCurrent = QtWidgets.QSpinBox(self.centralWidget)
        self.intMaxCurrent.setGeometry(QtCore.QRect(360, 120, 121, 71))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.intMaxCurrent.sizePolicy().hasHeightForWidth())
        self.intMaxCurrent.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(24)
        self.intMaxCurrent.setFont(font)
        self.intMaxCurrent.setMaximum(4000)
        self.intMaxCurrent.setObjectName("intMaxCurrent")
        self.label_8 = QtWidgets.QLabel(self.centralWidget)
        self.label_8.setGeometry(QtCore.QRect(540, 160, 106, 36))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_8.setFont(font)
        self.label_8.setObjectName("label_8")
        self.intMilligrams = QtWidgets.QSpinBox(self.centralWidget)
        self.intMilligrams.setGeometry(QtCore.QRect(506, 190, 151, 71))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.intMilligrams.sizePolicy().hasHeightForWidth())
        self.intMilligrams.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(24)
        self.intMilligrams.setFont(font)
        self.intMilligrams.setMaximum(4000)
        self.intMilligrams.setObjectName("intMilligrams")
        self.btnRun = QtWidgets.QPushButton(self.centralWidget)
        self.btnRun.setGeometry(QtCore.QRect(500, 280, 179, 61))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.btnRun.setFont(font)
        self.btnRun.setObjectName("btnRun")
        MainWindow.setCentralWidget(self.centralWidget)
        self.menuBar = QtWidgets.QMenuBar(MainWindow)
        self.menuBar.setGeometry(QtCore.QRect(0, 0, 1024, 21))
        self.menuBar.setObjectName("menuBar")
        MainWindow.setMenuBar(self.menuBar)
        self.mainToolBar = QtWidgets.QToolBar(MainWindow)
        self.mainToolBar.setObjectName("mainToolBar")
        MainWindow.addToolBar(QtCore.Qt.TopToolBarArea, self.mainToolBar)
        self.statusBar = QtWidgets.QStatusBar(MainWindow)
        self.statusBar.setObjectName("statusBar")
        MainWindow.setStatusBar(self.statusBar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.btnNewSession.setText(_translate("MainWindow", "NEW \n"
" SESSION"))
        self.label_10.setText(_translate("MainWindow", "MAX PULSE WIDTH"))
        self.btnScanPulseA.setText(_translate("MainWindow", "SCAN_ANODIC_PULSE"))
        self.label_3.setText(_translate("MainWindow", "MIN PULSE WIDTH"))
        self.label_14.setText(_translate("MainWindow", "DEAD_TIME"))
        self.label_15.setText(_translate("MainWindow", "CATHODE PULSE"))
        self.btnGraphVIT.setText(_translate("MainWindow", "GRAPH \n"
" VI-Time"))
        self.btnGraphVI.setText(_translate("MainWindow", "GRAPH \n"
" V vs I"))
        self.label_7.setText(_translate("MainWindow", "Volts/Sec"))
        self.btnScanV.setText(_translate("MainWindow", "SCAN_V"))
        self.label_4.setText(_translate("MainWindow", "VOLTAGE MAX"))
        self.label_2.setText(_translate("MainWindow", "VOLTAGE MIN"))
        self.label_6.setText(_translate("MainWindow", "CURRENT MIN"))
        self.label_5.setText(_translate("MainWindow", "CURRENT MAX"))
        self.btnScanI.setText(_translate("MainWindow", "SCAN_I"))
        self.label_9.setText(_translate("MainWindow", "mA/Sec"))
        self.label_8.setText(_translate("MainWindow", "mg to Transfer"))
        self.btnRun.setText(_translate("MainWindow", "DC_RUN"))

