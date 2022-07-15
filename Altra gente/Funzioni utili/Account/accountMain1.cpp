#include <iostream>
#include "Account.h"

using std::cout; using std::endl;

int main() {
	Account acct(1000.0);
	acct.credit(1000.0);
	acct.debit(100.0);
	cout << "balance is: " << acct.getBalance() << endl;
	
	return 0;
}