#include "Anziano.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
using std::ostringstream;
using std::invalid_argument;
using std::string;
using std::endl;

Anziano::Anziano(const string& nom,const string& cog,Data& dat,const string& ind,const string& num,const string& cod,int ven,double cos,double per,double bas)
    :Venditore(nom,cog,dat,ind,num,cod,ven,cos,per) {
        setStipendioBase(bas);
    }

void Anziano::setStipendioBase(double bas){
    if(bas>0){
        stipendioBase=bas;
    }
    else 
        throw invalid_argument("Lo stipendio base deve essere maggiore di 0");
}

double Anziano::getStipendioBase() const {return stipendioBase;}

double Anziano::calcoloStipendio() const{
    return Venditore::calcoloStipendio()+stipendioBase;
}

string Anziano::informazioni() const{
    ostringstream out;
    out<<Impiegato::informazioni()<<"Stipendio: "<<calcoloStipendio()<<endl;
    return out.str();
}
