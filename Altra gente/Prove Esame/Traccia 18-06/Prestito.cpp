#include "Prestito.h"
#include <string>
#include <iostream>
#include <sstream>
using std::string;

Prestito::Prestito(const Libro& lib,const Data& pre){
    setLibroPrestato(lib);
    setDataPrestito(pre);
}

void Prestito::setLibroPrestato(const Libro& lib){
    libroPrestato=lib;
}

void Prestito::setDataPrestito(const Data& pre){
    dataPrestito=pre;
}

string Prestito::getLibroPrestato() const{
    return libroPrestato.toString();
}

string Prestito::getDataPrestito() const{
    return dataPrestito.getData();
}

Data& Prestito::DataRestituzione() const{
    Data d=dataPrestito;
    d=d+30;
    return d;
}

bool Prestito::operator>(const Prestito& p){
    if(this->DataRestituzione()>p.DataRestituzione()) return true;
    return false;
}

