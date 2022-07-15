#include "Dizionario.h"
#include <string>
using std::string;

Dizionario::Dizionario(const string& eng,const string& ita){
    setParolaInglese(eng);
    setParolaItaliana(ita);
}

void Dizionario::setParolaInglese(const string& eng){
    parolaInglese=eng;
}

void Dizionario::setParolaItaliana(const string& ita){
    parolaItaliana=ita;
}

string Dizionario::getParolaInglese() const {return parolaInglese;}
string Dizionario::getParolaItaliana() const {return parolaItaliana;}