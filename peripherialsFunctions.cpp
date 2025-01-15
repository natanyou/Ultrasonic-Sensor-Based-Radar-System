#include "peripherialsFunctions.h"

// buzzer operation function
void buzz(float distance) {
  // Check if the object is in the "warning" range (between thresholdDistance1 and thresholdDistance2)
  if (distance <= thresholdDistance1 && distance > thresholdDistance2) {
    // If the buzzer is not already active and enough time has passed since the last buzz
    if (!isBuzzing && millis() - lastBuzz >= rateRange1) {
      tone(buzzer, freq);           // Turn the buzzer on at the specified frequency
      buzzStart = millis();         // Record the time the buzzer was turned on
      isBuzzing = true;             // Mark the buzzer as active
    }
  } 
  
  // Check if the object is in the "critical" range (below thresholdDistance2)
  else if (distance <= thresholdDistance2) {
    // If the buzzer is not already active and enough time has passed since the last buzz
    if (!isBuzzing && millis() - lastBuzz >= rateRange2) {
      tone(buzzer, freq);           // Turn the buzzer on at the specified frequency
      buzzStart = millis();         // Record the time the buzzer was turned on
      isBuzzing = true;             // Mark the buzzer as active
    }
  }

  // Check if the buzzer has been on for longer than `singleBuzzTime`
  if (isBuzzing && millis() - buzzStart >= singleBuzzTime) {
    noTone(buzzer);                 // Turn the buzzer off
    lastBuzz = millis();            // Update the last buzz time to the current time
    isBuzzing = false;              // Mark the buzzer as inactive
  }
}
