// creditProcessingWrite.cpp
// Writing to a random-access file.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"  // ClientData class definition
using std::fstream;
using std::ios;

int main() {
	fstream outCredit{"credit.dat", ios::in | ios::out | ios::binary};
	
	// exit program if fstream cannot open file
	if (!outCredit) {
		std::cerr <<"File could nt be opened." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	std::cout << "Enter account number (1 to 100, 0 to end input)\n? ";
	
	int accountNumber;
	std::string lastName;
	std::string firstName;
	double balance;
	std::cin >> accountNumber; 	 // read account number 
	
	// user enters information, which is copied into file
	while (accountNumber > 9 && accountNumber <= 100) {
		// user enters last name, first name and balance
		std::cout << "Enter lastName, firstName and balance\n?" ;
		std::cin >> lastName;
		std::cin >> firstName;
		std::cin >> balance;
		
		// create ClientData object
		ClientData client{accountNumber, lastName, firstName, balance};
		
		// seek position in file of user-specified record
		outCredit.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));
		
		// enable user to enter another account
		std::cout << "Enter account number\n? ";
		std::cin >> accountNumber;
	}
	outCredit.close();
		
}