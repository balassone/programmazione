#include "Point.h"
#include "Rectangle.h"
#include <iostream>
Rectangle::Rectangle(const Point& a, const Point& b, const Point& c, const Point& d, const char& bl, const char& bo, const char& fi) : p1{a}, p2{b}, p3(c), p4(d), blank{bl}, bound(bo), fill(fi) {
	h=(p3.getX()-p1.getX());
	w=(p2.getY()-p1.getY());
	p=2*(h+w);
	this->a=h*w;

}

void Rectangle::printRectangle(){

	for(int i{0}; i<25; ++i){
		for(int j{0}; j<25; ++j){
			if(i<p1.getX() || i>p3.getX() || j<p1.getY() || j>p2.getY()){
				std::cout<<blank;
			}
			else if (i>p1.getX() && i<p3.getX() && j>p1.getY() && j<p2.getY()){
				std::cout<<fill;
			}
			else if(((i==p1.getX()||i==p3.getX()) && (j>=p1.getY() && j<=p2.getY())) || ((j==p1.getY()|| j==p2.getY()) && (i>=p1.getX() && i<=p3.getX()))){
				std::cout<<bound;
			}
		}
		std::cout << std::endl;
	}

}

double Rectangle::getHeight() const{
	return h;
}

double Rectangle::getWidth() const{
	return w;
}
double Rectangle::getPerimeter() const{ return p; }
double Rectangle::getArea() const{return a;}
