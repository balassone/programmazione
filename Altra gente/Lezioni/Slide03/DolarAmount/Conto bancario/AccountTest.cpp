//AccountTest.cpp, creazione di un oggetto di tipo Account

#include <iostream>
#include <string>
#include "Account.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	/*Account myAccount{""};
	cout<<"Initial account name is: \n"<<myAccount.getName();
	cout<< "Please enter the account name : ";
	string theName;
	getline(cin, theName);
	myAccount.setName(theName);
	
	cout<< "Name in object myAccount is: "<<myAccount.getName()<<endl; */
	
	Account account1{"Jane Green", 50};
	Account account2{"John Blue", -7};
	
	cout<<"account1: "<<account1.getName()<<" balance is $ "<<account1.getBalance()<<endl;
	cout<<"account2: "<<account2.getName()<<" balance is $ "<<account2.getBalance()<<endl;
	
	cout<<"\n \nEnter deposit amount for Account1: "; 
	int depositAmount;
	cin>> depositAmount;
	cout<<"Adding $"<<depositAmount<<" to account1 balance";
	account1.deposit(depositAmount);
	
	displayAccount(account1);
	displayAccount(account2);
	
	cout<<"\n \nEnter deposit amount for Account2: "; 
	cin>> depositAmount;
	cout<<"Adding $"<<depositAmount<<"to account2 balance";
	account2.deposit(depositAmount);
	
	displayAccount(account1);
	displayAccount(account2);
	
	cout<<"\n \nEnter withdraw amount for Account2: "; 
	int withdrawAmount;
	cin>> withdrawAmount;
	if(account2.withdraw(withdrawAmount))
		{
			cout<<"Withdrawal amount exceeded account balance";
		}
	else
		{
			cout<<"withdrawing "<<withdrawAmount<<"to account2 balance"<<endl;
		}	
			

	
	displayAccount(account2);
	
	
}
