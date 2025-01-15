This project is a work in progress.
It is a radar system with an ultrasonic sensor and servo motor, supporting sweep
and static degree select modes. real-time distance and angle measurements
displayed on an LCD. Optimized for low power consumption with sleep modes and
efficient interrupts. A Python-based GUI to visualize radar data, simulating a
radar-like interface, will be included in the future.

Project is separted into several files, with the main file being radarMain.ino, 
which drives the radar and handles sleep mode. Other files include various 
functions and interrupts service routines (ISRs) which are used to operate the
radar and take readings.

Further work will be done in the future, adding more functionalities and further
optimization.
