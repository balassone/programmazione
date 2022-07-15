#include "ContoCorrente.h"
#include <iostream>
#include <exception>
using std::invalid_argument;

ContoCorrente::ContoCorrente(double sal,double com,double spe)
    :Account(sal){
        setCommissioniPrelievo(com);
        setSpeseTotali(spe);
    }

void ContoCorrente::setCommissioniPrelievo(double com){
    if(com>=0){
        commissioniPrelievo=com;
    }
    else
        throw invalid_argument("La commissione per il prelievo deve essere positiva");
}


void ContoCorrente::setSpeseTotali(double spe){
    speseTotali=spe;
}

double ContoCorrente::getCommissioniPreleivo() const {return commissioniPrelievo;}
double ContoCorrente::getSpeseTotali() const {return speseTotali;}


void ContoCorrente::prelievo(double pre){
    double prTot=pre+commissioniPrelievo+speseTotali;
    if(pre>0 && prTot<=getSaldo()){
        double nuovoSaldo=getSaldo()-prTot;
        setSaldo(nuovoSaldo);
    }
    else
        throw invalid_argument("Non puoi avere un saldo negtivo");
}

