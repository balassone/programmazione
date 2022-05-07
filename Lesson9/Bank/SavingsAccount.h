#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"
#include <string>
class SavingsAccount: public Account{
public:
	SavingsAccount(const double&, const double&);
	virtual ~SavingsAccount()=default;
	SavingsAccount& addInterest();
	std::string toString();
private:
	double rate;
};
#endif
