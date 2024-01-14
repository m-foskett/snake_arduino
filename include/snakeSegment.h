#ifndef SNAKESEGMENT_H
#define SNAKESEGMENT_H

// Snake Segment Class
class SnakeSegment
{
private:
    int m_x{0};
    int m_y{0};
    SnakeSegment *m_next{};

public:
    // Constructor Function Declaration
    // SnakeSegment(); // Default Constructor
    SnakeSegment(int x, int y, SnakeSegment *next); // Explicit Constructor
    // Member Function Declarations

    // Access Function Definitions
    int getX() const { return m_x; } // getter for X position
    void setX(int x) { m_x = x; }    // setter for X position
    int getY() const { return m_y; } // getter for Y position
    void setY(int y) { m_y = y; }    // setter for Y position
};

#endif