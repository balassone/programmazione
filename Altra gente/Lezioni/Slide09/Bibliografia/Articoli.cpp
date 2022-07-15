#include "Articoli.h"
#include "Pubblicazione.h"
#include <iostream>

Articoli::Articoli() :
    Pubblicazione(), titoloConvegno{""}, sedeConvegno{""}, numeroPagina{0} {}

Articoli::~Articoli(){
    titoloConvegno.erase();
    sedeConvegno.erase();
}

Articoli::Articoli(const std::string&t, const std::vector<std::string>&a, int y, const std::string& tc, const std::string& sc, int p)
    : Pubblicazione(t,a,y), titoloConvegno{tc}, sedeConvegno{sc},  numeroPagina{p} {}

Articoli::Articoli(const Articoli& a)
    : Pubblicazione(a), titoloConvegno{a.titoloConvegno}, sedeConvegno{a.sedeConvegno}, numeroPagina{a.numeroPagina} {}

void Articoli::print() const {
    std::cout << "Pubblicazione :\n"
    << "Titolo: "<<getTitolo() << "\n"
    <<"Autori: "<<getAutori()<< "\n"
    <<"AnnoPubblicazione: "<< getAnnoPubblicazione() << "\n"
    <<"Tipologia: ARTICOLO SU ATTO DI CONVEGNO \n"
    <<"Titolo Atto Convegno "<< titoloConvegno <<"\n"
    <<"Sede convegno: "<< sedeConvegno << "\n"
    <<"Numero Pagina: "<< numeroPagina << "\n"; 
}