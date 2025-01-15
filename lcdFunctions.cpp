#include "lcdFunctions.h"

// Preprint static text on the LCD
void LCDPrePrint() {
  lcd.setCursor(0, 0);
  lcd.print("Range:");
  lcd.setCursor(14, 0);
  lcd.print("cm");
  lcd.setCursor(0, 1);
  lcd.print("Angle:");
  lcd.setCursor(13, 1);
  lcd.print("deg");
}

// Print distance and angle to the LCD
void printLCDData(int pos, float distance) {
  if (pos >= 0 && distance >= 0) {  // Object is in range
    lcd.setCursor(7, 0);            // go to slot 1
    lcd.print("      ");            // clear slot 1
    lcd.setCursor(7, 0);            // go to slot 1
    lcd.print(distance);            // print range in slot 1
                                    //
    lcd.setCursor(9, 1);            // go to slot 2
    lcd.print("   ");               // clear slot 2
    lcd.setCursor(9, 1);            // go to slot 2
    lcd.print(pos);                 // print angle in slot 2
  } else {                          // No object in range
    lcd.setCursor(7, 0);            // go to slot 1
    lcd.print("XXXXXX");            // Print "XXXXXX" for range
    lcd.setCursor(9, 1);            // go to slot 2
    lcd.print("XXX");               // print "XXX" for angle
  }
}
