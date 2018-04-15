# -*- coding: utf-8 -*-
"""
PYQT python handlers

@author: Jeran
"""
import sys
import PyQt5
from PyQt5.QtWidgets import *
 
# This is our window from QtCreator
import mainwindow_auto
 
# create class for our Raspberry Pi GUI
class MainWindow(QMainWindow, mainwindow_auto.Ui_MainWindow):
 # access variables inside of the UI's file
    def __init__(self):
        super(self.__class__, self).__init__()
        self.setupUi(self) # gets defined in the UI file
         ### Hooks to for buttons
        self.btnNewSession.clicked.connect(lambda: self.newDB())
        self.btnScanV.clicked.connect(lambda: self.scanVoltage())
        
    ### functions for the buttons to call
    def newDB(self):
        print ("New Database Created")
     
    def scanVoltage(self):
        print ("Performing Potentiondynamic scan")
 
# I feel better having one of these
def main():
     # a new app instance
    app = QApplication(sys.argv)
    form = MainWindow()
    form.show()
     # without this, the script exits immediately.
    sys.exit(app.exec_())
 
# python bit to figure how who started This
if __name__ == "__main__":
    main()
