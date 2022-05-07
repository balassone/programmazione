#include "CheckingAccount.h"
#include <sstream>
#include <string>

CheckingAccount::CheckingAccount(const double& am) : Account(am) {}

std::string CheckingAccount::toString(){
	std::ostringstream out;
	out << "Checking " << Account::toString();
	return out.str();
}
