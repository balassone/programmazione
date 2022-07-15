#include "Account.h"
#include <string>
#include <iostream>
#include <exception>
using std::invalid_argument;
using std::string;

Account::Account(int num,const string& nom,const string& cog,double sal){
    setNumeroConto(num);
    setNome(nom);
    setCognome(cog);
    setSaldo(sal);
}

void Account::setNumeroConto(int num){
    if(num>=0 && num<100){
        numeroConto=num;
    }
    else
        throw invalid_argument("Il numero di conto inserito non appartiene al range [1-100]");
}

void Account::setNome(const string& nom){
    size_t lunghezza=nom.size();
    lunghezza=(lunghezza>14)? 14:lunghezza;
    nom.copy(nome,lunghezza);
    nome[lunghezza]='\0';
}

void Account::setCognome(const string& cog){
    size_t lunghezza=cog.size();
    lunghezza=(lunghezza>14)? 14:lunghezza;
    cog.copy(cognome,lunghezza);
    cognome[lunghezza]='\0';
}

void Account::setSaldo(double sal){
    if(sal>=0){
        saldo=sal;
    }
    else
        throw invalid_argument("Il saldo deve essere positivo");
}

int Account::getNumeroConto() const {return numeroConto;}
string Account::getNome() const {return nome;}
string Account::getCognome() const {return cognome;}
double Account::getSaldo() const {return saldo;}