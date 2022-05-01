#include <iostream>
#include "Matrix.h"

using std::cout;
using std::endl;

int main(){
	Matrix a{3,3};
	a.setMatrix();
	cout << endl << "a:" << endl << a;
	Matrix b{a};
	cout << endl << "b: " << endl << b;
	Matrix c;
	c=b;
	cout << endl << "c: " << endl << c;
	c=c*b;
	cout << endl << "c: " << endl << c;
	c=c-a;

	cout << endl << "c: " << endl << c;


	b=a+c;

	cout << endl << "b: " << endl << b;
	return 0;
}
