#ifndef PUBBLICAZIONE_H
#define PUBBLICAZIONE_H

#include "Data.h"
#include <string>
#include <vector>

class Pubblicazione{

public:
    Pubblicazione(const std::string&,const std::vector<std::string>,const Data&);
    //funzioni set e get
    void setTitolo(const std::string&);
    void setAutori(const std::vector<std::string>);
    void setData(const Data&);
    std::string getTitolo() const;
    std::string getAutori() const;
    std::string getData() const;
    //overloadind dell'operatore <
    bool operator<(const Pubblicazione&);

    virtual std::string toString() const;

protected:
    std::string titolo;
    std::vector<std::string> autori; //definisco gli autori come un vettore di stringhe //questo perchè ci possono essere anche più autori
    Data annoPubblicazione;

};

#endif