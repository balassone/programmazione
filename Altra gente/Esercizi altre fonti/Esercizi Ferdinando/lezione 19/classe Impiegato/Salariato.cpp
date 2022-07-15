#include "Salariato.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
using std::invalid_argument;
using std::string;
using std::ostringstream;
using std::endl;

Salariato::Salariato(const string& nom,const string& cog,Data& dat,const string& ind,const string& num,const string& cod,double sal)
    :Impiegato(nom,cog,dat,ind,num,cod) {
        setSalario(sal);    
    }

void Salariato::setSalario(double sal){
    if(sal>0){
        salario=sal;
    }
    else
        throw invalid_argument("Il salario deve essere maggiore di 0");
}

double Salariato::getSalario() const {return salario;}

double Salariato::calcoloStipendio() const{
    return getSalario();
}

string Salariato::informazioni() const{
    ostringstream out;
    out<<Impiegato::informazioni()<<"Stipendio: "<<calcoloStipendio()<<endl;
    return out.str();
}


