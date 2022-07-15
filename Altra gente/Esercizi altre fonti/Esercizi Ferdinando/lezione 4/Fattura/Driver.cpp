#include <iostream>
#include "Fattura.h"
using std::cout;
using std::cin;

int main(){
    int numero;
    double sconto;

    Fattura conto1{"0443-xst55","chiodi",0,1};

    cout<<"Inserisci il numero di "<<conto1.getDescrizioneArticolo()<<" : ";
    cin>>numero;
    conto1.setNumeroArticoli(numero);
    cout<<"\nQuale sconto vuoi applicare (in decimale)? ";
    cin>>sconto;
    conto1.setScontoArticolo(sconto);
    cout<<"\nIl prezzo totale è: "<<conto1.getImportoFattura();


    
}