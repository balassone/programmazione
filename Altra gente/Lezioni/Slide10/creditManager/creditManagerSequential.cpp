// creditManagerSequential

#include<iostream>
#include<fstream>
#include<cstdlib>
using std::endl;
using std::cout;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::ios;

int getRequest();// display the menu and gets the choice
bool shouldDisplay(int, double);//decide if the balance corresponds to the choice
void outputLine(int, const std::string&, double); //prints the current record

int main() {
	// ifstream constructor opens the file
	ifstream inClientFile{"clients.txt", ios::in};
	
	// exit program if ifstream could not open file
	if(!inClientFile) {
		cerr << "File could not be oened" << endl;
		exit(EXIT_FAILURE);
	}
	
	// get user's request( e.g., <ero, credit or debit balance)
	int request{getRequest()};
	
	// process user's erquest 
	while(request != 4) {
		switch (request) {
			case 1:
				cout << "\nAccounts with zero balances:\n";
				break;
			case 2:
				cout << "\nAccounts with credit balances:\n";
				break;
			case 3:
				cout << "\nAcounts with debt balances:\n";
				break;
		}
	
		int account; 	 // the account number
		std::string name; 	 // the account owner's name
		double balance; 	 	 // the accoun balance

		// read account, name and balance from file

		// display file contents (until eof)
		while(!inClientFile.eof()) {
			// read account, name and balance from file
			inClientFile >> account >> name >> balance;
			// display record
			if(shouldDisplay(request, balance)) {
				outputLine(account, name, balance);
			}
		}
		inClientFile.clear();  // reset eof for next nput
		inClientFile.seekg(0);  // reposition to beginning of file
		request = getRequest(); 	// get additional request from user
	}
	
	cout << "End of run." << endl;
}
int getRequest() {
	// display request options 
	cout << " \nEnter request\n"
		<< " 1 - List accounts with zero balances\n"
		<< " 2 - List accounts with credit balances\n"
		<< " 3- List accounts with debit balances\n"
		<< " 4 - End of run" << std::fixed << std::showpoint;
	int type; // request from user
	do {
		cout << "\n? ";
		std::cin >> type;
	}while(type < 1 || type > 4);
	
	return type;
}

// determine whether to display given record 
bool shouldDisplay(int type, double balance) {
	//determine weter to display zero balances
	if( type == 1 && balance == 0) {
		return true;
	}
	
	// determine whether to display credit balances
	if (type == 2 && balance < 0) {
		return true;
	}
	
	// determine whether to display debit balances
	if (type == 3 && balance > 0) {
		return true;
	}
	
	return false;
}

// display single record from file
void outputLine(int account, const std::string& name, double balance) {
	cout << std::left << std::setw(10) << account << std::setw(13) << name
		<< std::setw(7) << std::setprecision(2) << std::right << balance << std::endl;
}