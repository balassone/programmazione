//Borrow.cpp
#include "Borrow.h"
#include<string>
#include<sstream>
using std::string;

//constructor that takes 2 parameters in and sets restitutionDate to borrowDate+30
Borrow::Borrow(const Book& b, const Date& d) : book(b), borrowDate(d) {
    restitutionDate = borrowDate + 30;
} 

//constructor
Borrow::Borrow(const Book& b, const Date& d1, const Date& d2) : book(b), borrowDate(d1), restitutionDate(d2) {}

//set functions
void Borrow::setBook(const Book& b){
    book = b;
}

void Borrow::setBorrowDate(const Date& d) {
    borrowDate = d;
}

void Borrow::setRestitutionDate(const Date& d){
    restitutionDate = d;
}

//get functions
const Book& Borrow::getBook() const {
    return book;
}

const Date& Borrow::getBorrowDate() const {
    return borrowDate;
}

Date Borrow::getRestitutionDate() const {
    return restitutionDate;
}

//overloading operator <
bool Borrow::operator<(const Borrow& b) {
    return restitutionDate < b.restitutionDate;
}

//overloading operator !=
bool Borrow::operator!=(const Borrow& borrow) {
    if((book != borrow.book) || (borrowDate != borrow.borrowDate) || (restitutionDate != borrow.restitutionDate)){
        return true;
    }
    return false;
}

//overloading operator ==
bool Borrow::operator==(const Borrow& borrow) {
    return (!(this->operator!=(borrow)));
}


//print Borrow with toString
string Borrow::toString() const {
    std::ostringstream out;
    out<<book.toString()
    <<"\nBorrow date: "<<borrowDate
    <<"\nRestitution date: "<<restitutionDate<<"\n";
    return out.str();
}

//friend overloaded <<
std::ostream& operator<<(std::ostream& out, const Borrow& b) {
    out<<b.book.toString()
    <<"\nBorrow date: "<<b.borrowDate
    <<"\nRestitution date: "<<b.restitutionDate<<"\n";
    return out;
}