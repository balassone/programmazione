#include "Veicolo.h"
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;


int main(){
    string marca;
    string carburante;
    int anno;
    string colore;
    int potenza;

    Veicolo v1;

    cout<<"Inserisci il nome del veicolo: ";
    getline(cin,marca);
    v1.setMarca(marca);
    cout<<"Inserisci il tipo di carburante: ";
    cin>>carburante;
    v1.setTipoCarburante(carburante);
    cout<<"Inserisci l'anno di produzione: ";
    cin>>anno;
    v1.setAnnoProduzione(anno);
    cout<<"Inserisci il colore: ";
    cin>>colore;
    v1.setColore(colore);
    cout<<"Inserisci la potenza: ";
    cin>>potenza;
    v1.setPotenza(potenza);

    cout<<"\nI dati inseriti sono:"<<endl;
    v1.getInformazioni();

    return 0;
}