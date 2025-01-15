#ifndef LCD_FUNCTIONS_H
#define LCD_FUNCTIONS_H

#include <LiquidCrystal.h>

// Declare the `lcd` object as external to be shared across files
extern LiquidCrystal lcd;

// Function prototypes
void LCDPrePrint();
void printLCDData(int pos, float distance);

#endif // LCD_FUNCTIONS_H
