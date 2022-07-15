//ClientData.cpp
#include"ClientData.h"
#include<string>
using std::string;

ClientData::ClientData(int accountNumberValue, const string& lastName, const string& firstName, double balanceValue) :
accountNumber(accountNumberValue), balance(balanceValue) {
    setLastName(lastName);
    setFirstName(firstName);
}

void ClientData::setAccountNumber(int accountNumberValue){
    accountNumber=accountNumberValue; //should validate
}
int ClientData::getAccountNumber() const {
    return accountNumber;
}

void ClientData::setLastName(const string& lastNameString) {
    //copy at most 15 characters from string sto lastName
    size_t length{lastNameString.size()}; //size_t è una sorta unsigned int 
    length=(length < 15? length: 14);
    lastNameString.copy(lastName, length);
    lastName[length]='\0'; //append null character to lastName
}
string ClientData::getLastName() const {
    return lastName;
}

void ClientData::setFirstName(const string& firstNameString) {
    //copy at most 10 characters from string sto firstName
    size_t length{firstNameString.size()}; //size_t è una sorta unsigned int 
    length=(length < 10? length: 9);
    firstNameString.copy(firstName, length);
    firstName[length]='\0'; //append null character to lastName
}
string ClientData::getFirstName() const {
    return firstName;
}

void ClientData::setBalance(double balanceValue){ 
    balance=balanceValue; 
}
double ClientData::getBalance() const {
    return balance;
}
