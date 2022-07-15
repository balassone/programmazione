#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"


class CheckingAccount : public Account{
public:
CheckingAccount() : atmFees{2.0}, totalFee{0.0} {}
CheckingAccount(std::string name ="", double bal = 0.0, double fee = 2.00) : Account(name, bal), atmFees{fee}, totalFee{0.0} {}

void prelievo(double amt){
    totalFee += atmFees;
    debit(amt + atmFees);
}


private:
double atmFees;
double totalFee;

};




#endif