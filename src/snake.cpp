#include <Arduino.h>

#include "snake.h"
#include "snakeSegment.h"
#include "display.h"

// Constructor Function Definition
Snake::Snake(int snakeLength)
    : m_snakeLength{snakeLength}
{
}

void Snake::moveSnake()
{
    // New Snake Head
    SnakeSegment *head = tail.front();
    // Point the new snake head to the previous snake head
    head->next = tail.front();
    // Position the new snake head based on the current direction
    int newHeadX = tail.front()->getX();
    int newHeadY = tail.front()->getY();
    switch (direction)
    {
    case UP:
        if (newHeadX + 1 > maxRows - 1)
        {
            head->setX(0);
        }
        else
        {
            head->setX(newHeadX + 1);
        }
        break;
    case DOWN:
        if (newHeadX - 1 < 0)
        {
            head->setX(maxRows - 1);
        }
        else
        {
            head->setX(newHeadX - 1);
        }
        break;
    case LEFT:
        if (newHeadY - 1 < 0)
        {
            head->setY(maxCols - 1);
        }
        else
        {
            head->setY(newHeadY - 1);
        }
        break;
    case RIGHT:
        if (newHeadY + 1 > (maxCols - 1))
        {
            head->setY(0);
        }
        else
        {
            head->setY(newHeadY + 1);
        }
        break;
    default:
        break;
    }
    // Add the new snake head to the front of the snake segment tail
    // tail.front() = head;
    // Pop the tail segment
    // tail.pop_back();
};