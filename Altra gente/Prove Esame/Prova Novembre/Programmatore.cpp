#include"Programmatore.h"
#include <iomanip>
#include <sstream>

Programmatore::Programmatore(const string& n, double c){
    setNome(n);
    setCosto(c);
}

Programmatore::Programmatore(const Programmatore& p){
    this->nome=p.nome;
    this->costo=p.costo;
}

Programmatore::~Programmatore(){}

Programmatore& Programmatore::operator=(const Programmatore& p){
    this->nome=p.nome;
    this->costo=p.costo;
    return *this;
}


bool Programmatore::operator>(const Programmatore& p){
    if(this->costo>p.costo){
        return true;
    } else {
        return false;
    }
}

bool Programmatore::operator<(const Programmatore& p){
    if(this->costo<p.costo){
        return true;
    } else {
        return false;
    }
}

bool operator==(const Programmatore& lhs, const Programmatore&rhs){
    return (lhs.costo == rhs.costo && lhs.nome == rhs.nome);
}

string Programmatore::toString(){
    std::ostringstream o;
    o<<"Nome: " <<nome<< "costo: "<<costo;

    return o.str();
}

/*Programmatore& Programmatore::operator[](int i){
    
}*/






