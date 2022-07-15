#include <string>
#include <iostream>
#include "DollarAmountEnhanced.h"
/* Account.h
Esempio di classi - get e set */
class Account{
public:
	
	Account(std::string accountName, DollarAmount& initialBalance) : name{accountName}{
	
	balance = initialBalance;
	
	}
	
	void deposit (DollarAmount depositAmount) {
		balance.add(depositAmount);
	}
	
	string getBalance() const{
		return balance.toString();
	}
	
	void setName(std::string accountName){
		name=accountName;
	}
	
	std::string getName() const {
		return name;
	}
	
	bool withdraw(DollarAmount withdrawAmount){
		if (balance.getDollar()< withdrawAmount.getDollar() 
		&& balance.getCents() < withdrawAmount.getCents()){
			return 1;
		}
		else{
			balance.subtract(withdrawAmount);
			return 0;
		}
	}
private:
	std::string name;
	DollarAmount balance{0,0};
};

void displayAccount(Account accountToDisplay){
	std::cout<<"\n\nAccount: "<<accountToDisplay.getName()<<" balance is $"<<accountToDisplay.getBalance()<<std::endl;
}