#include "SavingsAccount.h"
#include <sstream>
SavingsAccount::SavingsAccount(const double& am, const double& ra) : Account(am), rate{ra} {}

SavingsAccount& SavingsAccount::addInterest(){
	setAmount(getAmount()+getAmount()*rate);
	return *this;
}

std::string SavingsAccount::toString(){
	std::ostringstream out;
	out << "Savings " << Account::toString();
	return out.str();
}
