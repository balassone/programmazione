#include <iostream>
#include <string>
#include "Rivista.h"
#include "Pubblicazione.h"


Rivista::Rivista() : 
    Pubblicazione(), titoloRivista{""},  numero{0}, paginaInizio{0}, paginaFine{0}  {}

Rivista::Rivista(const std::string& t, const std::vector<std::string>& a, int y, const std::string& ts, int n, int pi, int pf) :
    Pubblicazione(t, a, y), titoloRivista{ts}, numero{n}, paginaInizio{pi}, paginaFine{pf} {}

Rivista::~Rivista(){
    titoloRivista.erase();
}

Rivista::Rivista(const Rivista& r)
    : Pubblicazione(r), titoloRivista{r.titoloRivista}, numero{r.numero}, paginaInizio{r.paginaInizio}, paginaFine{r.paginaFine} {}
void Rivista::print() const {
    std::cout << "Pubblicazione :\n"
    << "Titolo: "<<getTitolo() << "\n"
    <<"Autori: "<<getAutori()<< "\n"
    <<"AnnoPubblicazione: "<< getAnnoPubblicazione() << "\n"
    <<"Tipologia: RIVISTA \n"
    <<"Titolo Rivista: " << titoloRivista << "\n"
    <<"Numero: " << numero << "\n"
    <<"Pagina Inizio: "<< paginaInizio << "\n"
    <<"Pagina Fine: "<<paginaFine << "\n";
}
