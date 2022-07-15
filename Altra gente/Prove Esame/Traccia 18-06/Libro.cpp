#include "Libro.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::endl;
using std::ostringstream;
using std::vector;
using std::string;
using std::cout;

Libro::Libro(int id,const vector<string>& aut,const string& tit,int yea,const string& pos,double val){
    setBookID(id);
    setAuthors(aut);
    setTitle(tit);
    setYear(yea);
    setPosition(pos);
    setValue(val);
}

void Libro::setBookID(int id){
    book_id=id;
}

void Libro::setAuthors(const vector<string>& aut){
    authors=aut;
}

void Libro::setTitle(const string& tit){
    title=tit;
}

void Libro::setYear(int yea){
    year=yea;
}

void Libro::setPosition(const string& pos){
    position=pos;
}

void Libro::setValue(double val){
    value=val;
}

string Libro::getAuthors() const{
    for(size_t i=0;i<authors.size();i++){
        cout<<authors[i]<<"\t";
    }
}

string Libro::getTitle() const{
    return title;
}

int Libro::getYear() const{
    return year;
}

string Libro::getPosition() const{
    return position;
}

double Libro::getValue() const{
    return value;
}

bool Libro::operator<(const Libro& l){
    if(authors<l.authors) return true;
    else if(authors==l.authors && year<l.year) return true;
    else return false;
}

string Libro::toString() const{
    ostringstream out;
    out<<"Book_id: "<<getBookID()<<endl<<"Authors: "<<getAuthors()<<endl<<"Title: "<<getTitle()<<endl
    <<"Year: "<<getYear()<<endl<<"Position: "<<getPosition()<<endl<<"Value: "<<getValue();
    return out.str();
}
