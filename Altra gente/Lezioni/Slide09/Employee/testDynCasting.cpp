//testDynCasting.cpp
// demosnstrating downcasting and runtime type informaton
#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using std::cout;
using std::endl;
using std::vector;
int main() {
	//set floating-point formatting
	cout << std::fixed << std::setprecision(2);
	
	// create and initialize vector of three base-class pointers
	vector<Employee*> employees{
	new SalariedEmployee("John", "Smith", "111-11-1111", 800),
	new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06),
	new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300)	
	};
	
	//polymorphically process each element in vector employees
	for (Employee* employeePtr : employees) {
		cout << employeePtr->toString() << endl; // output employee
		// attempt to downcast pointer 
		BasePlusCommissionEmployee* derivedPtr = dynamic_cast<BasePlusCommissionEmployee*>(employeePtr);
	
		//determine whether element points to a BasePlusCommissionEmployee
		if(derivedPtr != nullptr) { // truefor "is a" relationship
			double oldBaseSalary = derivedPtr->getBaseSalary();
			derivedPtr->setBaseSalary(1.10 * oldBaseSalary);
			cout << "new base salary with 10% increase is: $"
				<< derivedPtr->getBaseSalary() << endl;
		}
	
		cout << "earned $" << employeePtr->earnings() << "\n\n";
	}
	
	//release objects pointed to by vector's element
	
	for(const Employee* employeePtr : employees) {
		//output class name
		cout << "deleting object of " << typeid(*employeePtr).name() << endl;
		
		delete employeePtr;
	}
}