//CommissionEmployee.cpp
#include<sstream>
#include<iomanip>
#include"CommissionEmployee.h"
#include<stdexcept>
using std::string;
using std::setprecision;
using std::fixed;
//constructor
CommissionEmployee::CommissionEmployee(const string& first,const string& last, const string& ssn, double sales, double rate): Employee(first,last,ssn){
    setGrossSales(sales);
    setCommissionRate(rate);
}

void CommissionEmployee::setCommissionRate(double rate){
    if(rate<=0.0 || rate>1.0){
        throw std::invalid_argument("Commission rate must be >0.0 and <=1.0");
    }
    
    commissionRate=rate;
}

double CommissionEmployee::getCommissionRate() const{
    return commissionRate;
}

void CommissionEmployee::setGrossSales(double sales){
    if(sales<0){
        throw std::invalid_argument("Sales must be >=0");
    }
    grossSales=sales;
}

double CommissionEmployee::getGrossSales() const{
    return grossSales;
}

//virtual overriding
double CommissionEmployee::earnings() const {
    return getCommissionRate() * getGrossSales();
}
std::string CommissionEmployee::toString() const {
    std::ostringstream output;
    output<<fixed<<setprecision(2);
    output<<"Salaried employee: "<<Employee::toString()<<"\ngross sales: "<<getGrossSales()<<"; commission rate: "<<getCommissionRate();
    return output.str();
}