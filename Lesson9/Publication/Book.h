#ifndef BOOK_H
#define BOOK_H
#include "Publication.h"

class Book: public Publication {
public:
    static int nBooks;
    Book(const std::vector<std::string>&, const std::string&, const int&, const std::string&, const std::string&);
    ~Book();
    //get & set
    //...
    std::string toString();
private:
    std::string ISBN;
    std::string publisher;        
};

#endif
