#ifndef SNAKE_H
#define SNAKE_H

// Snake Class
class Snake
{
private:
    int m_snakeLength{2};
    // std::vector<SnakeSegment>
public:
    // Constructor Function Declaration
    Snake(int snakeLength);
    // Member Function Declarations
    void drawSnake();
    // void AddTailSegment();
    // Access Function Definitions
    int getSnakeLength() const { return m_snakeLength; }                  // getter for snakeLength
    void setSnakeLength(int snakeLength) { m_snakeLength = snakeLength; } // setter for snakeLength
};

// Constants
const int maxSnakeLength{64};

#endif