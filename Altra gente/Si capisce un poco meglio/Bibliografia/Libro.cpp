//Libro.cpp
#include"Libro.h"
#include<sstream>
#include<string>
using std::string;
using std::vector;
using std::ostringstream;

//Constructor
Libro::Libro(string ti, vector<string> au, int yr, string casa, string isbn) : Pubblicazione(ti, au, yr) {
    casa_editrice=casa;
    ISBN=isbn;
}

//set & get functions

//Casa editrice
void Libro::setCasaEditrice(string& casa){
    casa_editrice=casa;
}
string Libro::getCasaEditrice() const {
    return casa_editrice;
}

//ISBN
void Libro::setISBN(string& isbn){
    ISBN=isbn;
}
string Libro::getISBN() const {
    return ISBN;
}

string Libro::toString()  {
    ostringstream out;
    out<<Pubblicazione::toString()<<"Casa editrice: "<<casa_editrice<<" - ISBN: "<<ISBN<<"\n";
    out.str();
    return out.str();
}
