#ifndef RADAR_FUNCTIONS_H
#define RADAR_FUNCTIONS_H
#include <Arduino.h>
#include "lcdFunctions.h"

#include <Servo.h>
extern int trig;                  // trig pin
extern int echo;                  // echo pin
extern int servoPin;              // define the servo pin
extern float distance;            // distance from sensor
extern float thresholdDistance1;  // threshold to warn about target in range
extern unsigned long lastPrint;   // save last print time
extern int printInterval;         // time between prints
extern Servo radarServo;          // define servo object for radar servo
extern int posTime;               // define time to remain in position at each agnle

// functions
void sendTrigPulse();                           // signals the ultrasonic sensor to begins
float returnDistance();                         // return distance from readings function
void printSerialData(int pos, float distance);  // print distance and angle to serial monitor
void driveRadar(int pos);                       // operate the radar

#endif  // LCD_FUNCTIONS_H