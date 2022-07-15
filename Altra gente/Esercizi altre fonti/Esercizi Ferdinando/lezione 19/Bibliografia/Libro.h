#ifndef LIBRO_H
#define LIBRO_H

#include "Pubblicazione.h"
#include <vector>
#include <string>

class Libro: public Pubblicazione{

public:
    Libro(const std::string&,const std::vector<std::string>,const Data&,const std::string&,const std::string&);
    //funzioni set e get
    void setCasaEditrice(const std::string&);
    void setIsbn(const std::string&);
    std::string getCasaEditrice() const;
    std::string getIsnb() const;

    std::string toString() const;

private:
    std::string casaEditrice;
    std::string ISBN;
};

#endif