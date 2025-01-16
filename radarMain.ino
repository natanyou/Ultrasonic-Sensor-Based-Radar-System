// inclusions
#include <Servo.h>          // include the servo library
#include <LiquidCrystal.h>  // include LCD library
#include <avr/sleep.h>
#include "lcdFunctions.h"
#include "radarFunctions.h"
#include "interruptFunctions.h"
#include "peripherialsFunctions.h"
#define LCDPowPin A5

// variables and constants
// pins
int servoPin = 13;                                    // define the servo pin
int buttonPin = 2;                                    // define button pin (on/off)
int opModePin = 3;                                    // define button pin (operation mode)
int trig = 12;                                        // trig pin
int echo = 11;                                        // echo pin
int buzzer = 4;                                       // buzzer pin
int rs = 10, en = 9, d4 = 8, d5 = 7, d6 = 6, d7 = 5;  // LCD pins

// servo
Servo radarServo;  // define servo object for radar servo
int posTime = 50;  // define time to remain in position at each agnle

// buttons
volatile boolean onMode = false;     // on/off state
volatile int opMode = 0;             // 0: sweep, opMode = 1,2,3,4: pos = opMode * incrementDeg (45 deg)
volatile unsigned long lastISR = 0;  // time since last ISR
int incrementDeg = 45;               // position incrementation
int debounceTime = 50;               // dbounce time for the buttons

// ultrasonic sensor
float distance;                 // distance from sensor
float thresholdDistance1 = 50;  // threshold to warn about target in range 1 (detection)
float thresholdDistance2 = 10;  // threshold to warn about target in range 2 (critical)
unsigned long lastPrint = 0;    // save last print time
int printInterval = 100;        // time between prints

// buzzer
unsigned long buzzStart = 0;  // Track when the buzzer started
bool isBuzzing = false;       // Track whether the buzzer is active
unsigned long lastBuzz = 0;   // time of last buzz
int rateRange1 = 500;         // range 1 buzz rate
int rateRange2 = 10;          // range 2 buzz rate
int freq = 400;               // buzz sound frequncy
int singleBuzzTime = 20;      // duration of a single buzz

// LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // initialize LCD

//----------------------------------------------------------------------------------------------------------------------------------//

void setup() {
  Serial.begin(9600);                                                    // begin serial communication
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, RISING);  // attach interrupt to button pin (on/off mode)
  attachInterrupt(digitalPinToInterrupt(opModePin), opModeISR, RISING);  // attach interrupt to button pin (operation mode)

  // set pins
  pinMode(buttonPin, INPUT);    // set the interrupt pin as input
  pinMode(trig, OUTPUT);        // set trig pin as output
  pinMode(echo, INPUT);         // set echo pin as input
  pinMode(buzzer, OUTPUT);      // set buzzer pin as output
  radarServo.attach(servoPin);  // attach servo pin to the radar servo

  // LCD inital values
  lcd.begin(16, 2);  //
  LCDPrePrint();     // pre prints for LCD
}

void loop() {

  // sleep mode management
  if (!onMode) {                      // if off
    noTone(buzzer);                   // disable buzeer to avoid buzzing in off mode
    set_sleep_mode(SLEEP_MODE_IDLE);  // set to power-down sleep mode (lowest power consumption)
    sleep_enable();                   // enable sleep mode
    sleep_mode();                     // enter sleep mode (microcontroller)
  } else {                            // if on
    sleep_disable();                  // Disable sleep mode after waking uplcd.noDisplay();
  }
  

  if (onMode) {                               // if on
    if (opMode == 0) {                        // if opMode is sweep
      for (int pos = 0; pos <= 180; pos++) {  // from 0 to 180 degrees (ccw)
        if (!onMode || opMode != 0) {         // if an interruption happend
          break;                              //
        }                                     //
        driveRadar(pos);                      // rotate radar and take readings
        buzz(distance);                       // buzz according to distance
      }

      for (int pos = 180; pos >= 0; pos--) {  // from 180 to 0 degrees (cw)
        if (!onMode || opMode != 0) {         // if an interruption happend
          break;                              //
        }                                     //
        driveRadar(pos);                      // rotate radar and take readings
        buzz(distance);                       // buzz according to distance
      }
    } else {
      int pos = (opMode - 1) * incrementDeg;
      driveRadar(pos);  // rotate radar and take readings
      buzz(distance);   // buzz according to distance
    }
  }
}
