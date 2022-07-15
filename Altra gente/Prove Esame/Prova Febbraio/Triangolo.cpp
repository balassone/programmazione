#include "Triangolo.h"
#include <sstream>
using std::string;

Triangolo::Triangolo(int c, const string&f, const string&l, float p, double b, double h)
    : Piano(c, f, l, p), base{b}, altezza{h} {}

double Triangolo::getArea() const {return (base*altezza)/2;}

string Triangolo::toString() {
    std::ostringstream output;
    output << Piano::toString() << "\n FORMA PIANO TRIANGOLARE"
    <<"\n BASE: "<< base << "\n ALTEZZA: "<< altezza << " \n AREA" << getArea();
    return output.str();
}