//Account.cpp

#include"Account.h"
#include<stdexcept>
#include<sstream>
using std::string;
using std::invalid_argument;
using std::ostringstream;

Account::Account(string s, double v ) : name(s) {
    setBalance(v);
}

void Account::setBalance(double v){
    if (v>=0){
        balance=v;
    }
    else throw std::invalid_argument("Balance must be >0");
}

double Account::getBalance() const {
    return balance;
}

void Account::setName(string& s) {
    name=s;
}

string Account::getName() const {
    return name;
}

void Account::deposit(double depositAmount){
    if (depositAmount > 0) {
        balance+=depositAmount;
    }
}

void Account::withdraw(double withdrawAmount){
    if (withdrawAmount>0 && withdrawAmount<balance){
        balance -= withdrawAmount;
    }
}

string Account::toString() const {
    ostringstream out;
    out<<"Account belonging to "<< name <<" has a balance ($) : "<<balance<<"\n";
    return out.str();
}
