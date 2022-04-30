#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using std::cout; using std::endl;

int main(){
	Point a(5,6);
	Point b{5,18};
	Point c{15,6};
	Point d{15,18};
	Rectangle rec(a,b,c,d,'.','*','-');
	cout << "Rectangle height: " << rec.getHeight() << endl;
	cout << "Rectangle width: " << rec.getWidth() << endl;
	cout << "Rectangle perimeter: " << rec.getPerimeter() << endl;
	cout << "Rectangle area: " << rec.getArea() << endl;
	rec.printRectangle();
	return 0;
}
