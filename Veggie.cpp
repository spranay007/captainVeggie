/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description:

*/

#include "Veggie.h"

Veggie::Veggie(const string& name, int points, const string& symbol)
    : FieldInhabitant(symbol), name(name), points(points) {}

string Veggie::getName() const {
    return name;
}

void Veggie::setName(const string& name) {
    this->name = name;
}

int Veggie::getPoints() const {
    return points;
}

void Veggie::setPoints(int points) {
    this->points = points;
}
