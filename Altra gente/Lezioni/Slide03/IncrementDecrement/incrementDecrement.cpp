// Increment.cpp
// Prefix increment and postfixIncrement
#include <iostream>
using namespace std; //generally wrong for memory reasons: avoid this during an exam

int main(){
	//demonstrate postfix increment operator
	unsigned int c{5}; //initializes c with the value 5
	cout << "c before postincrement: "<< c << endl; // prints 5
	cout << "	postincrementing c: " << c++ <<endl; // prints 5
	cout << " c after postincrement: "<< c << endl; // prints 6
	
	cout << endl; //skips a line
	
	// demonstrate prefix increment operator 
	c = 5;
	cout << " c before preincrement " << c << endl; // prints 5
	cout << "	preincrementing c: "<< ++c << endl; // prints 6
	cout << " c after preincrementing: " << c << endl; // prints 6
}