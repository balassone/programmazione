//Libro.h

#ifndef LIBRO_H
#define LIBRO_H
#include"Pubblicazione.h"
using std::string;

class Libro : public Pubblicazione {
    public:
        Libro(string, vector<string>, int, string, string);     //constructor
        
        //set & get functions
        void setCasaEditrice(string&);
        string getCasaEditrice() const;

        void setISBN(string&);
        string getISBN() const;
        
        virtual string toString() ;

    private:
        string casa_editrice;
        string ISBN;

};

#endif
