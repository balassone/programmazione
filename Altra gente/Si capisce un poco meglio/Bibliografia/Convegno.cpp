//Convegno.cpp

#include"Convegno.h"
#include<sstream>
using std::string;
using std::ostringstream;

Convegno::Convegno(string ti, vector<string> au, int yr, string titConv, string sede, int num_conv) :
Pubblicazione(ti,au,yr), titoloConvegno(titConv), sedeConvegno(sede), numPagConv(num_conv) {}

void Convegno::setTitoloConvegno(string& titolo) {
    titoloConvegno=titolo;
}
string Convegno::getTitoloConvegno() const{
    return titoloConvegno;
}

void Convegno::setSedeConvegno(string& sede){
    sedeConvegno=sede;
}
string Convegno::getSedeConvegno() const{
    return sedeConvegno;
}

void Convegno::setNumPagConv(int n){
    numPagConv=n;
}
int Convegno::getNumPagConv() const {
    return numPagConv;
}

string Convegno::toString() {
    ostringstream out;
    out<<Pubblicazione::toString()<<"\n Titolo del convegno: "<<titoloConvegno
    <<" - Sede: "<<sedeConvegno
    <<", si trova a pagina "<<numPagConv<<"\n";
    return out.str();
}
