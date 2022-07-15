//Account.h
//Class containing a name data member and member functions to set and get value

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>

class Account{

    public:
        Account(std::string ="-", double = 0.0);

        void setName(std::string&);
        std::string getName() const;

        void setBalance(double);
        double getBalance() const;

        void deposit(double);
        void withdraw(double);

        std::string toString() const;

    private:
        std::string name;
        double balance;

};

#endif