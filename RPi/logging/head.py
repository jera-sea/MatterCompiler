import sys, time, serial, datetime
import numpy as np
import pandas as pd
import db_funcs as db

col_names = ["oe_voltage", "oe_current","ie_voltage", "ie_current", "surf_temp", "el_flow", "total_charge", "time"]



#try:
#ser = serial.Serial('/dev/ttyACM0', 115200)

#except:
 #   print("HW NODE NOT PRESENT!")


def main():
    try:
        ser = serial.Serial(port='COM6', baudrate=115200)
        print ("Hardware Node Connected")
    except Exception as e:
        print(e)
    
    log = pd.DataFrame(columns = col_names)
    while True:
        if ser.inWaiting() !=0:
            receive_data(ser, log)
            print(type(log.tail(1)))
            print(log.tail(1))
            
            db.log_state("1.db", log.tail(1))
   
            break
    

def receive_data(ser, log):
   # try:
    in_serial = ser.readline()
    while(in_serial != "sID = \r\n"):
        if ser.inWaiting()==0:
            break
        in_serial = ser.readline()
        
    in_serial = ser.readline()       
    in_serial = str(ser.readline()).split(":")

    log.loc[len(log.index)] = [float(in_serial[0].split("'")[1]), 
                                float(in_serial[1]), 
                                float(in_serial[2]), 
                                float(in_serial[3]), 
                                float(in_serial[4]), 
                                float(in_serial[5]), 
                                float(in_serial[6].strip("\\r\\n'")), 
                                pd.Timestamp.now()]
    
    time_diff = log.time[len(log)] - log.time[len(log)-1]
    
    log.total_charge[len(log)] = log.total_charge[len(log)-1] + log.oe_current.rolling(window = 5, center = False).mean()*time_diff.total_seconds()
    
    

    
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

db.create_db(database, "session_data", "session_log")

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

main()
ser.close() 

#if ser:
ser.close()