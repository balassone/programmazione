#include "magazzino.h"
#include <string>
#include <exception>
#include <iostream>
using std::invalid_argument;
using std::string;

Magazzino::Magazzino(int cod,const string& nom,int quant,double pre){
    setCodice(cod);
    setNome(nom);
    setQuantita(quant);
    setPrezzo(pre);
}

void Magazzino::setCodice(int cod){
    if(cod>=0 && cod<100){
        codiceArticolo=cod;
    }
    else
        throw invalid_argument("Gli articoli al più possono essere 100");
}

void Magazzino::setNome(const string& nom){
    size_t lunghezza=nom.size();
    lunghezza=(lunghezza>14)? 14:lunghezza;
    nom.copy(nome,lunghezza);
    nome[lunghezza]='\0';
}

void Magazzino::setQuantita(int quant){
    if(quant>=0){
        quantita=quant;
    }
    else
        throw invalid_argument("La quantità deve essere positiva");
}

void Magazzino::setPrezzo(double pre){
    if(pre>=0.0){
        prezzo=pre;
    }
    else 
        throw invalid_argument("Il prezzo deve essere positivo");
}

int Magazzino::getCodice() const{return codiceArticolo;}
string Magazzino::getNome() const{return nome;}
int Magazzino::getQuantita() const{return quantita;}
double Magazzino::getPrezzo() const{return prezzo;}