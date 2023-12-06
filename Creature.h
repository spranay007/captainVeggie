/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description: This header file is for Creature.

*/

#ifndef CREATURE_H
#define CREATURE_H

#include "FieldInhabitant.h" 

class Creature : public FieldInhabitant 
{
private:
    //to store the coordinates of the creature
    int x;
    int y;

public:
    Creature(int xCoord, int yCoord, const string& symbol);

    // Getter functions
    int getX() const;
    int getY() const;

    // Setter functions
    void setX(int xCoord);
    void setY(int yCoord);
};

#endif // CREATURE_H
