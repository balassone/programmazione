//Employee.h
//Employee class definition showing composition.
// member funcions defined in Employee.cpp

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h" 	// include Date class definition

class Employee {
public:
	Employee(const std::string&, const std::string&, const Date&, const Date&);
	std::string toString() const ;
	~Employee(); // provided to confirm destruction order
private:
	std::string firstName;	//composition:member object
	std::string lastName;	//composition:member object
	const Date birthDate; 	//composition:member object
	const Date hireDate;	//composition:member object
};

#endif