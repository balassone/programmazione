#include "Libro.h"
#include <string>
#include <sstream>
#include <vector>
using std::vector;
using std::ostringstream;
using std::string;
using std::endl;

Libro::Libro(const string& tit,const vector<string> aut,const Data& dat,const string& cas,const string& isbn)
    :Pubblicazione(tit,aut,dat) {
        setCasaEditrice(cas);
        setIsbn(isbn);
    }

void Libro::setCasaEditrice(const string& cas){
    casaEditrice=cas;
}

void Libro::setIsbn(const string& isbn){
    ISBN=isbn;
}

string Libro::getCasaEditrice() const{
    return casaEditrice;
}

string Libro::getIsnb() const{
    return ISBN;
}

string Libro::toString() const{
    ostringstream out;
    out<<Pubblicazione::toString()<<"Casa editrice: "<<casaEditrice<<endl<<"ISBN: "<<ISBN<<endl;
    return out.str();
}
