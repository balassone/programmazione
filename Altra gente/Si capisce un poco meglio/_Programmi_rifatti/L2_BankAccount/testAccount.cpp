//testAccount.cpp

#include<iostream>
#include"Account.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    Account a;
    cout<<a.toString();
    Account b {"Marco Iadaresta", 590.08};
    cout<<b.toString();
    Account c;
    cout<<"\nInsert name of account possessor:"<<endl;
    string nome;
    getline(cin, nome);
    cout<<"Insert balance:"<<endl;
    double valore;
    cin>>valore;
    c.setName(nome);
    c.setBalance(valore);
    cout<<c.toString();
    c.deposit(470);
    cout<<"After deposit "<<c.toString();
    c.withdraw(341);
    cout<<"After withdraw: "<<c.toString();
}