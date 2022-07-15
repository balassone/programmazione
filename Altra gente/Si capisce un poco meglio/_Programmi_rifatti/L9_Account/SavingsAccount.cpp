//SavingsAccount.cpp
#include"SavingsAccount.h"

SavingsAccount::SavingsAccount(double initial, double rate) : Account(initial), annualRate(rate){}

double SavingsAccount::totalAfterYears(int years) const {
    double total{0.0};
    total += getBalance() + annualRate*years;
    return total;
}

double SavingsAccount::getAnnualrate() const {
    return annualRate;
}

//type of account
std::string SavingsAccount::type () const {
    return {"Savings Account"};
}