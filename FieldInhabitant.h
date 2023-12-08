/* Author: Pranay Saha, Aaftab Gowani, Sameer Bhalala
Date: 12-06-2023
Description: This header file is for FeildInhabitant.
*/

#ifndef FIELDINHABITANT_H
#define FIELDINHABITANT_H

#include <string>

using namespace std;

class FieldInhabitant {
private:
    string symbol;

public:
    //String symbol for vegetable, rabbit or captain
    FieldInhabitant(const string& symbol);
    //Virtual deconstructor
    virtual ~FieldInhabitant();

    // Getter and setter for symbol
    string getSymbol() const;
    void setSymbol(const string& symbol);
};

#endif // FIELDINHABITANT_H
