#include<iostream>
#include<string>

class Account{

public:

	Account(std::string accName, int accBalance)
	: name{accName} {
		if(accBalance>0){
			balance=accBalance;
		}
	}

	void deposit(int amount){
		if (amount>0){
			balance+=amount;
		}
	}

	void withdraw(int amount){
		if(amount<balance){
			balance-=amount;
		}
		else{
			std::cout << "Withdrawal amount exceeded account balance!" << std::endl;
		}
	}

	int getBalance(){
		return balance;
	}

	void setName(std::string newName){
		name = newName;
	}

	std::string getName() const{
		return name;
	}

private:

	std::string name;
	int balance{0};

};
