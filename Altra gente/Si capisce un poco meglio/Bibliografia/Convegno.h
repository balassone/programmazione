//Convegno.h
#ifndef CONVEGNO_H
#define CONVEGNO_H
#include<string>
#include"Pubblicazione.h"
using std::string;

class Convegno : public Pubblicazione {
    public:
        Convegno(string, vector<string>, int, string, string, int);     //constructor
        
        //set & get functions
        void setTitoloConvegno(string&);
        string getTitoloConvegno() const;
        
        void setSedeConvegno(string&);
        string getSedeConvegno() const;

        void setNumPagConv(int);
        int getNumPagConv() const;

        virtual string toString() ;

    private:
        string titoloConvegno;
        string sedeConvegno;
        int numPagConv;
};

#endif