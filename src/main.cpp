// Snake
#include <Arduino.h>

#include "LedControl.h"
#include "snakeSegment.h"
#include "snake.h"

// #include "avr8-stub.h"
// #include "app_api.h" // only needed with flash breakpoints

// Create an instance of the LedControl class
//  Pin 12 is connected to the DataIn
//  Pin 10 is connected to the CLK
//  Pin 11 is connected to LOAD(CS)
//  # of devices = 1
LedControl lc = LedControl(12, 10, 11, 1);
// Create an instance of the Snake class
Snake snake = Snake(2);

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
  // Begin Serial Monitor
  Serial.begin(115200);
  // Setup the default snake (Head and 1 Tail Segment)
  snake.tail.setStorage(snake.storage_array); // Setup the SnakeSegment storage array
  SnakeSegment tail_1 = SnakeSegment(0, 3, NULL);
  SnakeSegment head = SnakeSegment(1, 3, &tail_1);
  Serial.print(snake.tail.size());
  snake.tail.push_back(head);
  Serial.print(snake.tail.size());
  snake.tail.push_back(tail_1);
  Serial.print(snake.tail.size());
}

void loop()
{
  // Set the starting position of the snake
  for (int i = 0; i < snake.tail.size(); i++)
  {
    // Print snake segment
    lc.setLed(0, snake.tail.at(i).getX(), snake.tail.at(i).getY(), true);
    delay(50);
  }
}