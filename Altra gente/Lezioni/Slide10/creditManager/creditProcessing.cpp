// creditProcessing.cpp
// creating a randomly accessed file.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h" 	 // clientData class definition
using std::ofstream;
using std::ios;

int main() {
	ofstream outCredit{"credit.dat", ios::out | ios::binary};
	
	// exit program if ofstream could not open file 
	if(!outCredit) {
		std::cerr << "File could not be opened." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	ClientData blankClient; 	 // constructor zeros out each data member
	
	// output 100 blank records to file
	for (int i{0}; i<100; ++i) {
		outCredit.write(
			reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
	}
}