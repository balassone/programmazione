#include "Rettangolo.h"
#include <sstream>
using std::string;

Rettangolo::Rettangolo(int c, const std::string&f, const std::string&l, float p, double b, double h)
    : Piano(c, f,l,p), base{b}, altezza{h} {}

double Rettangolo::getArea() const {return base*altezza;}

string Rettangolo::toString() {
    std::ostringstream output;
    output << Piano::toString() << "\n FORMA PIANO RETTANGOLARE"
    <<"\n BASE: "<< base << "\n ALTEZZA: "<< altezza << " \n AREA" << getArea();
    return output.str();
}