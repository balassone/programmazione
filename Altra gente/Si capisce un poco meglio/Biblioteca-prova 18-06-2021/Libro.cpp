//Libro.cpp
//Implementazione della classe Libro

#include"Libro.h"
#include<stdexcept>
#include<sstream>

using std::string;
using std::vector;
using std::invalid_argument;

//Constructor (uso le funzioni set per inizializzare le variabili membro così da validare anche se necessario)
Libro::Libro(string id, vector<string> au, string ti, int yr, string pos, double val) {
    setBookID(id);
    setAuthors(au);
    setTitle(ti);
    setYear(yr);
    setPosition(pos);
    setValue(val);
}

Libro* Libro::operator=(Libro* l){
    if (this == l){
        return this;
    }
    else {
        delete this;
        Libro* libro = new Libro[sizeof(l)];
        *this = *l;
    }
}

//overloading operator<
bool Libro::operator<(const Libro& lib) const {
    if (this->authors< lib.authors){
        return true;
    }
    if(this->authors==lib.authors){
        return (this->year < lib.year);
    }
}
/*
//copy constructor
Libro :: Libro(Libro& lib){
    book_id=lib.book_id;
    authors = lib.authors;
    title = lib.title;
    position = lib.position;
    value = lib.value;
    
}

//operator=
Libro& Libro ::operator=(Libro& lib){
    if (this == &lib){
        return *this;
    }
    

}
*/

//Set & get functions

//ID
void Libro::setBookID(string& id){
    book_id=id;
}
string Libro::getBookID() const {
    return book_id;
}

//Authors
void Libro::setAuthors(vector<string>& au){
    authors=au;
}
vector<string> Libro::getAuthors() const {
    return authors;
}

//Title
void Libro::setTitle(string& ti){
    title=ti;
}
string Libro::getTitle() const {
    return title;
}

//Year
void Libro::setYear(int yr){
    if (yr>2021){
        throw invalid_argument("Year can't be > 2021.");
    }
    else year=yr;
}
int Libro::getYear() const{
    return year;
}

//Position
void Libro::setPosition(string& pos) {
    position=pos;
}
string Libro::getPosition() const{
    return position;
}

//Value
void Libro::setValue(double val){
    if (val<0){
        throw invalid_argument("Book value must be >0");
    }
    else value=val;
}
double Libro::getValue() const{
    return value;
}


string Libro::toString() {
    std::ostringstream out;
    out<<"ID: "<<book_id<<"\n";
    out<<"Autori: ";
    for (size_t i=0; i<((authors.size())-1); i++){
        out<<authors[i]<<", ";
    }
    out<<authors[(authors.size())-1];
    
    out<<"\nTitolo: "<<title<<"\nAnno di pubblicazione: "<<year<<"\n"<<"Valore ($): "<<value<<"\n"<< "Posizione :"<<position<<"\n\n";
    return out.str();
}