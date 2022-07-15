#include "Veicolo.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::left;
using std::right;

Veicolo::Veicolo(string modello,string carburante,int anno,string col,int pot)
    : marca{modello}, tipoCarburante{carburante}, annoProduzione{anno}, colore{col}, potenza{pot} {}

void Veicolo::setMarca(string modello){
    marca=modello;
}

void Veicolo::setTipoCarburante(string carburante){
    tipoCarburante=carburante;
}

void Veicolo::setAnnoProduzione(int anno){
    annoProduzione=anno;
}

void Veicolo::setColore(string col){
    colore=col;
}

void Veicolo::setPotenza(int pot){
    potenza=pot;
}

string Veicolo::getMarca() const{
    return marca;
}

string Veicolo::getTipoCarburante() const{
    return tipoCarburante;
}

int Veicolo::getAnnoProduzione() const{
    return annoProduzione;
}

string Veicolo::getColore() const{
    return colore;
}

int Veicolo::getPotenza() const{
    return potenza;
}

void Veicolo::getInformazioni() const{
    cout<<left<<"Marca: "<<right<<getMarca()<<endl;
    cout<<left<<"Tipo di carburante: "<<right<<getTipoCarburante()<<endl;
    cout<<left<<"Anno di produzione: "<<right<<getAnnoProduzione()<<endl;
    cout<<left<<"Colore: "<<right<<getColore()<<endl;
    cout<<left<<"Potenza: "<<right<<getPotenza()<<endl;
}