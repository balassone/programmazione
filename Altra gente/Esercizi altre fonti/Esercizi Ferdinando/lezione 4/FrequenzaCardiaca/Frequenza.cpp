#include "Frequenza.h"
#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::ostringstream;

Frequenza::Frequenza(string nom,string cog,int gg,int ms,int an){
    setNome(nom);
    setCognome(cog);
    setData(gg,ms,an);
}

void Frequenza::setNome(string nom){
    nome=nom;
}

void Frequenza::setCognome(string cog){
    cognome=cog;
}

void Frequenza::setData(int gg,int ms,int an){
    DataNascita.setGiorno(gg);
    DataNascita.setMese(ms);
    DataNascita.setAnno(an);
}

string Frequenza::getNome() const{
    return nome;
}

string Frequenza::getCognome() const{
    return cognome;
}

string Frequenza::getData() const{
    return DataNascita.Display();
}

int Frequenza::eta(){
    return 2021-DataNascita.getAnno();
}

double Frequenza::frequenzaCardiacaMax(){
    return 220-eta();
}

string Frequenza::frequenzaCardiacaTar(){
    ostringstream out;
    double min,max;
    min=0.5*frequenzaCardiacaMax();
    max=0.85*frequenzaCardiacaMax();
    out<<"["<<min<<","<<max<<"] ";
    return out.str();
}

