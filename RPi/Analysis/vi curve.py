# -*- coding: utf-8 -*-
"""
Created on Thu Apr 19 23:51:04 2018

@author: Jeran
"""
import sqlite3
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from matplotlib import animation


plt.style.use('ggplot')


con = sqlite3.connect('s1i4.db')

with con:
    #select last 100 lines from session_log table within the database
    sql = ('SELECT * '
           'FROM session_log ')
    df = pd.read_sql_query(sql, con)
    
#df = df.set_index(pd.DatetimeIndex(df['time']))
#df = df.set_index(df.ie_current)
plotFrame = df[['oe_current', 'oe_voltage']].copy()
plotFrame = plotFrame[plotFrame.oe_current < 400]
plotFrame.oe_current = plotFrame.oe_current.rolling(window = 10).mean()
plotFrame = plotFrame[plotFrame.oe_voltage < 3]
#plotFrame = plotFrame[plotFrame.oe_voltage > 2]
plotFrame = plotFrame.reset_index()
negFrame = plotFrame.iloc[96:]
negFrame = negFrame.iloc[::-1]
negFrame = negFrame.reset_index()

plotFrame = plotFrame.iloc[:96]
#plotFrame = pd.concat([plotFrame, negFrame])
print(negFrame.index)
#plotFrame = plotFrame.reindex(index = list(range(0, len(plotFrame.index))))
#print(plotFrame.index)

#gct().autofmt_xdate() 

fig = plt.figure()
ax1 = plt.axes()
line_i, = ax1.plot(plotFrame.oe_voltage, plotFrame.oe_current, lw=2, color='m')
line_v, = ax1.plot(negFrame.oe_voltage, negFrame.oe_current, lw=2, color='g')
#ax2.set_ylabel('Voltage (V)', color='r') #label axis and give the line a colour
ax1.set_ylabel('Current (mA)')
ax1.set_xlabel('Voltage (V)')
#fig.tight_layout()
plt.legend([line_i, line_v], ["Positive Sweep", "negative sweep"])
plt.title("voltage vs current (potentiodynamic sweep)")
plt.show()

#print(df.index)
        