#ifndef RIVISTE_H
#define RIVISTE_H

#include "Pubblicazione.h"
#include <string>
#include <vector>

class Rivista: public Pubblicazione{

public:
    Rivista(const std::string&,const std::vector<std::string>,const Data&,int,int);
    //set e get
    void setNumeroRivista(int);
    void setPagine(int);
    int getNumeroRivista() const;
    int getPagine() const;

    std::string toString() const;

private:
    int numeroRivista;
    int pagine;

};

#endif