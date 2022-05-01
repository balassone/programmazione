#include <iostream>
#include "Matrix.h"

using std::cout;
using std::endl;

int main(){
	Matrix a{3,3};
	a.setMatrix();
	cout << endl << a;
	return 0;
}
