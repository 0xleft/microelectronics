#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,10,11,4);

int displayCount = 4;

void setup() {
  for (int i = 0; i < displayCount; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i,15);
    lc.clearDisplay(i);
  }
}

void loop() {
  lc.setLed(0, 2, 2, true);
}