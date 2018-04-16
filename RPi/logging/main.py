# -*- coding: utf-8 -*-
"""
PYQT python handlers

@author: Jeran
"""
import PyQt5
from PyQt5.QtWidgets import *
import sys, time, serial, datetime
import numpy as np
import pandas as pd
import db_funcs as db
import threading

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
        self.btnRun.clicked.connect(lambda: self.run())
        self.intMaxVoltage.valueChanged.connect(self.maxVchange)
        self.intMinVoltage.valueChanged.connect(self.minVchange)
        self.dblVoltSec.valueChanged.connect(self.voltSecChange)

        
    ### functions for the buttons to call
    def newDB(self):
        print ("New Database Created")
     
    def scanVoltage(self):
        #send arduino voltage limits followed by SCANV command
        ser.write(b'MAXV:')
        out_str = str(max_v) + '\n'
        ser.write(out_str.encode())
        ser.write(b'\n')
        ser.write(b'MINV:')
        out_str = str(min_v) + '\n'
        ser.write(out_str.encode())
        ser.write(b'\n')
        ser.write(b'VSEC:')
        out_str = str(volt_sec) + '\n'
        ser.write(out_str.encode())
        ser.write(b'\n')
        ser.write(b'SCANV\n')
        
        print ("Performing Potentiondynamic scan")
        
    def run(self):
        print ("Starting Polishing ...")
        
    def maxVchange(self):
        global max_v
        max_v = self.intMaxVoltage.value()
        print ("Max voltage: ")
        print(max_v)
        
    def minVchange(self):
        global min_v
        min_v = self.intMinVoltage.value()
        print ("Min voltage: ")
        print(min_v)
        
    def voltSecChange(self):
        global volt_sec
        volt_sec = self.dblVoltSec.value()
        print ("Min voltage: ")
        print(volt_sec)
        
        
def receive_data(log, serPort):
      
    while True:
        if serPort.inWaiting() !=0:
            try:
                in_serial = serPort.readline()
                #print(in_serial)
                in_serial = str(serPort.readline()).split(":")
            
                
                log.loc[len(log.index)] = [float(in_serial[1]), 
                                            float(in_serial[2]), 
                                            float(in_serial[3]), 
                                            float(in_serial[4]), 
                                            float(in_serial[5]), 
                                            float(in_serial[6]), 
                                            float(in_serial[7].strip("\\r\\n'")), 
                                            pd.Timestamp.now()]
                if(len(log)>3):
                    time_diff = log.time[len(log)] - log.time[len(log)-1]
                    log.total_charge[len(log)] = log.total_charge[len(log)-1] + log.oe_current.rolling(window = 2, center = False).mean()*time_diff.total_seconds()
                    
            except:
                print(in_serial)
            
            db.log_state("1.db", log.tail(1))
 
    
# I feel better having one of these
def main():
    #set session parameters which will later be passed from QT UI
    col_names = ["oe_voltage", "oe_current","ie_voltage", "ie_current", "surf_temp", "el_flow", "total_charge", "time"]
    
    database ="1.db"
    session_id = 1
    pulse_frequency = 2
    f_pulse_len = 200 #ms
    r_pulse_len = 50
    fr_dead = 200
    rf_dead = 50 
    flow_location = "core_out"
    flow_rate = 3.5 #l/min
    mass_removal = 0.35 #total grams removed
    f_rate = 0.2 #couloumbs
    r_rate = 0.05
    oe_space = 35 #mm
    ie_space = 3.5 #mm
    we_radius = 10 #mm
    we_mat = "NiTi"
    ce_mat = "SS_316"
    we_area = 17.165 #cm^2
    oce_area = 314.159
    ice_area = 6.597
    
        
    #create new session log
    db.create_db(database, "session_data", "session_log")
    #create new table which stores realtime data
    db.populate_session(database,
                 session_id,
                 pulse_frequency,
                 f_pulse_len,
                 r_pulse_len,
                 fr_dead,
                 rf_dead,
                 flow_location,
                 flow_rate,
                 mass_removal,
                 f_rate, r_rate,
                 oe_space,
                 ie_space,
                 we_radius,
                 we_mat,
                 ce_mat,
                 we_area,
                 oce_area,
                 ice_area)
    #create pandas dataframe to receive serial data and plot it
    log = pd.DataFrame(columns = col_names)



    #OPEN SERIAL PORT
    try:
        global ser
        ser = serial.Serial(port='COM6', baudrate=115200)
        print ("Hardware Node Connected")
    except Exception as e:
        print(e)
     # a new app instance
    app = QApplication(sys.argv)
    form = MainWindow()
    form.show()
     # without this, the script exits immediately.
    #sys.exit(app.exec_())


    #seperate blocking thread which handles serial reception
    thread = threading.Thread(target=receive_data, args=(log, ser))
    thread.start()
    
    sys.exit(app.exec_())

 
# python bit to figure how who started This
if __name__ == "__main__":
    main()
