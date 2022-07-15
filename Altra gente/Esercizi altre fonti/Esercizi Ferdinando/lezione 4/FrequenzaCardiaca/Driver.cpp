#include "Frequenza.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    string nome;
    string cognome;
    int giorno;
    int mese;
    int anno;

    Frequenza persona1;

    cout<<"Inserisci il nome: ";
    cin>>nome;
    persona1.setNome(nome);
    cout<<"Inserisci il cognome: ";
    cin>>cognome;
    persona1.setCognome(cognome);
    cout<<"Inserisci il giorno di nascita: ";
    cin>>giorno;
    cout<<"Inserisci il mese di nascita: ";
    cin>>mese;
    cout<<"Inserisci l'anno di nascita: ";
    cin>>anno;
    persona1.setData(giorno,mese,anno);

    cout<<"\nI dati inseriti sono: "<<endl;
    cout<<persona1.getNome()<<endl;
    cout<<persona1.getCognome()<<endl;
    cout<<persona1.getData()<<endl;

    cout<<"\nL'età di: "<<persona1.getNome()<<" è "<<persona1.eta()<<" anni"<<endl;
    cout<<"La frequenza cardiaca max è :"<<persona1.frequenzaCardiacaMax()<<endl;
    cout<<"Il range della frequenza cardiaca target è :"<<persona1.frequenzaCardiacaTar();

    return 0;


}