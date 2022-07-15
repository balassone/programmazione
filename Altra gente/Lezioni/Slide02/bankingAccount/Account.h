#include <string>
#include <iostream>
/* Account.h
Esempio di classi - get e set */
class Account{
public:
	
	Account(std::string accountName, int initialBalance) : name{accountName}{
		if (initialBalance > 0){
			balance = initialBalance;
		}
	}
	
	void deposit (int depositAmount) {
		if(depositAmount > 0){
			balance = balance + depositAmount;
		}
	}
	
	int getBalance() const{
		return balance;
	}
	
	void setName(std::string accountName){
		name=accountName;
	}
	
	std::string getName() const {
		return name;
	}
	
	void withdraw(int withdrawAmount){
		if (withdrawAmount > balance){
			std::cout << "Withdrawal amount exceeded account balance ";
		}
		else{
			std::cout<<"withdrawing "<<withdrawAmount<<"to account2 balance"<<std::endl;
		}
	}
private:
	std::string name;
	int balance{0};
};

void displayAccount(Account accountToDisplay){
	std::cout<<"\n\nAccount: "<<accountToDisplay.getName()<<" balance is $"<<accountToDisplay.getBalance()<<std::endl;
}
