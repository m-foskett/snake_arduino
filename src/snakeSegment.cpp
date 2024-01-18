#include <Arduino.h>

#include "snakeSegment.h"

// Constructor Function Definition
SnakeSegment::SnakeSegment(){

};

SnakeSegment::SnakeSegment(int x, int y)
    : m_x{x},
      m_y{y}
{
}

// void Snake::drawSnake(){

// };