#!/usr/bin/python
# -*- coding: utf-8 -*-

import sqlite3 as sql
import os, sys, time, datetime
import pandas as pd
#######################################################################################################################
def create_db(db_name, session_table, log_table):
        db_con = sql.connect(db_name)
        try:
                with db_con:
                        cur = db_con.cursor()
                        cur.execute("DROP TABLE IF EXISTS {0}".format(session_table))
                        cur.execute("CREATE TABLE IF NOT EXISTS {0}(session_id, \
                                                                        pulse_frequency REAL, \
                                                                        f_pulse_len INT, \
                                                                        r_pulse_len INT, \
                                                                        fr_dead INT, \
                                                                        rf_dead INT, \
                                                                        flow_location TEXT, \
                                                                        flow_rate REAL, \
                                                                        mass_removal REAL, \
                                                                        f_rate REAL, \
                                                                        r_rate REAL, \
                                                                        oe_space REAL, \
                                                                        ie_space REAL, \
                                                                        we_radius REAL, \
                                                                        we_mat TEXT, \
                                                                        ce_mat TEXT, \
                                                                        we_area REAL, \
                                                                        oce_area REAL, \
                                                                        ice_area REAL)".format(session_table))
                                                                        
                                                                        
                                    
                        cur.execute("DROP TABLE IF EXISTS {0}".format(log_table))
                        cur.execute('CREATE TABLE IF NOT EXISTS {0}(oe_voltage REAL, \
                                                                oe_current REAL, \
                                                                ie_voltage REAL, \
                                                                ie_current REAL, \
                                                                surf_temp REAL, \
                                                                el_flow REAL, \
                                                                total_charge REAL, \
                                                                time TEXT)'.format(log_table))	
        except sql.Error as e:
            print("Error %s:" % e.args[0])
            sys.exit(1)		
        return
#######################################################################################################################
def populate_session(db_name, sID, pf, fp, rp, frd, rfd, fLoc, flowR, massR, Frate, Rrate, oeS, ieS, weR, weM, ceM, weA, oceA, iceA ):
        db_con = sql.connect(db_name)

        with db_con:
                cur = db_con.cursor()
                cur.execute("INSERT INTO session_data VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", (sID, pf, fp, rp, frd, rfd, fLoc, flowR, massR, Frate, Rrate, oeS, ieS, weR, weM, ceM, weA, oceA, iceA))           


        return


#######################################################################################################################

def log_state(db_name, data):
   
        con = None
            
        try:
                con = sql.connect(db_name)
                with con:   
                        cur = con.cursor()
                        data.to_sql("session_log", con, if_exists='append', index=False)
                        #cur.execute("INSERT INTO session_log VALUES(?, ?, ?, ?, ?, ?, ?, ?)", (data))
        except sql.Error as e:
                print("Error %s:" %e.args[0])
                sys.exit(1)
        return
 #######################################################################################################################                                       
"""
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

timeNow = pd.Timestamp.now().to_pydatetime()


create_db(database, "session_data", "session_log")
populate_session(database,
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
"""
 
