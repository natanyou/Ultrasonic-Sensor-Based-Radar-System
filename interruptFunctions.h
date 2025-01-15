#ifndef INTERRUPT_FUNCTIONS_H
#define INTERRUPT_FUNCTIONS_H
#include <Arduino.h>

extern volatile unsigned long lastISR;  // last interrupt time
extern volatile bool onMode;            // import onMode
extern volatile int opMode;             // import opMode
extern int debounceTime;                // import time to debounce

// functions
void buttonISR();
void opModeISR();
#endif