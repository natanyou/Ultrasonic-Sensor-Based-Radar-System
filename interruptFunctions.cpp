#include "interruptFunctions.h"

// button interruption service routine
void buttonISR() {
  if (millis() - lastISR > debounceTime) {  // if enough time passed since last interrupt
    onMode = !onMode;                       // toggle on mode
  }                                         //
  lastISR = millis();                       //update last interrupt time
  Serial.println(onMode);
}

// mode change interruption service routine
void opModeISR() {
  if (onMode) {                               // change operation mode only if the radar is on
    if (millis() - lastISR > debounceTime) {  // if enough time passed since last interrupt
      opMode = (opMode + 1) % 6;              // increment mode or reset to 0 (possible modes: 0-5)
      lastISR = millis();                     //update last interrupt time
      Serial.println(opMode);                 // print opMode to the serial screen
    }
  }
}