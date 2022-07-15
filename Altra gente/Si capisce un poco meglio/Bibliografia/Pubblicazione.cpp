//Pubblicazione.cpp
#include"Pubblicazione.h"
#include<sstream>
#include<iostream>
using std::string;
using std::vector;
using std::ostringstream;

//constructor
Pubblicazione::Pubblicazione(string ti, vector<string> au, int yr) : titolo{ti},autori{au},anno{yr} {}

//set & get functions 

//Titolo
void Pubblicazione::setTitolo(string& ti){
    titolo=ti;
}
string Pubblicazione::getTitolo() const{
    return titolo;
}

//Autori
void Pubblicazione::setAutori(vector<string>& au){
    autori=au;
}
vector<string> Pubblicazione::getAutori() const {
    return autori;
}

//Anno
void Pubblicazione::setAnno(int yr){
    if (yr<0) {
        anno=1800;
    } else anno=yr;
} 
int Pubblicazione::getAnno() const {
    return anno;
}

//overloading <
bool Pubblicazione::operator<(const Pubblicazione& p){
    if (autori<p.autori){
        return true;
    }
    else return false;
}

string Pubblicazione::toString() {
    ostringstream out;
    out<<"Autori: ";
    for (size_t i=0; i<((autori.size())-1); i++){
        out<<autori[i]<<", ";
    }
    out<<autori[(autori.size())-1];
    
    out<<"\nTitolo: "<<titolo<<"\nAnno di pubblicazione: "<<anno<<"\n";
    return out.str();
}

