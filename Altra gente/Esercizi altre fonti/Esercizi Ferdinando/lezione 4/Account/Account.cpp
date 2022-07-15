#include "Account.h"
#include <iostream>
#include <string>
#include <exception>
using std::string;
using std::invalid_argument;

//Constructor
Account::Account(string firstName,double bal)
    : name{firstName} {
        setBalance(bal);
    }

//set and get function
void Account::setName(string firstName){
    name=firstName;
}

void Account::setBalance(double bal){
    if(bal>0) balance=bal;
    else{
        throw invalid_argument("Balance must be positive");
    }
}

string Account::getName() const{
    return name;
}

double Account::getBalance() const{
    return balance;
}

void Account::Withdrow(double wit){
    if(wit>0){
        if(wit<balance) balance=balance-wit;
        else{
            throw invalid_argument("Withdrow must be less than balance");
        }
    }
    else{
        throw invalid_argument("Withdrow must be positive");
    }
}