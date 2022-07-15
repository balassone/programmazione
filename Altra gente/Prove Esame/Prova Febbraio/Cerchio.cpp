#include "Cerchio.h"
#include <sstream>
using std::string;

Cerchio::Cerchio(int c, const std::string&f, const std::string&l, float p, double r)
    : Piano(c, f, l, p) , raggio{r} {}

double Cerchio:: getArea() const {
    return 3.14*raggio*raggio;
}

string Cerchio::toString() {
    std::ostringstream output;
    output << Piano::toString() << "\n FORMA PIANO CIRCOLARE"
    <<"\nRAGGIO"<< raggio << " \n AREA" << getArea();
    return output.str();
}


