//CheckingAccount.cpp
#include"CheckingAccount.h"

//constructor
CheckingAccount::CheckingAccount(double initial, double atm) : Account(initial), atmFee{atm} {
    totalFees=0.0;
}

//withdrawal
void CheckingAccount::cashWithdrawal(double amt){
    totalFees+=atmFee;
    debit(amt + atmFee);
}

//get functions
double CheckingAccount::getTotalFees() const {
    return totalFees;
}

//type of account
std::string CheckingAccount::type () const {
    return {"Checking Account"};
}




