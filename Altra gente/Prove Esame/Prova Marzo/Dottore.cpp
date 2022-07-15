#include "Dottore.h"
#include <string>
#include <sstream>




Dottore::Dottore() : 
    nome{""}, cognome{""}, codiceFiscale{""}, numeroTelefono{""}{LinkedQueue<Paziente>codaAttesa;}

Dottore::~Dottore(){
    nome.erase();
    cognome.erase();
    codiceFiscale.erase();
    numeroTelefono.erase();
    codaAttesa.~LinkedQueue();
}

Dottore::Dottore(const std::string& n,const std::string& c,const std::string &cf,const std::string&t)
    :   nome{n}, cognome{c}, codiceFiscale{cf}, numeroTelefono{t}{LinkedQueue<Paziente> codaAttesa;}

//Dottore::Dottore(const std::string& n,const std::string& c,const std::string &cf,const std::string&t, LinkedQueue<Paziente>&q)
  //  :   nome{n}, cognome{n}, codiceFiscale{cf}, numeroTelefono{t} {impostaCoda(q);}

Dottore& Dottore::operator = (const Dottore & d){
    if(!(*this == d)){
        nome = d.nome;
        cognome = d.cognome;
        codiceFiscale = d.codiceFiscale;
        numeroTelefono = d.numeroTelefono;
        impostaCoda(d.codaAttesa);
    }
    return *this;
}

Dottore::Dottore(const Dottore& d){
    nome = d.nome;
    cognome = d.cognome;
    codiceFiscale = d.codiceFiscale;
    numeroTelefono = d.numeroTelefono;
    impostaCoda(d.codaAttesa);
}



//getSet
std::string Dottore::getNome() const{return nome;}
std::string Dottore::getCognome() const{return cognome;}
std::string Dottore::getCodiceFiscale() const{return codiceFiscale;}
std::string Dottore::getNumeroTelefono() const{return numeroTelefono;}
LinkedQueue<Paziente> Dottore::getCoda() const{return codaAttesa;}
void Dottore::setNome(const std::string&n ) {nome = n;}
void Dottore::setCognome(const std::string& c){cognome = c;}
void Dottore::setCodiceFiscale(const std::string &cf){codiceFiscale =cf;}
void Dottore::setNumeroTelefono(const std::string &t){numeroTelefono = t;}
void Dottore::impostaCoda(const LinkedQueue<Paziente>&c){
    if(!(c.empty()))
        codaAttesa = c;
    else
        LinkedQueue<Paziente> codaAttesa;
    
    }
    
void Dottore::nuovoPaziente(const Paziente& p) {
    if(p.getDottore()->getNome() == nome)
        codaAttesa.enqueue(p);
    }
void Dottore::fineVisita() {
    if(!(codaAttesa.empty()))
        codaAttesa.dequeue();
    }


std::string Dottore::toString()const{
    std::ostringstream out;
    out <<" STAMPA DOTTORE "<< std::endl
    << "NOME DOTTORE: " << nome << std::endl
    << "COGNOME DOTTORE: " << cognome << std::endl
    << "CODICE FISCALE: " << codiceFiscale << std::endl
    << "RECAPITO TELEFONICO: " << numeroTelefono << std::endl
    << "*-----------------------------------------*"<<std::endl
    << "        CODA PAZIENTI       "<<std::endl
    <<"numero di pazienti in attesa: "<<codaAttesa.size() << std::endl
    <<"PAZIENTI IN CODA: \n"<<codaAttesa.toString();
    return out.str();
}


bool operator<(const Dottore&lhs, const Dottore&rhs){
    if(lhs.codaAttesa.size() < rhs.codaAttesa.size()){
        return true;
    }
    else return false;
}
bool operator>(const Dottore&lhs, const Dottore&rhs){
    if(lhs.codaAttesa.size() > rhs.codaAttesa.size()){
        return true;
    }
    else return false;
}
bool operator==(const Dottore&lhs, const Dottore&rhs){
    return (lhs.nome == rhs.nome && lhs.cognome==rhs.cognome && lhs.codiceFiscale == rhs.codiceFiscale && lhs.numeroTelefono == rhs.numeroTelefono);
}