#ifndef PERIPHERIALS_FUNCTIONS_H
#define PERIPHERIALS_FUNCTIONS_H
#include <Arduino.h>

extern int buzzer;
extern unsigned long lastBuzz;    // time of last buzz
extern unsigned long buzzStart;   // Track when the buzzer started
extern bool isBuzzing;            // Track whether the buzzer is active
extern int rateRange1;            // range 1 buzz rate
extern int rateRange2;            // range 2 buzz rate
extern int freq;                  // buzz sound frequncy
extern int singleBuzzTime;        // duration of a single buzz
extern float distance;            // distance from sensor
extern float thresholdDistance1;  // threshold to warn about target in range 1 (detection)
extern float thresholdDistance2;  // threshold to warn about target in range 2 (critical)
// functions
void buzz(float distance);

#endif