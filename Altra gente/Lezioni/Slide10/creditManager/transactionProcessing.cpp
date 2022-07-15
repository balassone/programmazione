// transactionProcessing.cpp
// This program reads a random-access file sequentially, updates data previously written to the file, creates data
// to be places in the file, and deletes data prevoiusly stored in the file.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "ClientData.h"

enum class Choice {PRINT = 1, UPDATE, NEW, DELETE, END};

Choice enterChoice();
void createTextFile(std::fstream&);
void updateRecord(std::fstream&);
void newRecord(std::fstream&);
void deleteRecord(std::fstream&);
void outputLine(std::ostream&, const ClientData& ) ;
int getAccount(const char* const);

int main() {
		
	// open file for reading and writing
	std::fstream inOutCredit{"credit.dat", std::ios::in | std::ios::out | std::ios::binary};
	
	// exit program if fstream cannot open file
	if (!inOutCredit) {
		std::cerr << "File could not be opened." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	Choice choice; 		 // store user choice
	
	// enable user to specify action
	while((choice = enterChoice()) != Choice::END) {
		switch(choice) {
			case Choice::PRINT: 	// create text file from recrod file
				createTextFile(inOutCredit);
				break;
			case Choice::UPDATE:		// update record
				updateRecord(inOutCredit);
				break;
			case Choice::NEW:  			// create record
				newRecord(inOutCredit);
				break;
			case Choice::DELETE: 	 	// delete existing record
				deleteRecord(inOutCredit);	
				break;	
			default: 					// display error if user does not select valid choice
				std::cerr<< "Incorrect choice" << std::endl;
				break;
			}
			
			inOutCredit.clear(); 	// 	reset end-of-file indicator
	}
}

//enterChoice
// enable user to input menu choice
Choice enterChoice() {
	//display available options
	std::cout << "\nEnter your choice\n"
		<< "1- store a fromatted text file of accounts\n"
		<< " 	 called \"print.txt\" for printing\n"
		<< "2 - update an account\n"
		<< "3 - add a new account\n"
		<< "4 - delete an account\n"
		<< " 5 - end program\n? " ;
	
	int menuChoice;
	std::cin >> menuChoice; 	 // input menu selection from user
	return static_cast<Choice>(menuChoice);
}

//createTextFile
void createTextFile(std::fstream& readFromFile) {
	std::ofstream outPrintFile("print.txt", std::ios::out); 	 // create text file
	
	// exit program if ofstream cannot create file
	if(!outPrintFile) {
		std::cerr << "File could not be created." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	// output column heads
	outPrintFile << std::left << std::setw(10) << "Account" << std::setw(16) << "Last Name" << std::setw(11)
		<< "First Name" << std::right << std::setw(10) << "Balance" << std::endl;
	
	// set file-position pointer to beginning of readFromFile 
	readFromFile.seekg(0);
	
	// read first record from record file
	ClientData client; 
	readFromFile.read(
		reinterpret_cast<char*>(&client), sizeof(ClientData));
	
	// copy all records from record file into text file
	while (!readFromFile.eof()) {
		// write single record to etxt file
		if (client.getAccountNumber() != 0) { 	 // skip empty records
			outputLine(outPrintFile, client);
		}
	
	// read next record from record file
		readFromFile.read(
			reinterpret_cast<char*>(&client), sizeof(ClientData));
	}
}

//updateRecord

void updateRecord(std::fstream& updateFile) {
	// obtain number of account to update 
	int accountNumber{getAccount("Enter account to update") };
	
	// move file-position pointer to correct record in file
	updateFile.seekg((accountNumber - 1 ) * sizeof(ClientData));
	
	// create record object and read first record from file
	ClientData client;
	updateFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
	
	//update record
	if (client.getAccountNumber() != 0) {
		outputLine(std::cout, client); 	 // display the record
		
		// request user to specify transaction
		std::cout << "\nEnter charge (+) or payment(-): ";
		double transaction; 	 	// charge or payment
		std::cin >> transaction;
		
		// update record balance 
		double oldBalance = client.getBalance();
		client.setBalance(oldBalance + transaction);
		outputLine(std::cout, client); 	 // display the record
		
		// move file-position pointer to correct record in file
		updateFile.seekp((accountNumber - 1) * sizeof(ClientData));
		
		// write updated record over old record in file
		updateFile.write(
			reinterpret_cast<const char*>(&client), sizeof(ClientData));
	}
	
	else {		// display error if account does not exist
		std::cerr << "Account #" << accountNumber
			<< " has no information." << std::endl;
	}
}

//newRecord

void newRecord(std::fstream& insertInFile) {
	// obtain number of account to create 
	int accountNumber{getAccount("Enter new account number")};
	
	// move file-position pointer to corrent record in file
	insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));
	
	// read record from file
	ClientData client;
	insertInFile.read(
		reinterpret_cast<char*>(&client), sizeof(ClientData));
	
	// create record, if record does not previously exist
	if (client.getAccountNumber() == 0) {
		std::string lastName;
		std::string firstName;
		double balance;
		
		// user enters last name, first name and balance
		std::cout << "Enter lastname, firstname, balance\n? ";
		std::cin >> std::setw(15) >> lastName;
		std::cin >> std::setw(10) >> firstName;
		std::cin >> balance;
		
		// use values to populate account values
		client.setLastName(lastName);
		client.setFirstName(firstName);
		client.setBalance(balance);
		client.setAccountNumber(accountNumber);
		
		// move file-position pointer to correct record in file
		insertInFile.seekp((accountNumber - 1) * sizeof(ClientData));
		
		// insert record in file
		insertInFile.write(
			reinterpret_cast<const char*>(&client), sizeof(ClientData));
	}
	else {		// display error if account already exists
		std::cerr << "Account #" << accountNumber << " already contains information" << std::endl;
	}
}

//deleteRecord

void deleteRecord(std::fstream& deleteFromFile) {
	// obtain number of account to delete
	int accountNumber{getAccount("Enter account to delete")};
	
	// move file-position pointer to corrent record in file
	deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));
	
	// read record from file
	ClientData client;
	deleteFromFile.read(
		reinterpret_cast<char*>(&client), sizeof(ClientData));
	
	// delete record, if record exists in file
	if (client.getAccountNumber() !=0) {
		ClientData blankClient; 	 // create blank record
		
		// move file-position pointer to correct record in file
		deleteFromFile.seekp((accountNumber - 1) * sizeof(ClientData));
		
		// replace existng record with blank record
		deleteFromFile.write(
			reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
		
		std::cout << "Account #" << accountNumber << " deleted.\n";
	}
	else { 		 // display error if record does not exist
		std::cerr << "Account #" << accountNumber << " is empty.\n";
	}
}

//outputLine

void outputLine(std::ostream& output, const ClientData& record) {
	output << std::left << std::setw(10) << record.getAccountNumber() << std::setw(16) << record.getLastName()
		<< std::setw(11) << record.getFirstName() << std::setw(10) << std::setprecision(2) << std::right << std::fixed << std::showpoint
		<< record.getBalance() << std::endl;
}

// obtain account-number value from user
int getAccount (const char* const prompt) {
	int accountNumber;
	
	//obtain account-number value
	do{
		std::cout << prompt << " (1 - 100): ";
		std::cin >> accountNumber;
	}while (accountNumber <1 || accountNumber > 100);
	
	return accountNumber;
}