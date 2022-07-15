//SavingsAccount.h

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include <string>



class SavingsAccount :  public Account {
public:
    SavingsAccount(): interest{0}, rate{0.05} {}
    explicit SavingsAccount(std::string nome = " ",  double bal = 0.0, double itr = 0.0, double rate = 0.05);
    void calculateInterest(int year);
    
private:
    double interest;
    double rate;

};




#endif