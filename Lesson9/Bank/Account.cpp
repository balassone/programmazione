#include "Account.h"
#include <stdexcept>
#include <string>
#include <sstream>
Account::Account(const double& am) : amount{0} {
	if (am>0) {amount=am;}
}

Account& Account::credit(const double& am){
	if(am>0){
		amount+=am;
	}
	return *this;
}

Account& Account::debit(const double& am){
	if(am<=amount){
		amount-=am;
	}
	else throw std::invalid_argument("Fondi insufficienti!");
	return *this;
}

std::string Account::toString(){
	std::ostringstream out;
	out << "Account Amount: " << amount;
	return out.str();
}

double Account::getAmount() const{return amount;}
Account& Account::setAmount(const double& ciao){if(ciao>0) amount=ciao; return *this;}
