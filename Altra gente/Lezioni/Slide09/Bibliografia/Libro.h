#ifndef LIBRO_H
#define LIBRO_H
#include "Pubblicazione.h"
#include <string>

class Libro : public Pubblicazione
{
private:
    int ISBN;
    std::string casaEditrice;
public:
    Libro();
    Libro(const std::string&, const std::vector<std::string>&, int, int, const std::string&);
    Libro(const Libro& l);
    virtual ~Libro();
    void print() const ;
};



#endif