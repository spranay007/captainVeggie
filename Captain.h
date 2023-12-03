#ifndef CAPTAIN_H
#define CAPTAIN_H

#include "Creature.h"
#include "Veggie.h"  
#include<vector>

class Captain : public Creature 
{
private:
    vector<Veggie*> veggieCollection;

public:
    Captain(int xCoord, int yCoord);

    // Function to add Veggie to the collection
    void addVeggie(Veggie* veggie);

    // Getter function for veggieCollection
    const vector<Veggie*>& getVeggieCollection() const;

    // Setter function for veggieCollection
    void setVeggieCollection(const vector<Veggie*>& collection);
};

#endif // CAPTAIN_H
