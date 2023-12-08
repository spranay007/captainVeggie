/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description: This header file is for Caption.
*/

#ifndef SNAKE_H
#define SNAKE_H

#include <string>
#include "Creature.h"  

class Snake : public Creature {
public:
    //this is the x and y coordinates of the captain
    Snake(int x, int y);
    
    // Getter functions
    int getSnakeX() const;
    void setSnakeX(int x);

    int getSnakeY() const;
    void setSnakeY(int y);
};

#endif 
