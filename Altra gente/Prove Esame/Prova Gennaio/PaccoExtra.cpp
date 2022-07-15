#include"PaccoExtra.h"
#include<sstream>

using std::ostringstream;



PaccoExtra::PaccoExtra(const string& m, const string& d, const string& n, const string& c, const Date& dc, int k)
: Pacco(m,d,dc,k){
    setNazione(n);
    setContinente(c);
}

void PaccoExtra::setNazione(const string& n){
    nazione=n;
}

void PaccoExtra::setContinente(const string& c){
    continente=c;
}

string PaccoExtra::getNazione()const{
    return nazione;
}

string PaccoExtra::getContinente()const{
    return continente;
}

int PaccoExtra::compensobase(){
    if(this->nazione=="Stati Uniti"){
        return getKg()+10;
    } else {
        return getKg()+15;
    }
}

string PaccoExtra::stampaPacco(){
    ostringstream out;
    out<<"Dettagli Pacco: \n";
    out<<"\n Tratta: Extra-Europa";
    out<<"Mittente: "<<getMittente();
    out<<"\n Destinatario: "<<getDestinatario();
    out<<"\n Nazione di provenienza: "<<getNazione();
    out<<"\n Continente: "<<getContinente();
    out<<"\n Data di consegna: "<<getData();
    out<<"\n Peso in Kg: "<<getKg();
    out<<"\n Compenso in €: "<<compensobase();
    out<<" \n \n";
  
    return out.str();
}

// aggiunte Simone
PaccoExtra :: PaccoExtra() : Pacco(), nazione{""}, continente{""} {}

PaccoExtra::PaccoExtra(const PaccoExtra& p) : Pacco{p.getMittente(), p.getDestinatario(), p.getData(), p.getKg()}{
    setNazione(p.getNazione());
    setContinente(p.getContinente());
}
PaccoExtra& PaccoExtra::operator=(const PaccoExtra& p){
    if(!(this == &p))
    {
    Pacco{p.getMittente(), p.getDestinatario(), p.getData(), p.getKg()}; // object slicing di p
    setNazione(p.getNazione());
    setContinente(p.getContinente());
    }
    return *this;
}
PaccoExtra::~PaccoExtra(){
    nazione.erase();
    continente.erase();
}
//qui si può sicuramente migliorare, a partire dal fatto che questa funzione è una friend class ma non accede ad alcun menbro
// poi 
bool operator == (const PaccoExtra& lhs, const PaccoExtra& rhs) {
    return(lhs.getMittente() == rhs.getMittente()
        &&  lhs.getDestinatario() == rhs.getDestinatario()
        &&  lhs.getData() == rhs.getData()
        &&  lhs.getKg() == rhs.getKg()
        &&  lhs. getNazione() == rhs.getNazione()
        &&  lhs. getContinente() == rhs. getContinente());
}

