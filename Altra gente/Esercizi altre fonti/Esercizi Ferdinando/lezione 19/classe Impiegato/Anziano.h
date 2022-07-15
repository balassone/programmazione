#ifndef ANZIANO_H
#define ANZIANO_H

#include "Venditore.h"
#include <string>

class Anziano: public Venditore{

public:
    Anziano(const std::string&,const std::string&,Data&,const std::string&,const std::string&,const std::string&,int,double,double,double);
    virtual ~Anziano() = default;
    //funzioni se e get
    void setStipendioBase(double);
    double getStipendioBase() const;
    //overriding delle funzioni
    double calcoloStipendio() const;
    std::string informazioni() const;

private:
    double stipendioBase;




};

#endif