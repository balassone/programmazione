#include "Book.h"
#include<string>
#include<vector>
#include<sstream>
Book::Book(std::vector<std::string> au, std::string ti, int yr, std::string is, std::string pub):
Publication(au,ti,yr), ISBN(is), publisher(pub){++nBooks;}

Book::~Book(){--nBooks;}

std::string Book::toString(){
    std::ostringstream out;
    out << Publication::toString() << " " << ISBN << publisher << "."; //Applico l'opeeratore di scopo per scegliere che funzione invocare
    return out.str();
}