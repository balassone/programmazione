#include "Venditore.h"
#include <iostream>
#include <stdexcept>
#include <sstream>
using std::ostringstream;
using std::invalid_argument;
using std::string;
using std::endl;

Venditore::Venditore(const string& nom,const string& cog,Data& dat,const string& ind,const string& num,const string& cod,int ven,double cos,double per)
    :Impiegato(nom,cog,dat,ind,num,cod){
        setNumeroVendite(ven);
        setCostoVendita(cos);
        setPercentualeVendita(per);
    }

void Venditore::setNumeroVendite(int ven) {
    if(ven>=0){
        numeroVendite=ven;
    }
    else
        throw invalid_argument("Il numero delle vendite deve essere positivo");
}

void Venditore::setCostoVendita(double cos){
    if(cos>0){
        costoVendita=cos;
    }
    else
        throw invalid_argument("Il costo di una singola vendita deve essere maggiore di 0");
}

void Venditore::setPercentualeVendita(double per){
    if(per>0 && per<1){
        percentualeVendita=per;
    }
    else 
        throw invalid_argument("La percentuale di vendita deve essere in modulo minore di 1");
}

int Venditore::getNumeroVendite() const {return numeroVendite;}
double Venditore::getCostoVendita() const {return costoVendita;}
double Venditore::getPercentualeVendita() const {return percentualeVendita;}

double Venditore::calcoloStipendio() const{
    double costoTot=numeroVendite*costoVendita;
    return percentualeVendita*costoTot;
}

string Venditore::informazioni() const{
    ostringstream out;
    out<<Impiegato::informazioni()<<"Stipendio: "<<calcoloStipendio()<<endl;
    return out.str();
}

