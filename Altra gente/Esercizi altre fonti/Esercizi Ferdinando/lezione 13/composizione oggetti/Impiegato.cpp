#include "Impiegato.h"
#include <string>
using std::string;

Impiegato::Impiegato(string nom,string cog,int gg,int ms,int an){
    setNome(nom);
    setCognome(cog);
    setDataAssunzione(gg,ms,an);
}

void Impiegato::setNome(string nom){
    nome=nom;
}

void Impiegato::setCognome(string cog){
    cognome=cog;
}

void Impiegato::setDataAssunzione(int gg,int ms,int an){
    dataAssunzione.setData(gg,ms,an);
}

string Impiegato::getNome() const{
    return nome;
}

string Impiegato::getCognome() const{
    return cognome;
}

string Impiegato::getDataAssunzione() const{
    return dataAssunzione.getData();
}

