//Rivista.h
#ifndef RIVISTA_H
#define RIVISTA_H
#include"Pubblicazione.h"
using std::string;

class Rivista: public Pubblicazione{
    public:
        Rivista(string, vector<string>, int, string, int, int, int); //Constructor

        void setTitoloRivista(string&); 
        string getTitoloRivista() const;

        void setNumRiv(int);
        int getNumRiv() const;

        void setPagIn(int);
        int getPagIn() const;

        void setPagFin(int);
        int getPagFin() const;

        virtual string toString() ;

    private:
        string titoloRivista;
        int numRiv;
        int pagIniziale;
        int pagFinale;

};

#endif