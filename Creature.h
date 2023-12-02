#ifndef CREATURE_H
#define CREATURE_H

#include "FieldInhabitant.h" 

class Creature : public FieldInhabitant 
{
private:
    int x;
    int y;

public:
    Creature(int xCoord, int yCoord, string& symbol);

    // Getter functions
    int getX();
    int getY();

    // Setter functions
    void setX(int xCoord);
    void setY(int yCoord);
};

#endif // CREATURE_H
