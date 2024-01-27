#include <Arduino.h>

#include "joystick.h"
#include "snake.h"

// Initialise the static class pointer
Joystick *Joystick::sJoystick{0};
volatile bool Joystick::continueGame;

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
    // Assign current isntance to the pointer
    sJoystick = this;
    // Attach an interrupt service routine to interrrupt vector 0 (pin 2 - SW)
    attachInterrupt(0, Joystick::joystickISR, CHANGE);
}

// Joystick ISR
void Joystick::joystickISR(void)
{
    // If the joystick object has been initialised
    if (sJoystick != 0)
    {
        // Play again
        sJoystick->playAgain();
    }
}

// Member Function: playAgain();
void Joystick::playAgain()
{
    // Set continueGame to true
    Joystick::continueGame = true;
}

//
void Joystick::getDirection(Snake *snake)
{
    int xReading;
    int yReading;
    // Read the X-axis analog input
    xReading = analogRead(VR_X);
    // Read the Y-axis analog input
    yReading = analogRead(VR_Y);

    // Determine direction from user input
    if ((xReading < xCenter + (maxAnalogReading - xCenter) / 2) && (xReading > xCenter / 2) && (yReading < yCenter / 2))
    {
        snake->direction = UP;
    }
    if ((yReading < yCenter + (maxAnalogReading - yCenter) / 2) && (yReading > yCenter / 2) && (xReading < xCenter / 2))
    {
        snake->direction = LEFT;
    }
    // Determine direction from user input
    if ((xReading < xCenter + (maxAnalogReading - xCenter) / 2) && (xReading > xCenter / 2) && (yReading > yCenter + (maxAnalogReading - yCenter) / 2))
    {
        snake->direction = DOWN;
    }
    // Determine direction from user input
    if ((yReading < yCenter + (maxAnalogReading - yCenter) / 2) && (yReading > yCenter / 2) && (xReading > xCenter + (maxAnalogReading - xCenter) / 2))
    {
        snake->direction = RIGHT;
    }
};

void Joystick::getCentreValues()
{
    int samples = 10;
    // Poll the analog values of X and Y multiple times
    for (int i = 0; i < samples; i++)
    {
        xCenter += analogRead(VR_X);
        yCenter += analogRead(VR_Y);
    }
    // Average the X and Y samples to get the centre values
    xCenter = xCenter / samples;
    yCenter = yCenter / samples;
}