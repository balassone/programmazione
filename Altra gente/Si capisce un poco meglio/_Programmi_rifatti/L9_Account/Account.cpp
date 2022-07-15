//Account.cpp
#include"Account.h"

//constructor
Account::Account(double initial) : balance{initial} {}

//credit
void Account::credit(double amt) {
    balance+=amt;
}

//debit
void Account::debit(double amt){
    balance-=amt;
}

//getBalance
double Account::getBalance() const {
    return balance;
}

std::string Account::type() const {
    return {"Generic account"};
}