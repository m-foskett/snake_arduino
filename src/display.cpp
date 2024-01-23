#include <Arduino.h>

#include "display.h"
#include "fruit.h"
#include "snake.h"
#include "LedControl.h"

// GAME OVER Patterns
bool g_pattern[maxRows][maxCols] = {
    {false, false, false, false, false, false, false, false},
    {false, true, true, true, true, true, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, true, true, true, false},
    {false, true, false, false, false, false, false, false},
    {false, true, true, true, true, true, true, false},
    {false, false, false, false, false, false, false, false}};
bool a_pattern[maxRows][maxCols] = {
    {false, false, false, false, false, false, false, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, true, true, true, true, true, false},
    {false, true, true, false, false, true, true, false},
    {false, false, true, false, false, true, false, false},
    {false, false, false, true, true, false, false, false},
    {false, false, false, false, false, false, false, false}};
bool m_pattern[maxRows][maxCols] = {
    {false, false, false, false, false, false, false, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, true, true, false, true, false},
    {false, true, false, true, true, false, true, false},
    {false, true, true, false, false, true, true, false},
    {false, true, false, false, false, false, true, false},
    {false, false, false, false, false, false, false, false}};
bool e_pattern[maxRows][maxCols] = {
    {false, false, false, false, false, false, false, false},
    {false, true, true, true, true, true, true, false},
    {false, true, false, false, false, false, false, false},
    {false, true, true, true, true, true, true, false},
    {false, true, true, true, true, true, true, false},
    {false, true, false, false, false, false, false, false},
    {false, true, true, true, true, true, true, false},
    {false, false, false, false, false, false, false, false}};
bool o_pattern[maxRows][maxCols] = {
    {false, false, false, false, false, false, false, false},
    {false, true, true, true, true, true, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, true, true, true, true, true, false},
    {false, false, false, false, false, false, false, false}};
bool v_pattern[maxRows][maxCols] = {
    {false, false, false, false, false, false, false, false},
    {false, false, false, true, true, false, false, false},
    {false, false, true, false, false, true, false, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, true, false},
    {false, false, false, false, false, false, false, false}};
bool r_pattern[maxRows][maxCols] = {
    {false, false, false, false, false, false, false, false},
    {false, true, false, false, false, true, false, false},
    {false, true, false, false, true, false, false, false},
    {false, true, true, true, true, true, false, false},
    {false, true, false, false, false, false, true, false},
    {false, true, false, false, false, false, true, false},
    {false, true, true, true, true, true, false, false},
    {false, false, false, false, false, false, false, false}};

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

void Display::updateBoardState(Snake snake, Fruit *fruit, LedControl lc)
{
    // Clear board
    for (int i = 0; i < maxRows; i++)
    {
        for (int j = 0; j < maxCols; j++)
        {
            board[i][j] = false;
        }
    }
    lc.clearDisplay(0);
    // Loop through snake segments
    SnakeSegment *temp = snake.head;
    while (temp != NULL)
    {
        board[temp->getX()][temp->getY()] = true;
        temp = temp->next;
    }
    // Store fruit location into the 2D board array
    board[fruit->getX()][fruit->getY()] = true;
    // Display the updated board state
    for (int i = 0; i < maxRows; i++)
    {
        // Set the current row's LED byte pattern
        lc.setRow(0, i, Display::BoolArrayToByte(board[i]));
        delay(50);
    }
};

void Display::gameOver(LedControl lc)
{
    // Update board to display GAME screen
    // for (int i = 0; i < maxRows; i++)
    // {
    //     for (int j = 0; j < maxCols; j++)
    //     {

    //         board[i][j] = game[i][j];
    //     }
    // }

    // Display the updated board state
    for (int i = 0; i < maxRows; i++)
    {
        // Set the current row's LED byte pattern
        lc.setRow(0, i, Display::BoolArrayToByte(g_pattern[i]));
        // delay(50);
    }
    delay(500);
    // Display the updated board state
    for (int i = 0; i < maxRows; i++)
    {
        // Set the current row's LED byte pattern
        lc.setRow(0, i, Display::BoolArrayToByte(a_pattern[i]));
        // delay(50);
    }
    delay(500);
    // Display the updated board state
    for (int i = 0; i < maxRows; i++)
    {
        // Set the current row's LED byte pattern
        lc.setRow(0, i, Display::BoolArrayToByte(m_pattern[i]));
        // delay(50);
    }
    delay(500);
    // Display the updated board state
    for (int i = 0; i < maxRows; i++)
    {
        // Set the current row's LED byte pattern
        lc.setRow(0, i, Display::BoolArrayToByte(e_pattern[i]));
        // delay(50);
    }
    delay(500);
    // Display the updated board state
    for (int i = 0; i < maxRows; i++)
    {
        // Set the current row's LED byte pattern
        lc.setRow(0, i, Display::BoolArrayToByte(o_pattern[i]));
        // delay(50);
    }
    delay(500);
    // Display the updated board state
    for (int i = 0; i < maxRows; i++)
    {
        // Set the current row's LED byte pattern
        lc.setRow(0, i, Display::BoolArrayToByte(v_pattern[i]));
        // delay(50);
    }
    delay(500);
    // Display the updated board state
    for (int i = 0; i < maxRows; i++)
    {
        // Set the current row's LED byte pattern
        lc.setRow(0, i, Display::BoolArrayToByte(e_pattern[i]));
        // delay(50);
    }
    delay(500);
    // Display the updated board state
    for (int i = 0; i < maxRows; i++)
    {
        // Set the current row's LED byte pattern
        lc.setRow(0, i, Display::BoolArrayToByte(r_pattern[i]));
        // delay(50);
    }
    delay(500);
}