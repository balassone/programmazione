#include "Pubblicazione.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using std::ostringstream;
using std::cout;
using std::endl;
using std::string;
using std::vector;

Pubblicazione::Pubblicazione(const string& tit,const vector<string> aut,const Data& dat){
    setTitolo(tit);
    setAutori(aut);
    setData(dat);
}

void Pubblicazione::setTitolo(const string& tit){
    titolo=tit;
}

void Pubblicazione::setAutori(const vector<string> aut){
    autori=aut;
}

void Pubblicazione::setData(const Data& dat){
    annoPubblicazione=dat;
}

string Pubblicazione::getTitolo() const{
    return titolo;
}

string Pubblicazione::getAutori() const{
    ostringstream out;
    for(size_t i=0;i<autori.size();i++){
        out<<autori[i]<<" ";
    }
    return out.str();
}

string Pubblicazione::getData() const{
    return annoPubblicazione.Display();
}

string Pubblicazione::toString() const {
    ostringstream out;
    out<<"Titolo: "<<titolo<<endl<<"Autori: "<<getAutori()<<endl<<"Anno pubblicazione: "<<getData()<<endl;
    return out.str();
}

bool Pubblicazione::operator<(const Pubblicazione& pub){
    if(this->autori<pub.autori){ //sfrutto l'overloading dell'operzione < data dalla classe vector
        return true;
    }
    else if(this->autori == pub.autori && this->annoPubblicazione<pub.annoPubblicazione){
        return true;
    }
    else return false;
}