#ifndef DISPLAY_H
#define DISPLAY_H

#include "snake.h"
#include "fruit.h"
#include "LedControl.h"

// Constants
const int maxRows{8};
const int maxCols{8};

// Snake Class
class Display
{
private:
public:
    bool board[maxRows][maxCols]{};
    // Constructor Function Declaration
    Display(); // Default Constructor
    // Member Function Declarations
    void updateBoardState(Snake *snake, Fruit *fruit, LedControl lc);
    void gameOver(LedControl lc);
    unsigned char BoolArrayToByte(bool array[8]);
};

#endif