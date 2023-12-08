/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description:

*/


// Include the header file for the FieldInhabitant class
#include "FieldInhabitant.h"

// Constructor for the FieldInhabitant class
FieldInhabitant::FieldInhabitant(const string& symbol) : symbol(symbol) {}

// Destructor for the FieldInhabitant                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ieldInhabitant class (empty as there are no dynamic resources to release)
FieldInhabitant::~FieldInhabitant() {}

// Getter method to retrieve the 'symbol' member variable
string FieldInhabitant::getSymbol() const {
    return symbol;
}

// Setter method to update the 'symbol' member variable with a new value
void FieldInhabitant::setSymbol(const string& symbol) {
    this->symbol = symbol;
}

