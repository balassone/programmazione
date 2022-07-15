#include "Rivista.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using std::vector;
using std::endl;
using std::ostringstream;
using std::string;
using std::cout;

Rivista::Rivista(const string& tit,const vector<string> aut,const Data& dat,int riv,int pag)
    : Pubblicazione(tit,aut,dat) {
        setNumeroRivista(riv);
        setPagine(pag);
    }


void Rivista::setNumeroRivista(int riv){
    numeroRivista=riv;
}

void Rivista::setPagine(int pag){
    pagine=pag;
}

int Rivista::getNumeroRivista() const{return numeroRivista;}
int Rivista::getPagine() const{return pagine;}

string Rivista::toString() const{
    ostringstream out;
    out<<Pubblicazione::toString()<<"Numero rivista: "<<endl<<"Numero pagine: "<<pagine<<endl;
    return out.str();
}