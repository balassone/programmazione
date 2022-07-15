//AccountTest.cpp, creazione di un oggetto di tipo Account

#include <iostream>
#include <string>
#include "Account.h"
#include "DollarAmountEnhanced.h"

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
	DollarAmount balance1{5,75};
	DollarAmount balance2{-7,49};
	Account account1{"Jane Green", balance1 };
	Account account2{"John Blue",  balance2 };
	
	cout<<"account1: "<<account1.getName()<<" balance is $ "<<account1.getBalance()<<endl;
	cout<<"account2: "<<account2.getName()<<" balance is $ "<<account2.getBalance()<<endl;
	
	cout<<"\n \nEnter deposit amount for Account1: ";
	int64_t dollar, cents ;
	cin >> dollar >> cents;
	cout<<"Adding $"<<dollar<<"."<<cents<<" to account1 balance";
	DollarAmount depositAmount{dollar,cents};
	account1.deposit(depositAmount);
	
	displayAccount(account1);
	displayAccount(account2);
	
	cout<<"\n \nEnter deposit amount for Account2: "; 
	cin >> dollar >> cents;
	cout<<"Adding $"<<dollar<<"."<<cents<<"to account2 balance";
	account2.deposit(depositAmount);
	
	displayAccount(account1);
	displayAccount(account2);
	
	cout<<"\n \nEnter withdraw amount for Account2: "; 
	cin>> dollar >> cents;
	DollarAmount withdrawAmount{dollar,cents};
	if(account2.withdraw(withdrawAmount))
		{
			cout<<"Withdrawal amount exceeded account balance";
		}
	else
		{
			cout<<"withdrawing "<<withdrawAmount.getDollar()<<"."<<withdrawAmount.getCents()<<"to account2 balance"<<endl;
		}	
			

	
	displayAccount(account2);
	
	
}
