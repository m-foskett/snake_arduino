#ifndef SNAKE_H
#define SNAKE_H

#include "snakeSegment.h"
#include "fruit.h"

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
    direction direction{DOWN};
    // Constructor Function Declaration
    Snake();
    // Member Function Declarations
    bool moveSnake(Fruit *fruit);
    void popBack();
    void pushFront(int x, int y);
    void pushBack(int x, int y);
    void reset();
    // Access Function Definitions
};

#endif