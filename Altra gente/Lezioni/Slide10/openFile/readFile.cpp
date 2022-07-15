//readFile.cpp
// reading and printing a sequential file.
#include <iostream>
#include <fstream> // file stream
#include <iomanip>
#include <string>
#include <cstdlib>

using std::ifstream;
using std::ios;
void outputLine(int, const std::string&, double); // prototype

int main() {
	// ifstream constructor opens the file
	ifstream inClientFile("clients.txt", ios::in);
	
	// exit program if ifstream couldnot open file
	if (!inClientFile) {
		std::cerr <<"File could not be opened" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	std::cout << std::left << std::setw(10) << "Account" << std::setw(20)
		<< "Name" << "Balance\n" << std::fixed << std::showpoint;
	
	int account; 	 // the account number
	std::string name; 	// the account owner's name
	double balance; 	// the account balance
	
	// display each record in file 
	while (inClientFile >> account >> name >> balance) {
		outputLine(account, name, balance);
	}
}

//display single record from file
void outputLine(int account, const std::string& name, double balance) {
	std::cout << std::left << std::setw(10) << account << std::setw(20) << name
		<< std::setw(7) << std::setprecision(2) << std::right << balance << std::endl;
	
}