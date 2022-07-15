//Rivista.cpp
#include"Rivista.h"
#include<sstream>
using std::ostringstream;

Rivista::Rivista(string ti, vector<string> au, int yr, string titRiv, int n, int in, int fin) :
Pubblicazione(ti,au,yr){
    titoloRivista=titRiv; numRiv=n; pagIniziale=in; pagFinale=fin;
    }

void Rivista::setTitoloRivista(string&riv) {
    titoloRivista=riv;
}
string Rivista::getTitoloRivista() const{
    return titoloRivista;
}

void Rivista::setNumRiv(int n) {
    numRiv=n;
}
int Rivista::getNumRiv() const{
    return numRiv;
}

void Rivista::setPagIn(int in) {
    pagIniziale=in;
}
int Rivista::getPagIn() const{
    return pagIniziale;
}

void Rivista::setPagFin(int fin) {
    pagFinale=fin;
}
int Rivista::getPagFin() const{
    return pagFinale;
}

string Rivista::toString() {
    ostringstream out;
    out<<Pubblicazione::toString()<<"Titolo della rivista: "<<titoloRivista
    <<"\nNumero della rivista:"<<numRiv
    <<"\nPag. iniziale: "<<pagIniziale
    <<"\nPag. finale: "<<pagFinale<<"\n";
    return out.str();
}
