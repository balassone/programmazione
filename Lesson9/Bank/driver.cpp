#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <iomanip>
#include <vector>
using std::cout;
using std::fixed;
using std::setprecision;
using std::vector;
using std::cin;

int main(){
	SavingsAccount sav(500,0.5);
	CheckingAccount che(1000);
	Account ac(200);
	vector<Account*> accounts{&sav,&che,&ac};
	cout << fixed << setprecision(2);
	double num;
	cout << "Quanto vuoi prelevare da Savings? ";
	cin >> num;
	accounts[0]->debit(num);
	cout << "\nQuanto vuoi depositare su Savings? ";
	cin >> num;
	accounts[0]->credit(num);
	cout << "Quanto vuoi prelevare da Checking? ";
	cin >> num;
	accounts[1]->debit(num);
	cout << "\nQuanto vuoi depositare su Checking? ";
	cin >> num;
	accounts[1]->credit(num);
	cout << "Quanto vuoi prelevare da Basic? ";
	cin >> num;
	accounts[2]->debit(num);
	cout << "\nQuanto vuoi depositare su Basic? ";
	cin >> num;
	accounts[2]->credit(num);

	for(const auto pointer : accounts){
		cout << pointer->toString() << std::endl;
	}

	SavingsAccount* cia=dynamic_cast<SavingsAccount*>(accounts[0]);
	cia->addInterest();
	for(const auto pointer : accounts){
		cout << pointer->toString() << std::endl;
	}
	return 0;
}
