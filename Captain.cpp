#include "Captain.h"

Captain::Captain(int xCoord, int yCoord) : Creature(xCoord, yCoord, "V") {}

void Captain::addVeggie(Veggie* veggie) 
{
    veggieCollection.push_back(veggie);
}

const vector<Veggie*>& Captain::getVeggieCollection() 
{
    return veggieCollection;
}

void Captain::setVeggieCollection(vector<Veggie*>& collection)
 {
    // Clear existing collection and copy the new one
    for (Veggie* veggie : veggieCollection) 
    {
        delete veggie;
    }
    veggieCollection = collection;
}
