// SalariedEmployee.cpp
// salariedEmployee class member-function definitions.
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "SalariedEmployee.h" // SalariedEmployee class definition

//constructor
SalariedEmployee::SalariedEmployee(const std::string& first, const std::string& last, const std::string& ssn, double salary)
	: Employee(first,last,ssn) {setWeeklySalary(salary);}

//set salary
void SalariedEmployee::setWeeklySalary(double salary) {
	if ( salary < 0.0) {throw std::invalid_argument("Weekly salary must be >= 0.0");}
	weeklySalary = salary;
}

// return salary
double SalariedEmployee::getWeeklySalary() const {return weeklySalary; }

//calculate earnings;
//override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const {return getWeeklySalary(); }

//return a string representation of SalariedEmployee's information
std::string SalariedEmployee::toString() const {
	std::ostringstream output;
	output << std::fixed << std::setprecision(2);
	output << "salaried employee: "
		<< Employee::toString() // reuse abstract base-class function
			<< "\nweekly salary: " << getWeeklySalary();
	return output.str();		
}