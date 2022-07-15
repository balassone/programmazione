//testAccount.cpp
#include"Account.h"
#include"CheckingAccount.h"
#include"SavingsAccount.h"
#include<iostream>
#include<string>
using std::string;
using std::cout; using std::endl;

string accountType(Account&);

int main() {
    Account a1{1000.0};
    cout<<"Account a1 has a balance of: "<<a1.getBalance()<<"$"<<endl;
    a1.credit(1000);
    a1.debit(100);
    cout<<"After a credit of 1000 and a debit of 100: "<<a1.getBalance()<<"$"<<endl; 

    SavingsAccount s1 {1000.0, 1.5};
    cout<<"Savings Account s1 has balance of: "<<s1.getBalance()<<"$"<<endl;
    cout<<"After 10 years, with an annual rate of "<<s1.getAnnualrate()<<": ";
    cout<<s1.totalAfterYears(10)<<"$"<<endl;

    //Polymorphism
    cout<<"object a1 belongs to category: "<<accountType(a1)<<endl;
    cout<<"object s1 belongs to category: "<<accountType(s1)<<endl;
}

string accountType(Account& a){
    return a.type();
}