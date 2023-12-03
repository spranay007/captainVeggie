#include "Creature.h"

Creature::Creature(int xCoord, int yCoord, string& symbol) : x(xCoord), y(yCoord), FieldInhabitant(symbol) {}

// Getter functions
int Creature::getX()
{
    return x;
}

int Creature::getY() 
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
