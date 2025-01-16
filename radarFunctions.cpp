#include "radarFunctions.h"

// trigger ultrasonic sensor pulse
void sendTrigPulse() {       // signals the ultrasonic sensor to begin
  digitalWrite(trig, LOW);   // begin from low
  delayMicroseconds(2);      // delaay for clean signal
  digitalWrite(trig, HIGH);  // send high pulse
  delayMicroseconds(10);     // pulse width
  digitalWrite(trig, LOW);   // lower signal back
}

// return distance from readings function
float returnDistance() {
  long duration = pulseIn(echo, HIGH);     // measure high signal on echo duration
  float distance = duration * 0.0344 / 2;  // calculate distance in air
  return distance;
} 

// print distance and angle to serial monitor
void printSerialData(int pos, float distance) {
  // Serial.print("Angle: ");                       //
  Serial.print(pos);  // print angle
  // Serial.print("° position: ");                  //
  Serial.print(",");
  Serial.println(distance);  // print distance
}

void driveRadar(int pos) {      // operate the radar
  radarServo.write(pos);        // move to requsted angle
  sendTrigPulse();              // send trigger signal
  distance = returnDistance();  // return distance of object
  delay(posTime);               // wait at this angle for some time
  // print angle and position
  if (millis() - lastPrint >= printInterval && distance <= thresholdDistance1) {        // if an object is in range
    printSerialData(pos, distance);                                                    // print distance and angle to serial monitor
    printLCDData(pos, distance);                                                       // print distance and angle to LCD
    lastPrint = millis();                                                              // update time since last print
  } else if (millis() - lastPrint >= printInterval && distance > thresholdDistance1) {  // if no object is in range
    printSerialData(pos, -1);                                                           // call function with (-1, -1) to print X's
    printLCDData(pos, -1);                                                              // call function with (-1, -1) to print X's
    lastPrint = millis();                                                              // update time since last print
  }
}