#include "Paziente.h"
#include <sstream>
Paziente::Paziente() : nome{""}, cognome{""}, numeroTelefono{""} {}
Paziente::Paziente(const std::string& n,const  std::string& c,const  std::string& t, Dottore* d) :
    nome{n}, cognome{c}, numeroTelefono{t} , dottoreRichiesto{d} {}
Paziente::~Paziente(){
    nome.erase();
    cognome.erase();;
    numeroTelefono.erase();
}

Paziente::Paziente(const Paziente&p){
    dottoreRichiesto = p.dottoreRichiesto;
    nome = p.nome;
    cognome = p.cognome;
    numeroTelefono = p.numeroTelefono;
}

Paziente& Paziente::operator=(const Paziente&p){
    if(!(*this == p)){
        dottoreRichiesto = p.dottoreRichiesto;
        nome = p.nome;
        cognome = p.cognome;
        numeroTelefono = p.numeroTelefono;
    }
    return *this;
}

std::string Paziente::getNome() const{return nome;}
std::string Paziente::getCognome() const{return cognome;}
std::string Paziente::getNumeroTelefono() const{return numeroTelefono;}
Dottore* Paziente::getDottore() const {return dottoreRichiesto;}

void Paziente::setNome(const std::string& n){nome = n;}
void Paziente::setCognome(const std::string& c){cognome = c;}
void Paziente::setNumeroTelefono(const std::string& numTel){numeroTelefono = numTel;}
void Paziente::setDottore(Dottore*d){dottoreRichiesto = d;}

std::string Paziente::toString() const {
    std::ostringstream out;
    out << "NOME PAZIENTE:  " <<getNome()<<std::endl
    << "COGNOME PAZIENTE:  " <<getCognome()<<std::endl
    << "RECAPITO TELEFONICO:  " <<getNumeroTelefono()<<std::endl
    << "NOME DOTTORE RICHIESTO:  " <<dottoreRichiesto->getNome()<< " " << dottoreRichiesto->getCognome()<<std::endl;
    return out.str();
}

bool operator == (const Paziente&lhs, const Paziente&rhs){
    return(lhs.nome == rhs.nome && lhs.cognome == rhs.cognome &&
    lhs.numeroTelefono == rhs.numeroTelefono && *(lhs.dottoreRichiesto) == *(rhs.dottoreRichiesto));
}

std::ostream& operator<< (std::ostream& os, const Paziente& p){
    os << p.toString();
    return os;
}