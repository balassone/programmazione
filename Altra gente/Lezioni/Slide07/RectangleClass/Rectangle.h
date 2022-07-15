// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h" 	 // include definition of class Point

class Rectangle {
public:
	// default constructor
	explicit Rectangle(Point = Point(0.0, 1.0), Point = Point(1.0, 1.0), Point = Point(1.0, 0.0), Point = Point(0.0, 0.0), char = '*', char = '*');
	
	// sets x,y, x2, y2 coordinates
	void setCoord(Point, Point, Point, Point);
	double height() const; // length
	double width() const; // width
	double perimeter() const; 	 // perimeter
	double area() const; 		// area
	bool square() const;		// square
	void draw() const;			// draw rectangle
	void setPerimeterCharacter(char);	// set perimeter character
	void setFillCharacter(char); 	// set fill character
private:
	Point point1;
	Point point2;
	Point point3;
	Point point4;
	char fillCharacter;
	char perimeterCharacter;
};

#endif