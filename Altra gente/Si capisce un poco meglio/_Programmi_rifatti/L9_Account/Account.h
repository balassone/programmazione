#include<string>
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    public:
        //constructor
        Account(double=0.0);
        
        void credit(double);
        void debit(double);
        double getBalance() const;
        virtual std::string type() const;

    private:
        double balance;
};

#endif