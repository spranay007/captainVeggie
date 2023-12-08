/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description:This is a Rabbit.cpp file.
*/

#include "Rabbit.h"

// Constructor for Rabbit
Rabbit::Rabbit(int x, int y) : Creature(x, y, "R") {}

// Getter functions
int Rabbit::getRabbitX() const {
    return getX(); 
}

int Rabbit::getRabbitY() const {
    return getY(); 
}

// Setter functions
void Rabbit::setRabbitX(int x) {
    setX(x);
}

void Rabbit::setRabbitY(int y) {
    setY(y);
}
