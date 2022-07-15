#include "Account.h"
#include "SavingsAccount.h"

#include <iostream>
#include <cmath>


SavingsAccount::SavingsAccount(std::string nome, double bal, double itr, double rate){
    Account(nome, bal);
    interest = itr;
    this->rate = rate; 
}


void SavingsAccount::calculateInterest(int year){
    for(int i=0; i<year; i++){
        interest += getBalance() * pow (1.0 + rate, i);
    }
}