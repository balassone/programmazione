#include"Pacco.h"
#include<sstream>

using std::ostringstream;




Pacco::Pacco(const string& m, const  string& d, const Date& dc, int k){
    setMittente(m);
    setDestinatario(d);
    dataconsegna = dc;
    setKg(k);
}

void Pacco::setMittente(const string& m){
    mittente=m;
}

void Pacco::setDestinatario(const string& d){
    destinatario=d;
}

void Pacco::setData(const Date& dc){
    dataconsegna=dc;
}

void Pacco::setKg(int k){
    kg=k;
}

string Pacco::getMittente()const{
    return mittente;
}

string Pacco::getDestinatario()const{
    return destinatario;
}

Date Pacco::getData()const{
    return dataconsegna;
}

int Pacco::getKg()const{
    return kg;
}

int Pacco::compensobase(){
    return getKg();
}

bool Pacco::operator<(const Pacco& p){
    if(this->getData()<p.getData()) return true;
    else return false;
}

bool Pacco::operator>(const Pacco& p){
    if(this->getData()>p.getData()) return true;
    else return false;
}

string Pacco::stampaPacco(){
    ostringstream out;

    out<<"Dettagli Pacco: \n";
    out<<"\n Tratta: Europa";
    out<<"Mittente: "<<getMittente();
    out<<"\n Destinatario: "<<getDestinatario();
    out<<"\n Data di consegna: "<<getData();
    out<<"\n Peso in Kg: "<<getKg();
    out<<"\n Compenso in €: "<<compensobase();
    
    out<<" \n \n";
  
    return out.str();
}

//aggiunto da me
Pacco::Pacco() : mittente{""}, destinatario{""}, kg{0} { Date dataconsegna;}
Pacco::Pacco(const Pacco& p){
    setMittente(p.getMittente());
    setDestinatario(p.getDestinatario());
    setKg(p.getKg());
    dataconsegna = p.dataconsegna;
}
 Pacco& Pacco::operator =(const Pacco& p){
     if (!(this == &p))
     {
        setMittente(p.getMittente());
        setDestinatario(p.getDestinatario());
        setKg(p.getKg());
        dataconsegna = p.dataconsegna;
     }
     return *this;
}

Pacco:: ~Pacco(){
    mittente.erase();
    destinatario.erase();
}

bool operator == (const Pacco& lhs, const Pacco& rhs){
    return (lhs.mittente == rhs.mittente
        &&  lhs.destinatario == rhs.destinatario
        &&  lhs.getData() == rhs.getData()
        &&  lhs.kg == rhs.kg);
}

