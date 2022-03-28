#include<iostream>
#include<string>
#include"Account.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){

	Account myAccount;
	cout << "Initial name: "<<myAccount.getName()<<endl;

	string newName;

	cout << "New Account name: "<<endl;
	getline(cin,newName);

	myAccount.setName(newName);

	cout << "New Account Name: "<<myAccount.getName()<<endl;

	return 0;
}
