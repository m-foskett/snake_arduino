#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "snake.h"

// Constants
const int minAnalogReading{0};
const int maxAnalogReading{1024};

class Joystick
{
private:
    // VRX Pin
    int VR_X;
    // VRY Pin
    int VR_Y;
    // SW (Switch) Pin
    int SW;
    // Static Member Function and Pointer used for Interrupt Service Routine
    //  - Declared as static as the address of the function must be known at compile time for attachInterrupt to work
    void (*localPointerToCallback)(const int);
    // static Joystick *sJoystick;

public:
    volatile bool continueGame;
    int xCenter{0};
    int yCenter{0};
    // Constructor Function Declaration
    Joystick(int xPin, int yPin, int swPin); // Default Constructor
    // Member Function Declarations
    void getDirection(Snake *snake);
    void getCentreValues();
    void playAgain();
    void joystickISR(void);
};

#endif