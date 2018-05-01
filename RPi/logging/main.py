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
import threading
import scipy.constants
import db_funcs as db
import graphing as gp

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
        self.btnGraphVIT.clicked.connect(lambda: self.GraphVIT())
        self.btnGraphVI.clicked.connect(lambda: self.GraphVI())
        self.intMaxVoltage.valueChanged.connect(self.maxVchange)
        self.intMinVoltage.valueChanged.connect(self.minVchange)
        self.intMaxCurrent.valueChanged.connect(self.maxIchange)
        self.intMilligrams.valueChanged.connect(self.massChange)
        self.dblVoltSec.valueChanged.connect(self.voltSecChange)

        
    ### functions for the buttons to call
    def newDB(self):
        print ("New Database Created")
     
    def scanVoltage(self):
        #send arduino voltage limits followed by SCANV command
        try:
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
        except:
            print("SET PARAMETERS FIRST")
        ser.write(b'SCANV\n')
        
        print ("Performing Potentiondynamic scan")
        
    def run(self):
        print ("Starting Polishing ...")
        out_str = str(max_i) + '\n'
        ser.write(b'MAXI:')
        ser.write(out_str.encode())
        # calculate total charge required to remove x grams of Ti and Ni
        mass = mg/1000 #convert milligrams to g
        #assume 1:1 Ti:Ni
        TiMolMass = 47.867
        NiMolMass = 58.693
        #assume the oxidation reactions produce Ti2+ and Ni2+
        TiCharge = (((mass/2)/TiMolMass)*scipy.constants.Avogadro*scipy.constants.e)*2
        NiCharge = (((mass/2)/NiMolMass)*scipy.constants.Avogadro*scipy.constants.e)*2
        TotCharge = TiCharge+NiCharge
        print(TotCharge)
        ser.write(b'RUN:')
        out_str = str(round(TotCharge, 3)) + '\n'
        ser.write(out_str.encode())
        
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
    def maxIchange(self):
        global max_i
        max_i = self.intMaxCurrent.value()
        print ("Max Current: ")
        print(max_i)
    def massChange(self):
        global mg
        mg = self.intMilligrams.value()
        print ("Mass to Transfer in mg: ")
        print(mg)
    def GraphVI(self):
        gp.graphVvsI(database)
        #thread = threading.Thread(target=gp.graphVvsI, args=(database,))
        #thread.start()
    def GraphVIT(self):
        print("graphing")
        
        
        
def receive_data(datab):
    global log
    while True:
        if ser.inWaiting() !=0:
            try:
                in_serial = ser.readline()
                #timeNow = pd.Timestamp.now()
                #print(in_serial)
                #print(in_serial)
                in_serial = str(ser.readline()).split(":")
                #print(in_serial)
                
                log.loc[len(log.index)] = [float(in_serial[1]), 
                                            float(in_serial[2]), 
                                            float(in_serial[3]), 
                                            float(in_serial[4]), 
                                            float(in_serial[5]), 
                                            float(in_serial[6]), 
                                            float(in_serial[7]), 
                                            float(in_serial[8].strip("\\r\\n'"))]

                db.log_state(datab, log.tail(1))
                    
            except:
                print("ERROR")
            
# I feel better having one of these
def main():
    #set session parameters which will later be passed from QT UI
    col_names = ["oe_voltage", "oe_current","ie_voltage", "ie_current", "surf_temp", "el_flow", "total_charge", "time"]
    
    #database ="1.db"
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
    global database
    database = time.strftime("%Y%m%d-%H%M%S") + ".db" 
        
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
    global log
    log = pd.DataFrame(columns = col_names)



    #OPEN SERIAL PORT
    try:
        global ser
        #ser = serial.Serial(port='/dev/ttyACM0', baudrate=115200)
        ser = serial.Serial(port='COM6', baudrate=115200)
        print ("Hardware Node Connected")
    except Exception as e:
        print(e)
     # a new app instance
    app = QApplication(sys.argv)
    form = MainWindow()
    form.show()

    #seperate blocking thread which handles serial reception
    thread = threading.Thread(target=receive_data, args=(database,))
    thread.start()
    
    # without this, the script exits immediately.
    sys.exit(app.exec_())

# python bit to figure how who started This
if __name__ == "__main__":
    main()