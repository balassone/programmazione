//Prestito.cpp
//Implementazione classe Prestito

#include"Libro.h"
#include"Prestito.h"

using std::string;
using std::vector;

//costruttore (usa i costruttori di Libro e Date)
Prestito::Prestito(Libro& lib, Date d, Date r) : book(lib), borrowDate(d), restitutionDate(r) {}

Prestito::Prestito() {
    book;
    borrowDate;
    restitutionDate;
}

//set & get functions 
void Prestito::setBook(Libro& l){
    book.setBookID(l.book_id);
    book.setAuthors(l.authors);
    book.setTitle(l.title);
    book.setYear(l.year);
    book.setPosition(l.position);
    book.setValue(l.value);
}

void Prestito::setBorrowDate(Date& d){
    borrowDate.setDate(d.day, d.month, d.year);
}
Date Prestito::getBorrowDate() const {
    return borrowDate;
}

 //restitution Date
 void Prestito:: setRestitutionDate(Date& d){
    restitutionDate+=30;
} 

Date Prestito:: getRestitutionDate() const {
    return restitutionDate;
}

string Prestito:: toString() {
    std::ostringstream out;
    out<<book.toString()<<"borrowed in "<<borrowDate<<", has to be given back in "<<restitutionDate<<"\n\n\n";
    return out.str();
}

bool Prestito::operator<(Prestito& p){
    return (this->restitutionDate < p.restitutionDate);
}