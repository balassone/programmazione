#ifndef CONVEGNO_H
#define CONVEGNO_H

#include "Pubblicazione.h"
#include <string>
#include <vector>

class Convegno: public Pubblicazione{
public:
    Convegno(const std::string&,const std::vector<std::string>,const Data&,const std::string&,int);
    //funzioni set e get
    void setSedeConvegno(const std::string&);
    void setNumeroPagine(int);
    std::string getSedeConvegno() const;
    int getNumeroPagine() const;

    std::string toString() const;

private:
    std::string sedeConvegno;
    int numeroPagine;

};

#endif