#include <Arduino.h>

#include "joystick.h"
#include "snake.h"

// Constructor Function Definition
Joystick::Joystick(int xPin, int yPin, int swPin)
{
    VR_X = xPin;
    VR_Y = yPin;
    SW = swPin;

    // Set the switch pin to INPUT
    pinMode(SW, INPUT);
    // Write HIGH to the switch pin for pull-up resistor
    digitalWrite(SW, HIGH);
}
//
void Joystick::getDirection(Snake *snake)
{
    int xReading;
    int yReading;
    int variance = 25;
    // Read the X-axis analog input
    xReading = analogRead(VR_X);
    // Read the Y-axis analog input
    yReading = analogRead(VR_Y);

    // Determine direction from user input
    if (xReading < variance && yReading > (maxAnalogReading / 2 - variance) && yReading < (maxAnalogReading / 2 + variance))
    {
        snake->direction = LEFT;
    }
};