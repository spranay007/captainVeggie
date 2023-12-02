#ifndef FIELDINHABITANT_H
#define FIELDINHABITANT_H

#include <string>

using namespace std;

class FieldInhabitant {
private:
    string symbol;

public:
    FieldInhabitant(const string& symbol);
    //Virtual deconstructor
    virtual ~FieldInhabitant();

    // Getter and setter for symbol
    string getSymbol() const;
    void setSymbol(const string& symbol);
};

#endif // FIELDINHABITANT_H
