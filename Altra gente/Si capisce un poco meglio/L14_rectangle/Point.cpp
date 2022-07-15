//Point.cpp
//Implementazione della classe Point
#include<stdexcept>
#include"Point.h"

using namespace std;

Point::Point(double xCoord, double yCoord) {
    setX(xCoord);
    setY(yCoord);
}

//set x coordinate
void Point::setX(double xCoord) {
    if (xCoord < 0.0 || xCoord > 20.0) {
        throw invalid_argument("x must be >= 0.0 and <= 20.0");
    }
    x=xCoord;
}
void Point::setY(double yCoord) {
    if (yCoord < 0.0 || yCoord > 20.0) {
        throw invalid_argument("y must be >= 0.0 and <= 20.0");
    }
    y=yCoord;
}

double Point::getX() const {
    return x;
}
double Point::getY() const {
    return y;
}
