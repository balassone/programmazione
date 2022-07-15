#include <iostream>
using std::cout;
using std::endl;

class Shape {
public:
	virtual double area() const = 0; // pure virtual
};

class Rectangle : public Shape {
public:
	Rectangle(double w, double h) : width{w}, height{h} {}
	virtual double area() const {return width * height; }
private:
	double width, height;	
};

int main() {
	//Shape s;
	Rectangle r = {10.0, 5.0};
	cout << "r area = " << r.area() << endl; return 0;
}