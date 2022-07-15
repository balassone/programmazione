//Book.cpp
#include"Book.h"
#include<sstream>
using std::string;
using std::vector;
#include<iomanip>

//constructor
Book::Book(string ID, vector<string> Au, string ti, int anno, string pos, double val) :
book_id(ID), authors(Au), title(ti), year(anno), position(pos) {
    setValue(val);
}

// set functions

void Book::setBookID(const string& ID) {
    book_id = ID;
}

void Book::setAuthors(const vector<string>& au) {
    authors = au;
}

void Book::setTitle(const string& ti){
    title = ti;
}

void Book::setYear(int anno) {
    year = anno;
}

void Book::setPosition(const string& pos) {
    position = pos;
}

//validate value
void Book::setValue(double val){
    if (val>0.0){
        value = val;
    }
    else value = 0.0;
}

//get functions
const string& Book::getBookID() const{
    return book_id;
}
const vector<string>& Book::getAuthors() const {
    return authors;
}
const string& Book::getTitle() const {
    return title;
}

int Book::getYear() const{
    return year;
}
const string& Book::getPosition() const{
    return position;
}
double Book::getValue() const{
    return value;
}

//overloading operator<
bool Book::operator<(const Book& b){
    if (this->authors[0] < b.authors[0]){
        return true;
    }
    if (this->authors[0] == b.authors[0]){
        return year<b.year;
    }
    return false;
}

//overloading operator ==
bool Book::operator ==(const Book& b) {
    if (getBookID() == b.getBookID() && getAuthors() == b.getAuthors() && getTitle() == b.getTitle() && getYear() == b.getYear() && getPosition() == b.getPosition() && getValue() == b.getValue()){
        return true;
    }
    return false;
}

//overloading operator !=
bool Book::operator !=(const Book& b){
    return !(*this == b);
}


string Book::toString() const{
    std::ostringstream out;
    out<<"\nBook ID: "<<book_id;
    out<<"\nAuthors: ";
    for (size_t i=0; i<authors.size(); i++){
        out<<authors[i];
        out<< ((i < (authors.size()-1)) ? ", " : " ");
    }
    out<<"\nTitle: "<<title
    <<"\nYear: "<<year
    <<"\nPosition: "<<position
    <<"\nValue: "<<std::showpoint<<std::fixed<<std::setprecision(2)<<value<<"$";
    return out.str();
}   


