#include "Rabbit.h"

// Constructor for Rabbit
Rabbit::Rabbit(int x, int y) : Creature(x, y, "R") {
    // The superclass’s constructor is called with x, y, and "R"
    // No need to explicitly initialize x and y here, as it's done in the superclass
}

// Getter functions
int Rabbit::getX() const {
    return x; // assuming x is a member variable of Creature
}

int Rabbit::getY() const {
    return y; // assuming y is a member variable of Creature
}

// Setter functions
void Rabbit::setX(int x) {
    this->x = x; // assuming x is a member variable of Creature
}

void Rabbit::setY(int y) {
    this->y = y; // assuming y is a member variable of Creature
}
