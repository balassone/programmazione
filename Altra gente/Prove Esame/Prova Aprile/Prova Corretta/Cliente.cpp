#include "Cliente.h"
#include <sstream>


//i confronti vengono effettuati a seconda della data

bool operator < (const Cliente& lhs, const Cliente& rhs){
    return (lhs.dataPrenotazione < rhs.dataPrenotazione);
}
bool operator > (const Cliente& lhs, const Cliente& rhs){
    return (lhs.dataPrenotazione > rhs.dataPrenotazione);
}

bool operator == (const Cliente& lhs, const Cliente& rhs){
    return (lhs.dataPrenotazione == rhs.dataPrenotazione);
}
//overload operator << per stampa all'interno della lista
std::ostream& operator<<(std::ostream& out, const Cliente &cl){
    out << cl.toString();
    return out;
}

Cliente::Cliente(const Cliente & cl){
    setData(cl.getData());
    setNome(cl.getNome());
    setCartaCredito(cl.getCartaCredito());
}

Cliente& Cliente::operator=(const Cliente&cl){
    if(!(this == &cl)){ // controlla se si sta effettuando la copia dello stesso oggetto
        setData(cl.getData());
        setNome(cl.getNome());
        setCartaCredito(cl.getCartaCredito());
    }
    return *this;
}

void Cliente::setData(const Date& data){dataPrenotazione = data;}
void Cliente::setNome(const std::string& n){nome = n;}
void Cliente::setCartaCredito(const std::string&carta){codiceCartaCredito = carta;}
Date Cliente::getData() const {return dataPrenotazione; }
std::string Cliente::getNome () const {return nome;}
std::string Cliente::getCartaCredito() const {return codiceCartaCredito;}




std::string Cliente::toString() const {
    std::ostringstream out;

    out << "        DATI CLIENTE: \n"
    << "NOME : "<<nome << "\n"
    << " DATA PROENOTAZIONE : "<< dataPrenotazione<< "\n"
    << "CODICE CARTA CREDITO : "<<codiceCartaCredito << "\n";

    return out.str();

} 