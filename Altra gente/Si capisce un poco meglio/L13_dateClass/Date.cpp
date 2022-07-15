//Date.cpp
//Date class member functions definition

#include<sstream>
#include<string> //Serve per ostringstream
#include"Date.h"
using namespace std;

//Date constructor(should do range checking)
Date::Date(unsigned int m, unsigned int d, unsigned int y)
    : month{m}, day{d}, year{y} {}

//Print Date in the format mm/dd/yyyy
string Date::toString() const {
    ostringstream output;
    output<<day<<"/"<<month<<"/"<<year;
    return output.str();
}

