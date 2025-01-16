import serial                       # import (py)serial for serial communication with arduino
import matplotlib.pyplot as plt     # import pyplot for ploting the radar display
import numpy as np                  # import numpy for mathematical operations
import time                         # import time to introduce delay where needed

# set up serial portcommunication
ser = serial.Serial('COM8', 9600, timeout=1)    # set serial connection with arduino using the corresponding port
time.sleep(2)                                   # introduce a small delay for clean communication

# set up radar display
fig, ax = plt.subplots(subplot_kw={'projection': 'polar'})      # plot a polar graph for radar display


# Customize the figure's background and styling
fig.patch.set_facecolor("black")                  # Set the figure background to black
ax.set_facecolor((0.1, 0.1, 0.1))                         # Set the polar plot's background to black
ax.grid(color="gray", linestyle="--", linewidth=0.5)  # Customize grid appearance
ax.spines['polar'].set_color("white")            # Set the color of the polar axis
ax.tick_params(colors="white")                   # Set tick colors to white
ax.set_title("Radar Display", color="white", fontsize=16)  # Add a title with white color



angle_dist = [0,0]                                              # initialize readings data array for future use
maxDist = 50                                                    # detection range

while True:                                                             # read continuesly
    # if the radar is in onMode, save the reading (it is valid), else keep scatter point at the center
    angle_dist = [0,0] if angle_dist[0] == '' else ser.readline().decode('utf-8').strip().split(',')   

    print(angle_dist)                                                                                       # print angle and distance 
    if len(angle_dist) < 2:                                                                                 # if an invalid reading was taken (usually in offMode)
        angle_dist = [0,0]                                                                                  # keep scatter point at the center (if took invalid reading in offMode or no object is in range)
    angle = float(angle_dist[0])                                                                            # take angle value
    dist = float(angle_dist[1]) if float(angle_dist[1]) >=0 else 0                                          # take distance value if an object is in detection range, else keep scatter point at the center 
    ax.clear()                                                                                              # clear previous scatter point
    ax.plot([angle * np.pi / 180, angle * np.pi / 180], [0,maxDist], color = "g")
    if dist > 0:                                                                                            # only print valid readings
        ax.plot([angle * np.pi / 180, angle * np.pi / 180], [dist,maxDist], color = "r",linewidth =2 )      # print scatter point (with conversion to radians)
    ax.set_rmax(maxDist)                                                                                    # maximum radial delimiter for clarity
    ax.set_thetamax(180)                                                                                    # delimit to semi circle
    plt.pause(0.1)                                                                                          # pause between subsequent plots