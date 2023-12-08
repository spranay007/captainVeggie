/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description: This header file is for Rabbit.

*/


#ifndef RABBIT_H
#define RABBIT_H

#include <string>
#include "Creature.h"

using namespace std;

class Rabbit : public Creature {
public:
    //this is the x and y coordinates of the captain
    Rabbit(int x, int y);
    
    // Getter functions
    int getRabbitX() const;
    void setRabbitX(int x);

    int getRabbitY() const;
    void setRabbitY(int y);

private:
};

#endif // RABBIT_H
