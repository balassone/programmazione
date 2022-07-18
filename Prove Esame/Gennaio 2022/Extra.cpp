#include "Pacco.h"
#include "Extra.h"
#include <string>
#include <sstream>

Extra::Extra() : Pacco(), nazione{""}, continente {""} {}
Extra::Extra(const std::string& m, const std::string& d, const Date& c, const double& p, const std::string& n, const std::string& co) : Pacco(m,d,c,p), nazione{n}, continente{co} {}
Extra& Extra::setNazione(const std::string& n){
    nazione=n;
    return *this;
}
const std::string& Extra::getNazione() const {return nazione;}
Extra& Extra::setContinente(const std::string& c){
    continente=c;
    return *this;
}
const std::string& Extra::getContinente() const {return continente;}

std::string Extra::toString() const{
    std::ostringstream out;
    out << Pacco::toString() << "\nNazione: " << nazione;
    out << "\nContinente: " << continente;
    return out.str();
}