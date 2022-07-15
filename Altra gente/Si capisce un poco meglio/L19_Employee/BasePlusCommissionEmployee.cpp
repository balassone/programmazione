//BasePlusCommissionEmployee.cpp
#include<stdexcept>
#include<sstream>
#include<iomanip>
#include"BasePlusCommissionEmployee.h"
using std::string; using std::setprecision; using std::fixed; using std::ostringstream;

//constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn, double sales,double rate, double salary) : CommissionEmployee(first, last, ssn, sales, rate) {
    setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary){
    if(salary<0.0){
        throw std::invalid_argument("salary must be >0.0");
    }
    baseSalary=salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

//Calculating earnings
double BasePlusCommissionEmployee::earnings() const{
    return getBaseSalary()+CommissionEmployee::earnings();
}

string BasePlusCommissionEmployee::toString() const{
    ostringstream output;
    output<<fixed<<setprecision(2);
    output<<"base-salaried "<<CommissionEmployee::toString()<<"; base salary: "<<getBaseSalary();
    return output.str();
}