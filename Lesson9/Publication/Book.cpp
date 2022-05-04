#include "Book.h"
#include<string>
#include<vector>
#include<sstream>
Book::Book(const std::vector<std::string>& au, const std::string& ti, const int& yr, const std::string& is, const std::string& pub):
Publication(au,ti,yr), ISBN(is), publisher(pub) {++nBooks;}

Book::~Book(){--nBooks;}

std::string Book::toString(){
    std::ostringstream out;
    out << Publication::toString() << " " << ISBN << " " << publisher << "."; //Applico l'opeeratore di scopo per scegliere che funzione invocare
    return out.str();
}