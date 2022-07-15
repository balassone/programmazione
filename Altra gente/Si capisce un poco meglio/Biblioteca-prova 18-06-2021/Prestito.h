//Prestito.h
//interfaccia della classe Prestito
#ifndef BORROW_H
#define BORROW_H

#include"Libro.h"
#include"Date.h"                //composizione di classi: la classe Prestito.h
                                //farà uso delle funzionalità della classe Date.h
#include<sstream>

class Prestito {
    public:
        //Constructor
        Prestito(Libro&, Date, Date);
        Prestito();

        //set & get functions
        //Book
        void setBook(Libro&);
        Libro getBook() const;

        //borrow Date
        void setBorrowDate(Date&);
        Date getBorrowDate() const;

        //restitution Date
        void setRestitutionDate(Date&);
        Date getRestitutionDate() const;

        //overloading operator <
        bool operator<(Prestito&);

        //toString function
        string toString();

    private:
        Libro book;
        Date borrowDate;
        Date restitutionDate;
    

};


#endif