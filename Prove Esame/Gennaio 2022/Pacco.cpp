#include <string>
#include <sstream>
#include "Pacco.h"

Pacco::Pacco() : mittente{""}, destinatario{""}, consegna{}, peso{0} {}
Pacco::Pacco(const std::string& m, const std::string& d, const Date& c, const double& p) : mittente{m}, destinatario{d}, consegna{c}, peso{p} {}
Pacco& Pacco::setMittente(const std::string& m) {mittente=m; return *this;}
const std::string& Pacco::getMittente() const {return mittente;}
Pacco& Pacco::setDestinatario(const std::string& d){destinatario=d; return *this;}
const std::string& Pacco::getDestinatario() const{return destinatario;}
Pacco& Pacco::setDate(const Date& c){consegna=c; return *this;}
const Date& Pacco::getDate() const {return consegna;}
Pacco& Pacco::setPeso(const double& p){peso=p; return *this;}
const double& Pacco::getPeso() const {return peso;}
bool Pacco::operator<(const Pacco& p){return consegna<p.consegna;}
std::string Pacco::toString() const{
    std::ostringstream out;
    out << "Mittente: " << mittente;
    out << "\nDestinatario: " << destinatario;
    out << "\nConsegna: " << consegna;
    out << "\nPeso: " << peso << " Kg";
    return out.str();
}