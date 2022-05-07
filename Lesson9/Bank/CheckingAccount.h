#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"
class CheckingAccount: public Account{

public:
	CheckingAccount(const double&);
	std::string toString();
	virtual ~CheckingAccount()=default;
};
#endif
