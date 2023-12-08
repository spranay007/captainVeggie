#include "Snake.h"

Snake::Snake(int x, int y) : Creature(x, y, "S") {}

// Getter functions
int Snake::getSnakeX() const {
    return getX(); // assuming x is a member variable of Creature
}

int Snake::getSnakeY() const {
    return getY(); // assuming y is a member variable of Creature
}

// Setter functions
void Snake::setSnakeX(int x) {
    setX(x);
    //this->x = x; // assuming x is a member variable of Creature
}

void Snake::setSnakeY(int y) {
    setY(y);
    //this->y = y; // assuming y is a member variable of Creature
}