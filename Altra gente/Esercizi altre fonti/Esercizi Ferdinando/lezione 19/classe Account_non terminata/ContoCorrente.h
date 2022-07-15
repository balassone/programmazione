#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H

#include "Account.h"

class ContoCorrente: public Account{

public:
    ContoCorrente(double=0.0,double=2.0,double=0.0);
    virtual ~ContoCorrente() = default;
    //funzioni set e get
    void setCommissioniPrelievo(double);
    void setSpeseTotali(double);
    double getCommissioniPreleivo() const;
    double getSpeseTotali() const;
    //overriding
    void prelievo(double);


private:
    double commissioniPrelievo;
    double speseTotali;


};


#endif