#ifndef ARTICOLI_H
#define ARTICOLI_H

#include "Pubblicazione.h"

class Articoli: public Pubblicazione{
    public:
    Articoli();
    virtual ~Articoli();
    Articoli(const std::string&, const std::vector<std::string>&, int, const std::string&, const std::string&, int);
    Articoli(const Articoli&a);
    void print() const;
    private:
    std::string titoloConvegno;
    std::string sedeConvegno;
    int numeroPagina;
};

#endif