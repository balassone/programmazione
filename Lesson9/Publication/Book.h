#ifndef BOOK_H
#define BOOK_H
#include "Publication.h"

class Book: public Publication {
public:
    static int nBooks;
    Book(std::vector<std::string>, std::string, int, std::string, std::string);
    ~Book();
    std::string toString();
private:
    std::string ISBN;
    std::string publisher;        
};

#endif