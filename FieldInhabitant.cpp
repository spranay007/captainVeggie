/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description:

*/


#include "FieldInhabitant.h"

FieldInhabitant::FieldInhabitant(const string& symbol) : symbol(symbol) {}

FieldInhabitant::~FieldInhabitant() {}

string FieldInhabitant::getSymbol() const {
    return symbol;
}

void FieldInhabitant::setSymbol(const string& symbol) {
    this->symbol = symbol;
}
