//Account.h
//Account class that contains name and balance data members, and a costructor
//and deposit function that each perform validation

#include <string> //enable program to use C++ string data type
#include<iostream> 
using std::cout;
using std::endl;

//Ricordiamo che è sempre meglio non usare direttive di tipo "using" all'interno di un file .h, perché non sappiamo chi andrà ad usufruirne.
//Per questo non scriviamo "using std::string" bensì mettiamo "std::string" prima di ogni variabile di tipo string

class Account {
  public:
  	//constructor initializes data member name
 	//with parameter accountName
 	Account(std::string accountName, int initialBalance)
 	: name{accountName} {
 		if (initialBalance>0) {
 			balance=initialBalance;
 		}
 	};

  //function that deposits (adds) only a valid amount to the balance
  
  void deposit(int depositAmount) {
  	if (depositAmount > 0) {
  		balance=balance+depositAmount;
  	}
  }

  //function that returns the account balance
  int getBalance() const {
  	return balance;
  }

  //function that sets the name

  void setName(std::string accountName){
    name = accountName; //store the account name
  }

  //function that retrieves the account name from the object
  std::string getName () const {
    return name; //return name's value to this function's caller
  }
  //function for withdraw
  void withdraw (int withdrawAmount) {
  	if (withdrawAmount>0 && withdrawAmount<balance){
  		balance=balance-withdrawAmount;
  	}
  	else {
  		cout<<"Error"<<endl;
  	}
  }
 
  private:
 	std::string name; //data member containing account holder's name
 	int balance{0}; //data member containing default initial value of balance;

}; //end class Account
