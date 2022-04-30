#include "Point.h"
#include <stdexcept>
Point::Point(double x, double y){

	setX(x);
	setY(y);

}

const double& Point::checkPoint(const double& a){

	if(a>=0 && a<=20){
		return a;
	}
	else{
		throw std::invalid_argument("Numero Non Valido!");
	}

}

void Point::setX(const double& x){
	this->x=checkPoint(x);
}

void Point::setY(const double& y){
	this->y=checkPoint(y);
}

double Point::getX() const{
	return x;
}

double Point::getY() const{
	return y;
}
