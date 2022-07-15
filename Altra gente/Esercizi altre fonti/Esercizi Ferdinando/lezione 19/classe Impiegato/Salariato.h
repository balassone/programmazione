#ifndef SALARIATO_H
#define SALARIATO_H

#include "Impiegato.h"
#include <string>

class Salariato: public Impiegato{

public:
    Salariato(const std::string&,const std::string&,Data&,const std::string&,const std::string&,const std::string&,double);
    virtual ~Salariato() = default; //Distruttore di default
    //funzioni set e get
    void setSalario(double);
    double getSalario() const;

    double calcoloStipendio() const;
    std::string informazioni() const;

private:
    double salario;
};

#endif