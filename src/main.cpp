// Snake
#include <Arduino.h>

#include "LedControl.h"
#include "snakeSegment.h"
#include "snake.h"
#include "fruit.h"
#include "display.h"

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
// Create an instance of the Fruit class
Fruit fruit = Fruit();
// Create an instance of the Display class
Display display = Display();

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
  SnakeSegment *head = new SnakeSegment(2, 3);
  SnakeSegment *tail_1 = new SnakeSegment(1, 3);
  SnakeSegment *tail_2 = new SnakeSegment(0, 3);
  head->next = tail_1;
  tail_1->next = tail_2;
  tail_2->next = NULL;
  snake.tail.push_back(head);
  snake.tail.push_back(tail_1);
  snake.tail.push_back(tail_2);
  // Setup the default fruit
  fruit.setX(6);
  fruit.setY(3);
}

void loop()
{
  // Move the snake
  snake.moveSnake();
  // Update the display state
  display.updateBoardState(snake, fruit, lc);
  // Add a delay between snake movement
  delay(1000);
}