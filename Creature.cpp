#include "Creature.h"

Creature::Creature(int xCoord, int yCoord, const string& symbol) : FieldInhabitant(symbol), x(xCoord), y(yCoord)  {}

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
