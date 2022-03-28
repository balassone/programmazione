/*
Modify class Account to provide a member function called
withdraw that withdraws money from an Account. Ensure that
the withdrawal amount does not exceed the Account’s
balance. If it does, the balance should be left unchanged
and the member function should display a message indicating
"Withdrawal amount exceeded account balance." Modify class
AccountTest to test member function withdraw.
*/

#include<iostream>
#include<string>
#include"E1.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){

	Account myAcc("Francesco Balassone", 500), yourAcc("Michael Ceccarelli", 0);

	cout << "L'account di " << myAcc.getName() << " ha " << myAcc.getBalance() << " euro." << endl;
	cout << "L'account di " << yourAcc.getName() << " ha " << yourAcc.getBalance() << " euro." << endl;

	cout << yourAcc.getName() << ", quanto vuoi depositare? ";
	int deposit;
	cin >> deposit;
	yourAcc.deposit(deposit);

	cout << "Bene, " << yourAcc.getName() << ", adesso hai " << yourAcc.getBalance() << " euro sul tuo conto." << endl;

	cout << myAcc.getName() << ", quanto vuoi prelevare? ";
	int withdraw;
	cin >> withdraw;
	myAcc.withdraw(withdraw);

	cout << "Bene, " << myAcc.getName() << ", adesso hai " << myAcc.getBalance() << " euro sul tuo conto." << endl;

	return 0;
}
