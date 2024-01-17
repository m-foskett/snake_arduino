#ifndef FRUIT_H
#define FRUIT_H

// Fruit Class
class Fruit
{
private:
    int m_x{0};
    int m_y{0};

public:
    // Constructor Function Declaration
    Fruit();             // Default Constructor
    Fruit(int x, int y); // Explicit Constructor
    // Member Function Declarations
    // Access Function Definitions
    int getX() const { return m_x; } // getter for m_x
    void setX(int x) { m_x = x; }    // setter for m_x
    int getY() const { return m_y; } // getter for m_y
    void setY(int y) { m_y = y; }    // setter for m_y
};

#endif