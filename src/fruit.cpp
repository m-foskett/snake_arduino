#include <Arduino.h>

#include "fruit.h"

// Constructor Function Definition
Fruit::Fruit(){

};

Fruit::Fruit(int x, int y)
    : m_x{x},
      m_y{y}
{
}