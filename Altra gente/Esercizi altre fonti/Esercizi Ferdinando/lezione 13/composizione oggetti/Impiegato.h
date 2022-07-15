#ifndef IMPIEGATO_H
#define IMPIEGATO_H

#include "Data.h"
#include <string>

class Impiegato{

public:
    //Costruttore
    Impiegato(std::string,std::string,int,int,int);
    //set e get
    void setNome(std::string);
    void setCognome(std::string);
    void setDataAssunzione(int,int,int);
    std::string getNome() const;
    std::string getCognome() const;
    std::string getDataAssunzione() const;

private:
    std::string nome;
    std::string cognome;
    Data dataAssunzione;
};

#endif