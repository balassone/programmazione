//Book.h
#ifndef BOOK_H
#define BOOK_H
#include"Publication.h"
#include<string>
#include <vector>
#include<sstream>
using std::string;
using std::vector;

class Book : public Publication {
    public:
        static int nBooks;
        Book(string ti, vector<string> au, int yr, string pub, string is) : Publication(ti, au, yr), Publisher(pub), ISBN(is) {
            ++nBooks;
        };
        ~Book(){--nBooks;}
        string toString(){
            std::ostringstream out;
            out<<Publication::toString() << ". ";
            out<<Publisher<<", "<< ISBN;
            return out.str();
        }
    private:
        string Publisher;
        string ISBN;
};

#endif