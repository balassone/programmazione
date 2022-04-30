#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"

class Rectangle{
public:
	Rectangle(const Point&,const Point&,const Point&,const Point&, const char&, const char&, const char&);
	void printRectangle();
	double getHeight() const;
	double getWidth() const;
	double getPerimeter() const;
	double getArea() const;
private:
	Point p1, p2, p3, p4;
	char blank;
	char bound;
	char fill;
	double h;
	double w;
	double p;
	double a;
};
#endif
