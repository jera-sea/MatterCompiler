# -*- coding: utf-8 -*-
"""
Created on Sat Apr  7 17:56:35 2018

@author: Jeran
"""
import sqlite3
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from matplotlib import animation


def graphVvsI(database_name):

    try:
        plt.style.use('ggplot')
        
        
        con = sqlite3.connect(database_name)
        
        with con:
            #select last 100 lines from session_log table within the database
            sql = ('SELECT * '
                   'FROM session_log ')
            df = pd.read_sql_query(sql, con)
            
        #df = df.set_index(pd.DatetimeIndex(df['time']))
    
        df.index = df.index/1000
        plotFrame = df[['oe_voltage', 'oe_current']].copy()
        plotFrame = plotFrame[plotFrame.oe_current < 5000]
        plotFrame = plotFrame[plotFrame.oe_voltage < 60]
        
        
        #gct().autofmt_xdate() 
        
        fig = plt.figure()
        ax1 = plt.axes()
        ax2 = ax1.twinx()
        line_i, = ax1.plot(plotFrame.index, plotFrame.oe_voltage, lw=5, color='b')
        line_v, = ax2.plot(plotFrame.index, plotFrame.oe_current, lw=2, color='r')
        ax2.set_ylabel('Current (mA)', color='r') #label axis and give the line a colour
        ax2.tick_params('y', colors='r') #make tick markers match line
        ax1.set_ylabel('Voltage (V)', color='b')
        ax1.tick_params('y', colors='b')
        ax1.set_xlabel('Time (s)')
        #fig.tight_layout()
        
        plt.title("current and voltage vs time")
        
        plt.show()
    except:
        print("failed to graph")
    
    return
