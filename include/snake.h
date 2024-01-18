#ifndef SNAKE_H
#define SNAKE_H

#include <Vector.h>
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
    int m_snakeLength{2};

public:
    direction direction{UP};
    SnakeSegment *storage_array[maxSnakeLength];
    Vector<SnakeSegment *> tail; // Dynamic Container
    // Constructor Function Declaration
    Snake(int snakeLength);
    // Member Function Declarations
    void moveSnake();
    // void AddTailSegment();
    // Access Function Definitions
    int getSnakeLength() const { return m_snakeLength; }                  // getter for snakeLength
    void setSnakeLength(int snakeLength) { m_snakeLength = snakeLength; } // setter for snakeLength
};

#endif