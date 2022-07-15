//accountMain2.cpp
// test inheritane
#include <iostream>
#include "Account.h"

using std::cout; using std::endl;

int main() {
	Account acct(1000.0);
	acct.credit(1000.0);
	acct.debit(100.0);
	cout << "Account balance is: $" << acct.getBalance() << endl;
	
	CheckingAccount checking(1000.0, 2.00);
	checking.credit(1000.0); // calls the function of the base class
	checking.cashWithdrawal(100.0); // incurs ATM fee
	cout << "Checking balance is: $" << checking.getBalance() << endl;
	cout << "Checking total fees is: $ " << checking.getTotalFees() << endl;
	
	SavingsAccount saving(1000.0, 0.05);
	saving.credit(1000.0);
	cout << "Savings balance is: $" << saving.getBalance() << endl;
	
	return 0;
}