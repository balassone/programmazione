// Point.cpp
// Member-function definitions for class Point.
#include <stdexcept>
#include "Point.h" 	 // include definition of class Point
using std::invalid_argument;

Point::Point(double xCoord, double yCoord) {
	setX(xCoord); 	 // invoke function setX
	setY(yCoord); 	// invoke function setY
}

// set x coordinate
void Point::setX(double xCoord) {
	if((xCoord < 0.0) || (xCoord > 20.0)) {
	throw invalid_argument ("x must be >= 0.0 and <= 20.0");	
	}
	
	x = xCoord;
}

// set y coordinate
void Point::setY(double yCoord) {
	if ((yCoord < 0.0)||(yCoord > 20.0)) {
		throw invalid_argument("y must be >= 0.0 and <= 20.0");
	}
	
	y = yCoord;
}

// return x coordinate
double Point::getX() const {
	return x;
}

// return y coordinate
double Point::getY() const {
	return y;
}

