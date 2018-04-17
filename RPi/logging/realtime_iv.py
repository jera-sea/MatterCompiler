# -*- coding: utf-8 -*-
"""
Graphing Code which updates directly from the database and maintains a live graph of the process

@author: Jeran
"""
import sqlite3
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from matplotlib import animation

# First set up the figure, the axis, and the plot element we want to animate
fig = plt.figure()
ax1 = plt.axes()
ax2 = ax1.twinx()
line_i, = ax1.plot([], [], lw=5, color='b')
line_v, = ax2.plot([], [], lw=2, color='r')
ax2.set_ylabel('Voltage (V)', color='r') #label axis and give the line a colour
ax2.tick_params('y', colors='r') #make tick markers match line
ax1.set_ylabel('Current (mA)', color='b')
ax1.tick_params('y', colors='b')
fig.tight_layout()

# initialization function: plot the background of each frame
def init():
    try:
        con = sqlite3.connect('1.db') #connect to db as read only
    except:
        return line_i, line_v
    with con:
        df = pd.read_sql_query("SELECT * FROM session_log", con)

        line_v.set_data(pd.to_datetime(df['time']), df['oe_voltage'].values)
        line_i.set_data(pd.to_datetime(df['time']), df['oe_current'].values)
        ax1.relim()
        ax1.autoscale_view()
        ax2.relim()
        ax2.autoscale_view()
    return line_i, line_v

# animation function.  This is called sequentially
def animate(i):
    try:
        con = sqlite3.connect('1.db')
    except:
        return line_i, line_v
    with con:
        #select last 100 lines from session_log table within the database
        sql = ('SELECT * '
               'FROM session_log '
               'LIMIT 500 '
               'OFFSET (SELECT COUNT(*) FROM session_log)-500')
        df = pd.read_sql_query(sql, con) 
        
        line_v.set_data(pd.to_datetime(df['time']), df['oe_voltage'].values)
        line_i.set_data(pd.to_datetime(df['time']), df['oe_current'].values)
        ax1.relim()
        ax1.autoscale_view()
        ax2.relim()
        ax2.autoscale_view()
    return line_i, line_v

# call the animator.  blit=True means only re-draw the parts that have changed BUT ONLY WITHIN A BOX BOUNDED BY THE AXIS LINES.
anim = animation.FuncAnimation(fig, animate, init_func=init,
                               frames=200, interval=1000)

# save the animation as an mp4.  This requires ffmpeg or mencoder to be
# installed.  The extra_args ensure that the x264 codec is used, so that
# the video can be embedded in html5.  You may need to adjust this for
# your system: for more information, see
# http://matplotlib.sourceforge.net/api/animation_api.html
#anim.save('basic_animation.mp4', fps=30, extra_args=['-vcodec', 'libx264'])

plt.show()