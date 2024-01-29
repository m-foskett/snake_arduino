#include <Arduino.h>

#include "display.h"
#include "fruit.h"
#include "snake.h"
#include "LedControl.h"

// GAME OVER Byte Patterns
byte g_Bytes[8] = {
    B00000000,
    B01111110,
    B01000000,
    B01001110,
    B01000010,
    B01000010,
    B01111110,
    B00000000};
byte a_Bytes[8] = {
    B00000000,
    B00011000,
    B00100100,
    B01100110,
    B01111110,
    B01000010,
    B01000010,
    B00000000};
byte m_Bytes[8] = {
    B00000000,
    B01000010,
    B01100110,
    B01011010,
    B01011010,
    B01000010,
    B01000010,
    B00000000};
byte e_Bytes[8] = {
    B00000000,
    B01111110,
    B01000000,
    B01111110,
    B01111110,
    B01000000,
    B01111110,
    B00000000};
byte o_Bytes[8] = {
    B00000000,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01111110,
    B00000000};
byte v_Bytes[8] = {
    B00000000,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00100100,
    B00011000,
    B00000000};
byte r_Bytes[8] = {
    B00000000,
    B01111100,
    B01000010,
    B01000010,
    B01111100,
    B01001000,
    B01000100,
    B00000000};
// Byte Array to keep track of currently displayed pattern
byte currentPattern[8] = {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000};

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

// Function: resetBoardState(LedControl lc)
void Display::resetBoardState(LedControl lc)
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
}

void Display::updateBoardState(Snake *snake, Fruit *fruit, LedControl lc)
{
    // Clear board
    resetBoardState(lc);
    // Loop through snake segments
    SnakeSegment *temp = snake->head;
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
    }
};

byte *Display::updatePattern(byte *patternToUpdate, byte patternToInsert[], LedControl lc)
{
    // For each bit of the byte pattern
    for (int i = 0; i < maxCols; i++)
    {
        // Display the current byte pattern
        for (int j = 0; j < maxRows; j++)
        {
            // Set the current row's LED byte pattern
            lc.setRow(0, j, patternToUpdate[j]);
            // Left shift each row by 1 bit (adds a 0 as the LSB)
            patternToUpdate[j] = patternToUpdate[j] << 1;
            // Insert the next bit of the new letter pattern
            patternToUpdate[j] |= (patternToInsert[j] >> (7 - i));
        }
        delay(100);
    }
    return patternToUpdate;
}

void Display::gameOver(LedControl lc)
{
    // Display 'GAME OVER'
    byte currentPattern[8] = {
        B00000000,
        B00000000,
        B00000000,
        B00000000,
        B00000000,
        B00000000,
        B00000000};
    byte *current = currentPattern;
    current = updatePattern(current, g_Bytes, lc);
    current = updatePattern(current, a_Bytes, lc);
    current = updatePattern(current, m_Bytes, lc);
    current = updatePattern(current, e_Bytes, lc);
    current = updatePattern(current, o_Bytes, lc);
    current = updatePattern(current, v_Bytes, lc);
    current = updatePattern(current, e_Bytes, lc);
    current = updatePattern(current, r_Bytes, lc);
}