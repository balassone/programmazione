// creditProcessingRead.cpp
// reading a random-access file sequentially.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "ClientData.h" 	 // ClientData class defnition
using std::ostream;
using std::ifstream;
using std::ios;

void outputLine(ostream &, const ClientData&); 	// prototype

int main() {
	ifstream inCredit{"credit.dat", ios::in | ios::binary};
	
	// exit program if ifstream cannot open file
	if(!inCredit) {
		std::cerr << "File could not be opened." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	// output column heads
	std::cout << std::left << std::setw(10) << "Acstd::count" << std::setw(16) << "Last Name" 
		<< std::setw(11) << "First Name" << std::setw(10) << std::right << "Balance\n";
	
	ClientData client; 	 // create record
	
	// read first record from file
	inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
	
	// read all records from file
	while(inCredit) {
		// display recrod 
		if (client.getAccountNumber() != 0) {
			outputLine(std::cout, client);
		}
		
		// read next from file
		inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
	}
}


// display single record 
void outputLine(ostream& output, const ClientData& record) {
	output << std::left << std::setw(10) << record.getAccountNumber()
		<< std::setw(16) << record.getLastName()
		<< std::setw(11) << record.getFirstName()
			<< std::setw(10) << std::setprecision(2) << std::right << std::fixed
			<< std::showpoint << record.getBalance() << std::endl;
}