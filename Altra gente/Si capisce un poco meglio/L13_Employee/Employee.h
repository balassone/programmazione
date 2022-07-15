//Employee.h
//Employee class definition showing composition.
//Member functions defined in Employee.cpp
#include<string>
#include"Date.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
    public:
        Employee(const std::string&, const std::string&, const Date&, const Date&);
        std::string toString() const;
        ~Employee();
    private:
        std::string firstName;
        std::string lastName;
        const Date birthDate;
        const Date hireDate;
};

#endif