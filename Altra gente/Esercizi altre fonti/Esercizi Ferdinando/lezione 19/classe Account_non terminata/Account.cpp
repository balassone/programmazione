#include "Account.h"
#include <iostream>
#include <exception>
using std::invalid_argument;

Account::Account(double sal){
    setSaldo(sal);
}

void Account::setSaldo(double sal){
    if(sal>=0){
        saldo=sal;
    }
    else
        throw invalid_argument("Il saldo deve essere positivo");
}

double Account::getSaldo() const {return saldo;}

void Account::deposito(double deposito){
    if(deposito>0){
        saldo=saldo+deposito;
    }
    else
        throw invalid_argument("Il deposito deve essere maggiore di 0");
}
