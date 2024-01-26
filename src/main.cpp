// Snake
#include <Arduino.h>

#include "LedControl.h"
#include "joystick.h"
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
// Create an instance of the Joystick class
Joystick joystick = Joystick(0, 1, 2);
// Create an instance of the Snake class
Snake *snake = new Snake();
// Create an instance of the Fruit class
Fruit *fruit = new Fruit();
// Create an instance of the Display class
Display display = Display();

// Game State
// true - Normal
// false - Game Over
bool continueGame = true;

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
  snake->pushBack(2, 3);
  snake->pushBack(1, 3);
  snake->pushBack(0, 3);

  // Setup the default fruit
  fruit->setX(6);
  fruit->setY(3);
  // Acquire the default center values of the joystick
  joystick.getCentreValues();
}

void loop()
{
  while (continueGame)
  {
    // Serial.print(snake.tail.size());
    // Move the snake
    continueGame = snake->moveSnake(fruit);
    // Update the display state
    display.updateBoardState(snake, fruit, lc);
    // Get user input
    joystick.getDirection(snake);
    // Add a delay between snake movement
    delay(1000);
  }
  display.gameOver(lc);
  delay(5000);
}