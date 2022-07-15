#ifndef DATA_H
#define DATA_H

#include <string>

class Orario{

public:
    //costruttore 
    explicit Orario(int = 0,int = 0,int = 0);
    //set Data
    void setOrario(int,int,int);
    //get Data: formato 24h
    std::string getUniversalOrario() const;
    //get Data: formato 12 h
    std::string getAmericanOrario() const;

private:
    int ora;
    int minuti;
    int secondi;
};

#endif