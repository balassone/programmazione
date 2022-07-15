#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout; 
using std::setw;
class Account {
public:
	//Constructors
	Account() : balance{0.0} {}
	Account(double initial) : balance{initial} {}
	
	//Member functions
	void credit(double amt) {balance += amt; }
	void debit(double amt) {balance -= amt; }
	double getBalance() const { return balance; }
	virtual std::string type() const {return "Account";}	
	
private:
	// member data
	double balance;
};

class CheckingAccount: public Account {
	//CheckingAccount is derived from class Account
	
public:
	//Constructor
	CheckingAccount(double initial, double atm) : Account(initial), totalFees{0.0}, atmFee{atm} {}
	
	void cashWithdrawal(double amt) {
		totalFees += atmFee;
		debit(amt + atmFee); 	// call to the membr function of the base class 	
	}
	// get function
	double getTotalFees() const {return totalFees; }
	virtual std::string type() const override { return "Checking Account";}
	
private:
	// private data members
	double totalFees;
	double atmFee;
};

class SavingsAccount : public Account {
	//SavingsAccount is derived from class Account
	
public:
	//Constructor
	SavingsAccount(double initial, double rate) : Account(initial), annualRate{rate} {}
	/*void compoundInterestCalculation(int years){
	cout << "Iniial principal: " << balance;
	cout << "	Interest rate " << annualRate;
	
	cout <<"\nYear" << setw(20) << "Amount on deposit" << endl;
	for(unsigned int year{0}; year <=years; year++ {
		double amount = principal * pow(1.0 + rate, year);
	
		cout << setw(4) << year << setw(20) << amount << endl;
		}
	}
	*/
	double totalAfterYears(int years) const;
	
	virtual std::string type() const override { return "Saving Account";}
	
private: 
	double annualRate;
};

