#include "Impiegato.h"
#include <string>
#include <sstream>
using std::ostringstream;
using std::string;
using std::endl;

Impiegato::Impiegato(const string& nom,const string& cog,Data& dat,const string& ind,const string& num,const string& cod){
    setNome(nom);
    setCognome(cog);
    setData(dat);
    setIndirizzo(ind);
    setNumero(num);
    setCodiceFiscale(cod);
}

void Impiegato::setNome(const string& nom){
    nome=nom;
}

void Impiegato::setCognome(const string& cog){
    cognome=cog;
}

void Impiegato::setData(Data& dat){
    dataNascita=dat;
}

void Impiegato::setIndirizzo(const string& ind){
    indirizzo=ind;
}

void Impiegato::setNumero(const string& num){
    numero=num;
}

void Impiegato::setCodiceFiscale(const string& cod){
    codiceFiscale=cod;
}

string Impiegato::getNome() const {return nome;}
string Impiegato::getCognome() const{return cognome;}
string Impiegato::getData() const{return dataNascita.Display();}
string Impiegato::getIndirizzo() const{return indirizzo;}
string Impiegato::getNumero() const{return numero;}
string Impiegato::getCodiceFiscale() const{return codiceFiscale;}

string Impiegato::informazioni() const{
    ostringstream out;
    out<<"Nome: "<<getNome()<<endl<<"Cognome: "<<getCognome()<<endl<<"Data: "<<getData()<<endl
    <<"Indirizzo: "<<getIndirizzo()<<endl<<"Numero: "<<getNumero()<<endl<<"Codice Fiscale: "<<getCodiceFiscale()<<endl;
    return out.str();
}