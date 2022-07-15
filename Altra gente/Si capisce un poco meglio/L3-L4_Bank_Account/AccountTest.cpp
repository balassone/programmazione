//AccountTest.cpp
//using the Account constructor to initialize the name data member at the time each account is created

#include "Account.h"

using std::cin;
using std::endl;
using std::string;

int main () {
//create two Account objects

  /*
  //prompt for and read name
  cout<<"\n Please enter the account name: ";
  string theName;
  getline (cin, theName); //read a line of text
  myAccount.setName(theName);//put theName in myAccount
  

  //display the name stored in the object my Account
  cout<< "Name in object myAccount is: "<<myAccount.getName()<<endl;
  */

Account account1{"Roberto Torpedine", 50};
Account account2{"Carlo Silvestri", -8};  

  //display initial balance of name for each Account
  cout<< "account1: "<<account1.getName()<<" balance is $"<< account1.getBalance()<<endl;
  cout<< "account2: "<<account2.getName()<<" balance is $"<< account2.getBalance();

  cout<< "\n\nEnter deposit amount for account1: ";
  int depositAmount1;
  cin>>depositAmount1;
  cout<<"Adding "<<depositAmount1<<" to account1 balance"<<endl;
  account1.deposit(depositAmount1),

  //display balances
  cout<<"\n\naccount1: "<<account1.getName()<< "balance is $"<< account1.getBalance();
  cout<<"\n\naccount2: "<<account2.getName()<< "balance is $"<< account2.getBalance();

  cout<< "\n\nEnter deposit amount for account2: ";
  int depositAmount2;
  cin>>depositAmount2;
  cout<<"Adding "<<depositAmount2<<" to account2 balance"<<endl;
  account2.deposit(depositAmount2);

  //display balances
  cout<<"\n\naccount1: "<<account1.getName()<< "balance is $"<< account1.getBalance();
  cout<<"\n\naccount2: "<<account2.getName()<< "balance is $"<< account2.getBalance()<<endl;

  //withdraw

  cout<<"\n\nEnter the withdraw amount for account1: ";
  int withdrawAmount1;
  cin>>withdrawAmount1;
  cout<<"Subtracting "<<withdrawAmount1<<"to account1 balance"<<endl;
  account1.withdraw(withdrawAmount1);

  cout<<"\n\nEnter the withdraw amount for account2: ";
  int withdrawAmount2;
  cin>>withdrawAmount2;
  cout<<"Subtracting "<<withdrawAmount2<<"to account1 balance"<<endl;
  account2.withdraw(withdrawAmount2);

  //display withdraws
  cout<<"\n\naccount1: "<<account1.getName()<<" balance is $"<<account1.getBalance();
  cout<<"\n\naccount2: "<<account2.getName()<<" balance is $"<<account2.getBalance();

}
