#ifndef VENDITORE_H
#define VENDITORE_H

#include "Impiegato.h"
#include <string>

class Venditore: public Impiegato{

public:
    Venditore(const std::string&,const std::string&,Data&,const std::string&,const std::string&,const std::string&,int,double,double);
    virtual ~Venditore() = default;
    //funzioni set e get
    void setNumeroVendite(int);
    void setCostoVendita(double);
    void setPercentualeVendita(double);
    int getNumeroVendite() const;
    double getCostoVendita() const;
    double getPercentualeVendita() const;
    //overriding funzioni
    double calcoloStipendio() const;
    std::string informazioni() const;

private:
    int numeroVendite;
    double costoVendita; //sto supponendo lo stesso prezzo per ogni vendita
    double percentualeVendita;
}; 

#endif