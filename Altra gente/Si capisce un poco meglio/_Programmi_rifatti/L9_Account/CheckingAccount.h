//CheckingAccount.h
//derived class of Account

#include"Account.h"
#include<string>

#ifndef CHECKING_ACCOUNT
#define CHECKING_ACCOUNT

class CheckingAccount : public Account {
    public:
        CheckingAccount(double=0.0, double = 0.0);      //constructor

        void cashWithdrawal(double);
        double getTotalFees() const;

        std::string type() const;

    private:
        double totalFees;
        double atmFee;

};

#endif