// Point.h
#ifndef POINT_H
#define POINT_H

class Point {
public:
	explicit Point(double = 0.0, double = 0.0); // default constructor
	
	// set and get functions
	void setX(double);
	void setY(double);
	double getX() const;
	double getY() const;
private:
	double x; 	 // 0.0 <= x <= 20.0
	double y;	// 0.0 <= y <= 20.0
	
};
#endif