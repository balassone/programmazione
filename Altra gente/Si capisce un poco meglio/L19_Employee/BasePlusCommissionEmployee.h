//BasePlusCommissionEmployee.h
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include"CommissionEmployee.h"
#include<string>

class BasePlusCommissionEmployee : public CommissionEmployee {
    public: 
        BasePlusCommissionEmployee(const std::string&, const std::string&, const std::string&, double = 0.0, double = 0.0, double = 0.0);
        virtual ~BasePlusCommissionEmployee()=default; //virtual destructor

        double getBaseSalary() const;
        void setBaseSalary(double);

        virtual double earnings() const;
        virtual std::string toString() const;
    private:
        double baseSalary;
};

#endif