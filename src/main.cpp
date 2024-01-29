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
  snake->pushBack(5, 3);
  snake->pushBack(6, 3);
  snake->pushBack(7, 3);

  // Setup the default fruit
  fruit->setX(1);
  fruit->setY(3);
  // Acquire the default center values of the joystick
  joystick.getCentreValues();
}

void loop()
{
  // While the game is to be continued
  while (joystick.continueGame)
  {
    // Move the snake
    joystick.continueGame = snake->moveSnake(fruit);
    // Update the display state
    display.updateBoardState(snake, fruit, lc);
    // Get user input
    joystick.getDirection(snake);
    // Add a delay between snake movement
    delay(1000);
  }
  // Display the 'GAME OVER' screen
  display.gameOver(lc);
  // If the game was reset by the user
  if (joystick.continueGame)
  {
    // Reset the board state
    display.resetBoardState(lc);
    // Reset the fruit's position
    fruit->setX(1);
    fruit->setY(3);
    // Reset the snake's size to 3 segments and its position to the start
    snake->reset();
  }
}