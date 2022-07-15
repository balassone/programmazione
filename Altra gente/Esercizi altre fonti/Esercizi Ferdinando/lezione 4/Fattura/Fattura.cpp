#include "Fattura.h"

#include <iostream>
#include <string>
#include <exception>
using std::string;
using std::invalid_argument;

Fattura::Fattura(string codice,std::string descrizione, int numero,int prezzo, double iva, double sconto)
    : codiceArticolo{codice}, descrizioneArticolo{descrizione}, numeroArticoli{numero} {
        setPrezzoArticolo(prezzo);
        setIva(iva);
        setScontoArticolo(sconto);
    }

void Fattura::setCodiceArticolo(string codice){
    codiceArticolo=codice;
}

void Fattura::setDescrizioneArticolo(string descrizione){
    descrizioneArticolo=descrizione;
}

void Fattura::setNumeroArticoli(int numero){
    numeroArticoli=numero;
}

void Fattura::setPrezzoArticolo(int prezzo){
    if(prezzo>0) prezzoArticolo=prezzo;
    else throw invalid_argument("Il prezzo dell'articolo deve essere positivo");
}

void Fattura::setIva(double iva){
    if(iva>=0 && iva<=1) IVA=iva;
    else throw invalid_argument("L'iva deve essere un valore compreso tra 0 ed 1");
}

void Fattura::setScontoArticolo(double sconto){
    if(sconto>=0 && sconto<=1) scontoArticolo=sconto;
    else throw invalid_argument("Lo sconto deve essere riportato in decimali");
}

string Fattura::getCodiceArticolo() const{
    return codiceArticolo;
}

string Fattura::getDescrizioneArticolo() const{
    return descrizioneArticolo;
}

int Fattura::getNumeroArticoli() const{
    return numeroArticoli;
}

int Fattura::getPrezzoArticolo() const{
    return prezzoArticolo;
}

double Fattura::getIva() const{
    return IVA;
}

double Fattura::getScontoArticolo() const{
    return scontoArticolo;
}

double Fattura::getImportoFattura(){
    double importo;
    int PrezzoTot;
    PrezzoTot=numeroArticoli*prezzoArticolo;
    importo=PrezzoTot+(PrezzoTot*IVA)-(PrezzoTot*scontoArticolo);
    return importo;
}
