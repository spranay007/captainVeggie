/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description:

*/

// Include the header file for the Captain class
#include "Captain.h"

// Constructor for the Captain class, initializing the Creature base class with coordinates and a string identifier
Captain::Captain(int xCoord, int yCoord) : Creature(xCoord, yCoord, "V") {}

// Method to add a Veggie object to the veggieCollection vector
void Captain::addVeggie(Veggie* veggie) 
{
    veggieCollection.push_back(veggie);
}

// Getter method to retrieve the veggieCollection vector
vector<Veggie*>& Captain::getVeggieCollection()
{
    return veggieCollection;
}

// Setter method to set the veggieCollection vector with a new collection
void Captain::setVeggieCollection(const vector<Veggie*>& collection)
{
    // Clear existing collection to avoid memory leaks and copy the new one
    for (Veggie* veggie : veggieCollection) 
    {
        delete veggie; // Delete each Veggie object in the existing collection
    }
    veggieCollection = collection; // Assign the new collection to veggieCollection
}
