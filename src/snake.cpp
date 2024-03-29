#include <Arduino.h>

#include "snake.h"
#include "snakeSegment.h"
#include "display.h"

// Constructor Function Definition
Snake::Snake()
{
}

// Function: popBack()
void Snake::popBack()
{
    SnakeSegment *temp = head;
    // Check if the head is null
    if (head == NULL)
    {
        return; // Exit
    }
    // Loop through the segments
    while (temp->next->next != NULL)
    {
        // Cycle through to the next segment
        temp = temp->next;
    }
    // Pop the last segment off
    temp->next = NULL;
}
// Function: pushFront()
void Snake::pushFront(int x, int y)
{
    // Create a new head node
    SnakeSegment *newHead = new SnakeSegment(x, y);
    // Set the next node to the previous head
    newHead->next = head;
    // Replace the head
    head = newHead;
}
// Function: pushBack()
void Snake::pushBack(int x, int y)
{
    // Create a new node
    SnakeSegment *newNode = new SnakeSegment(x, y);
    // Check if the head is NULL
    if (head == NULL)
    {
        // Set the new node as the head
        head = newNode;
        return;
    }
    // Create a temp node to cycle with
    SnakeSegment *temp = head;
    // Cycle through to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Update the last node to point to the new node
    temp->next = newNode;
}
// Function: moveSnake()
bool Snake::moveSnake(Fruit *fruit)
{
    // Initialise new head position with old head position
    int newHeadX = head->getX();
    int newHeadY = head->getY();
    // Set the values of the new head's position based off of the current direction
    switch (direction)
    {
    case UP:
        if (newHeadX + 1 > maxRows - 1)
        {
            newHeadX = 0;
        }
        else
        {
            newHeadX += 1;
        }
        break;
    case DOWN:
        if (newHeadX - 1 < 0)
        {
            newHeadX = maxRows - 1;
        }
        else
        {
            newHeadX -= 1;
        }
        break;
    case LEFT:
        if (newHeadY - 1 < 0)
        {
            newHeadY = maxCols - 1;
        }
        else
        {
            newHeadY -= 1;
        }
        break;
    case RIGHT:
        if (newHeadY + 1 > (maxCols - 1))
        {
            newHeadY = 0;
        }
        else
        {
            newHeadY += 1;
        }
        break;
    default:
        break;
    }
    // Check to see if the snake hit itself
    SnakeSegment *temp = head;
    while (temp != NULL)
    {
        if (newHeadX == temp->getX() && newHeadY == temp->getY())
        {
            // Snake hit itself
            return false;
        }
        temp = temp->next;
    }
    // Add the new snake head to the front of the snake segment tail
    this->pushFront(newHeadX, newHeadY);
    // Check if the snake ate the fruit
    if (newHeadX == fruit->getX() && newHeadY == fruit->getY())
    {
        // Update the fruit to have a new position
        fruit->setX(random(0, maxRows));
        fruit->setY(random(0, maxCols));
        // Return before popping the last tail segment to simulate tail growth
        return true;
    }
    // Pop the last tail segment
    this->popBack();
    return true;
};

void Snake::reset()
{
    while (head->next->next->next != NULL)
    {
        this->popBack();
    }
    head->setX(5);
    head->setY(3);
    head->next->setX(6);
    head->next->setY(3);
    head->next->next->setX(7);
    head->next->next->setY(3);
    // Reset the direction of the snake
    direction = DOWN;
}