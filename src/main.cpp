// Snake
#include <Arduino.h>

#include "LedControl.h"
// #include "snake.h"

// #include "avr8-stub.h"
// #include "app_api.h" // only needed with flash breakpoints

// Create an instance of the LedControl class
//  Pin 12 is connected to the DataIn
//  Pin 10 is connected to the CLK
//  Pin 11 is connected to LOAD(CS)
//  # of devices = 1
LedControl lc = LedControl(12, 10, 11, 1);

void setup()
{
  // initialize GDB stub
  // debug_init();

  // LED Matrix Setup
  // Wakeup call to get the module out of power-saving mode
  lc.shutdown(0, false);
  // Set the brightness to a medium value Range: 0 - 15
  lc.setIntensity(0, 1);
  // Clear the display
  lc.clearDisplay(0);
}

void loop()
{
  // Set the starting position of the snake
  lc.setLed(0, 0, 3, true);
  delay(50);
  lc.setLed(0, 0, 3, false);
  delay(50);
}