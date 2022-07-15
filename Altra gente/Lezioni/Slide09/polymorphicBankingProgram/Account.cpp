//Account.cpp
#include <iostream>
#include "Account.h"

using std::string;

bool operator <(Account &lhs, Account & rhs){
    return (lhs.balance < rhs.balance);
}


Account::Account(Account &acc){
    name = acc.name;
    balance = acc.balance;
}

void Account::setName(std::string nome){name = nome;}
std::string Account::getName() const {return name;}
double Account::getBalance() const{return balance;}
void Account::debit(const double amt){balance -=amt;}
void Account::credit(const double amt){balance +=amt;}

