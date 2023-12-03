#ifndef RABBIT_H
#define RABBIT_H

#include <string>

using namespace std;

class Creature {
public:
    Creature(int x, int y, const string& type);
    // Assume appropriate getter/setter functions for x, y, and type in the Creature class
};

class Rabbit : public Creature {
public:
    Rabbit(int x, int y);
    
    // Getter functions
    int getX() const;
    int getY() const;
    
    // Setter functions
    void setX(int x);
    void setY(int y);

private:
    // Member variables for Rabbit
    // These are inherited from Creature: int x, int y, string type
};

#endif // RABBIT_H
