/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description:

*/

#include "Rabbit.h"

// Constructor for Rabbit
Rabbit::Rabbit(int x, int y) : Creature(x, y, "R") {
    // The superclass’s constructor is called with x, y, and "R"
    // No need to explicitly initialize x and y here, as it's done in the superclass
}

// Getter functions
int Rabbit::getRabbitX() const {
    return getX(); // assuming x is a member variable of Creature
}

int Rabbit::getRabbitY() const {
    return getY(); // assuming y is a member variable of Creature
}

// Setter functions
void Rabbit::setRabbitX(int x) {
    setX(x);
    //this->x = x; // assuming x is a member variable of Creature
}

void Rabbit::setRabbitY(int y) {
    setY(y);
    //this->y = y; // assuming y is a member variable of Creature
}
