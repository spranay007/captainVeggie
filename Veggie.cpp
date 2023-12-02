#include "Veggie.h"

Veggie::Veggie(const string& name, const string& symbol, int points)
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
