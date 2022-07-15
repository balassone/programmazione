#include <iostream>
#include "Impiegato.h"
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(){
    Impiegato c1{"Ferdinando","Costigliola",16,8,2005};
    Impiegato c2{"Carmine","Fonderico",4,5,2020};

    cout<<"I dati dell'impiegato c1 sono: "<<endl;
    cout<<"Nome: "<<c1.getNome()<<endl;
    cout<<"Cognome: "<<c1.getCognome()<<endl;
    cout<<"Data assunzione: "<<c1.getDataAssunzione()<<endl;

    cout<<"\nI dati dell'impieagto c2 sono: "<<endl;
    cout<<"Nome: "<<c2.getNome()<<endl;
    cout<<"Cognome: "<<c2.getCognome()<<endl;
    cout<<"Data assunzione: "<<c2.getDataAssunzione()<<endl;



    




}