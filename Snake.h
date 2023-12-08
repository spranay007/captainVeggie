#ifndef SNAKE_H
#define SNAKE_H

#include <string>
#include "Creature.h"  

class Snake : public Creature {
public:
    Snake(int x, int y);
    
    // Getter and Setter functions
    int getSnakeX() const;
    void setSnakeX(int x);

    int getSnakeY() const;
    void setSnakeY(int y);
};

#endif 
