#ifndef VEGGIE_H
#define VEGGIE_H

#include "FieldInhabitant.h"

using namespace std;

class Veggie : public FieldInhabitant {
private:
    string name;
    int points;

public:
    Veggie(const string& name, int points, const string& symbol);
    
    // Getter and setter for name
    string getName() const;
    void setName(const string& name);

    // Getter and setter for points
    int getPoints() const;
    void setPoints(int points);
};

#endif // VEGGIE_H
