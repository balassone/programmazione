#include "Libro.h"
#include "iostream"

Libro::Libro() : 
    Pubblicazione(), ISBN{0}, casaEditrice{""} {}
Libro::~Libro(){
    casaEditrice.erase();
}
Libro::Libro(const std::string&t, const std::vector<std::string>&a, int y, int i, const std::string& c) 
    : Pubblicazione(t,a,y), ISBN{i}, casaEditrice{c} {}

Libro::Libro(const Libro& l) : Pubblicazione(l) , ISBN{l.ISBN}, casaEditrice{l.casaEditrice}{}

void Libro::print() const {
    std::cout << "Pubblicazione :\n"
    << "Titolo: "<<getTitolo() << "\n"
    <<"Autori: "<<getAutori()<< "\n"
    <<"AnnoPubblicazione: "<< getAnnoPubblicazione() << "\n"
    <<"Tipologia: LIBRO \n"
    <<"ISBN: "<< ISBN << "\n"
    <<"Casa Editrice: "<< casaEditrice << "\n";
}
