// openFile1.cpp
// Creating a sequential file
#include <iostream>
#include <string>
#include <fstream> // contains file stream processing types
#include <cstdlib> // exit function prototpe
using std::ofstream;
using std::ios;

int main() {
	//ofstream constructor opens file
	ofstream outClientFile{"clients.txt", ios::out};
	
	//exit program if unable to create file
	if(!outClientFile) { // overloaded ! operator
		std::cerr << "File coulld not be opened" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	std::cout << "Enter the account, name, and balance. \n"
		<< "Enter end-of-file to end input \n";
	
	int account; 	 // the account number
	std::string name; 	 // the account owner's name
	double balance;	 	 // the account balance
	
	//read account, name and balance from cin, then place in file
	
	while(std::cin >> account >> name >> balance) {
		outClientFile << account << ' ' << name << ' ' << balance << std::endl;
		std::cout <<" ? ";
	}
}
