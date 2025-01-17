This project is a radar system with an ultrasonic sensor and servo motor, supporting sweep
and static degree select modes. real-time distance and angle measurements
displayed on an LCD. Optimized for low power consumption with sleep modes and
efficient interrupts. Includes a Python-based GUI to visualize radar data, taken in real 
time via serial communication, simulating a radar-like interface.

Project is separted into several files, with the main file being radarMain.ino, 
which drives the radar and handles sleep mode. Other files include various 
functions, interrupts service routines (ISRs) which are used to operate the
radar and take readings, and the radar display interface.

Further improvements will be added, such as more functionalities and further
optimization.

Things that could be improved:
1. Smoothning the servo motor rotaion when to toggling on mode or operation mode;
2. Figuring out how to quicly reanble LCD after toggling on mode (current reinitialization
takes to long, can't figure out why, currently the LCD stays on even when the microcontroller
is asleep during off MODE).
