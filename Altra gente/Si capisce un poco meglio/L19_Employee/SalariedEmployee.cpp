//SalariedEmployee.cpp
#include<iomanip>
#include<stdexcept>
#include<sstream>
#include "SalariedEmployee.h"
using namespace std;

//constructor
SalariedEmployee::SalariedEmployee(const string& first, const string& last, const string& ssn, double salary) : Employee(first,last,ssn){
    setWeeklySalary(salary);
}

//set salary
void SalariedEmployee::setWeeklySalary(double salary){
    if (salary<0){
        throw std::invalid_argument("Weekly Salary must be >=0");
    }
    weeklySalary=salary;
}

//return salary
double SalariedEmployee::getWeeklySalary() const{
    return weeklySalary;
}

//calculate earnings
//override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const {
    return getWeeklySalary();
} 

//return a string representation of SalariedEmployee's information
std::string SalariedEmployee::toString() const {
    std::ostringstream output;
    output<<std::fixed<<std::setprecision(2); //sempre stesso numero di cifre decimali per rappresentare il numero, in particolare 2 cifre
    output<<"salaried employee: "<<Employee::toString()<<"\nweekly salary: "<<getWeeklySalary();
    return output.str();
}
