//testEmployee.cpp
// Demonstrating composition -- an object with member objects

#include <iostream>
#include "Date.h" 	 // Date class definition
#include "Employee.h" 	//Employee class definition
using std::cout;
using std::endl;

int main() {
	Date birth{5, 26, 1926};
	Date hire{8, 17, 1958};
	Employee manager{"Miles", "Davis", birth, hire};
	
	cout << "\n" << manager.toString() << endl;
}