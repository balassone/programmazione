#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account{

public:
    Account(std::string = " ", double = 0);
    //Set and get function
    void setName(std::string);
    void setBalance(double);
    std::string getName() const;
    double getBalance() const;
    //withdrow function
    void Withdrow(double);

private:
    std::string name;
    double balance;
};

#endif