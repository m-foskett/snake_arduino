#include <Arduino.h>

#include "display.h"
#include "fruit.h"
#include "snake.h"
#include "LedControl.h"

// Constructor Function Definition
Display::Display()
{
}

byte Display::BoolArrayToByte(bool array[8])
{
    byte b = B00000000;
    for (int i = 0; i < 8; i++)
    {
        if (array[i] == true)
        {
            b |= 1 << i;
        }
    }
    return b;
}

void Display::updateBoardState(Snake snake, Fruit fruit, LedControl lc)
{
    // Loop through snake segments
    for (int i = 0; i < snake.tail.size(); i++)
    {
        // Store snake segment location into the 2D board array
        board[snake.tail.at(i).getX()][snake.tail.at(i).getY()] = true;
    };
    // Store fruit location into the 2D board array
    board[fruit.getX()][fruit.getY()] = true;
    // Display the updated board state
    for (int i = 0; i < maxRows; i++)
    {
        // Set the current row's LED byte pattern
        lc.setRow(0, i, Display::BoolArrayToByte(board[i]));
        delay(50);
    }
};