#ifndef CAPTAIN_H
#define CAPTAIN_H

#include "Creature.h"
// #include "Veggie.h"  

class Captain : public Creature 
{
private:
    vector<Veggie*> veggieCollection;

public:
    Captain(int xCoord, int yCoord);

    // Function to add Veggie to the collection
    void addVeggie(Veggie* veggie);

    // Getter function for veggieCollection
    vector<Veggie*>& getVeggieCollection();

    // Setter function for veggieCollection
    void setVeggieCollection(const vector<Veggie*>& collection);
};

#endif // CAPTAIN_H
