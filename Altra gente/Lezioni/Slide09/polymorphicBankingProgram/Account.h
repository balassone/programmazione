//Account.h 
//Definizione account

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account{

friend bool operator<(Account &lhs, Account &rhs);

public:

   Account(): name{""}, balance{0} {}
   
   Account(std::string nome, double bal) : name{nome}, balance{bal} {}
   Account(Account &acc);


    
   std::string getName() const;
   double getBalance() const;
   void setName(std::string nome);
   void credit(const double amt);
   void debit (const double amt);
   
private:
   std::string name;
   double balance;
};









#endif