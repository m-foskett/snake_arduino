#include <Arduino.h>

#include "snakeSegment.h"

// Constructor Function Definition
SnakeSegment::SnakeSegment(){

};

SnakeSegment::SnakeSegment(int x, int y, SnakeSegment *next)
    : m_x{x},
      m_y{y},
      m_next{next}
{
}

// void Snake::drawSnake(){

// };