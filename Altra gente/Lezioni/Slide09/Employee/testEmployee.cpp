//testEmployee.cpp
// Processing Employee derived-class objexts with static binding
// then oplymorphically using dynamic binding.
#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using std::cout;
using std::vector;
void virtualViaPointer(const Employee* const); // prototype
void virtualViaReference(const Employee&); // prototype

int main() {
	cout << std::fixed << std::setprecision(2); // set floating-poing formatting
	
	//create derved-class objects
	SalariedEmployee salariedEmployee{"Paul", "Chambers", "111-11-1111", 800};
	CommissionEmployee commissionEmployee{"Bill", "Evans", "333-33-3333", 10000, .06};
	BasePlusCommissionEmployee basePlusCommissionEmployee{"Miles", "Davis", "444-44-4444", 5000, .04, 300};
	
	//output eache employee's information and earning using static binding
	cout << "EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
		<< salariedEmployee.toString() << "\n earned $ "<< salariedEmployee.earnings() <<"\n\n"
		<<commissionEmployee.toString() << "\n earned $ " << commissionEmployee.earnings() << "\n\n"
		<<basePlusCommissionEmployee.toString() << "\n earned $ " << basePlusCommissionEmployee.earnings() << "\n\n";

	// create and initialize vector of three base-class pointers
	vector<Employee *> employees{&salariedEmployee, &commissionEmployee, &basePlusCommissionEmployee};
	cout << " EMPLOYEES PROCESSED POLYMORPHICALLYT VIA DINAMIC BYNDING\n\n";
	
	// call virtualViaPointer to print each Employee's information and earnings using dynamic binding
	
	cout << "VIRTUAL FUNCTION CALLS MADE OF BASE-CLASS POINTERS\n";
	
	for(const Employee* employeePtr : employees) {
		virtualViaPointer(employeePtr);
	}
	
	// call virtualViaReference to print each Employee's information and earnings using dynamic binding
	cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n";
	
	for(const Employee* employeePtr : employees) {
		virtualViaReference(*employeePtr); 	 // note dereferncing
	}
}

// call Employee virtual functions toString and earnings off a base-class opinter using dynamic binding
void virtualViaPointer(const Employee* const baseClassPtr) {
	cout << baseClassPtr->toString()
		<<"\nearned $" << baseClassPtr->earnings() << "\n\n";
}

// call Employee virtual functions toString and earnings off a base-class reference using dyamic binding
void virtualViaReference(const Employee& baseClassRef) {
	cout << baseClassRef.toString() << "\n earned $" << baseClassRef.earnings() <<"\n\n";
}