#ifndef SNAKE_H
#define SNAKE_H

#include "snakeSegment.h"

// Constants
const int maxSnakeLength{64};

enum direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// Snake Class
class Snake
{
private:
public:
    SnakeSegment *head{NULL};
    direction direction{UP};
    // Constructor Function Declaration
    Snake();
    // Member Function Declarations
    void moveSnake();
    void popBack();
    void pushFront(int x, int y);
    void pushBack(int x, int y);
    // Access Function Definitions
};

#endif