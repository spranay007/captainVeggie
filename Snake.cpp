#include "Snake.h"

Snake::Snake(int x, int y) : Creature(x, y, "S") {}

// Getter functions
int Snake::getSnakeX() const {
    return getX(); 
}

int Snake::getSnakeY() const {
    return getY(); 
}

// Setter functions
void Snake::setSnakeX(int x) {
    setX(x);
}

void Snake::setSnakeY(int y) {
    setY(y);
}