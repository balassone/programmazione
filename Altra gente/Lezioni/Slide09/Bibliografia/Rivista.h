#ifndef RIVISTA_H
#define RIVISTA_H
#include "Pubblicazione.h"
#include <iostream>
#include <string>

class Rivista : public Pubblicazione
{
private:
    std::string titoloRivista;
    int numero;
    int paginaInizio;
    int paginaFine;
public:
    Rivista();
    Rivista(const std::string&, const std::vector<std::string>&, int, const std::string&, int, int, int);
    Rivista(const Rivista&);
    virtual ~Rivista();
    void print()const;
};



#endif