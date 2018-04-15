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
ax = plt.axes()
line, = ax.plot([], [], lw=2)



# initialization function: plot the background of each frame
def init():
    try:
        con = sqlite3.connect('1.db')
    except:
        return line,
    with con:
        df = pd.read_sql_query("SELECT * FROM session_log", con)
        line.set_data(df['oe_voltage'].values, df['oe_current'].values)
        ax.relim()
        ax.autoscale_view()
    return line,

# animation function.  This is called sequentially
def animate(i):
    try:
        con = sqlite3.connect('1.db')
    except:
        return line,
    with con:
        #select last 100 lines from session_log table within the database
        sql = ('SELECT * '
               'FROM session_log '
               'LIMIT 100 '
               'OFFSET (SELECT COUNT(*) FROM session_log)-100')
        df = pd.read_sql_query(sql, con) 
        
        line.set_data(df['oe_voltage'].values, df['oe_current'].values)
        ax.relim()
        ax.autoscale_view()
    return line, 

# call the animator.  blit=True means only re-draw the parts that have changed BUT ONLY WITHIN A BOX BOUNDED BY THE AXIS LINES.
anim = animation.FuncAnimation(fig, animate, init_func=init,
                               frames=200, interval=200)

# save the animation as an mp4.  This requires ffmpeg or mencoder to be
# installed.  The extra_args ensure that the x264 codec is used, so that
# the video can be embedded in html5.  You may need to adjust this for
# your system: for more information, see
# http://matplotlib.sourceforge.net/api/animation_api.html
#anim.save('basic_animation.mp4', fps=30, extra_args=['-vcodec', 'libx264'])

plt.show()