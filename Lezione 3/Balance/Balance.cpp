#include<iostream>
#include<string>
#include"Balance.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){

	Account uno{"Francesco Balassone",100}, due{"Chiara Balassone",-70};

	cout << uno.getName() << " ha " << uno.getBalance() << " euro." << endl;
	cout << due.getName() << " ha " << due.getBalance() << " euro." << endl;

	cout << uno.getName() << ", quanto vuoi depositare? ";
	int deposit{0};
	cin >> deposit;
	uno.deposit(deposit);
	cout << "Adesso " << uno.getName() << " ha " << uno.getBalance() << " euro!" << endl;

	return 0;
}
