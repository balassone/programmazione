//SavingsAccount.h
#include"Account.h"

#ifndef SAVINGS_ACCOUNT
#define SAVINGS_ACCOUNT

class SavingsAccount : public Account {
    public:
        SavingsAccount(double=0.0, double=0.0);
        double totalAfterYears(int years) const;
        double getAnnualrate() const;

        std::string type() const;
    private:
        double annualRate;
};

#endif