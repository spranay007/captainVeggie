/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description: This is a creature.cpp file.

*/

#include "Creature.h"

Creature::Creature(int xCoord, int yCoord, const string& symbol) : x(xCoord), y(yCoord),FieldInhabitant(symbol)  {}

// Getter functions
int Creature::getX() const
{
    return x;
}

int Creature::getY() const
{
    return y;
}

// Setter functions
void Creature::setX(int xCoord) 
{
    x = xCoord;
}

void Creature::setY(int yCoord) 
{
    y = yCoord;
}
