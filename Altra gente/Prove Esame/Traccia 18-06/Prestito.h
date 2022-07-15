#ifndef PRESTITO_H
#define PRESTITO_H

#include "Libro.h"
#include "Data.h"
#include <string>

class Prestito{
public:
    Prestito(const Libro&,const Data&);
    void setLibroPrestato(const Libro&);
    void setDataPrestito(const Data&);
    std::string getLibroPrestato() const;
    std::string getDataPrestito() const;

    
    Data& DataRestituzione() const;
    bool operator>(const Prestito&);

private:
    Libro libroPrestato;
    Data dataPrestito;
};


#endif