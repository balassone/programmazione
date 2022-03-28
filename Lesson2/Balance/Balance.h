#include<string>

class Account{
public:
	Account(std::string acName, int acBalance)
	: name{acName} {

		if(acBalance>0){
			balance=acBalance;
		}
	}

	void deposit(int amount){
		if(amount>0){
			balance+=amount;
		}
	}

	int getBalance() const {
		return balance;
	}

	void setName(std::string acName){
		name=acName;
	}

	std::string getName() const {
		return name;
	}

private:
	std::string name;
	int balance{0};
};
