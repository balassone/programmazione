//Prestito.h
#include"Book.h"
#include"Date.h"
#include<iostream>
#ifndef PRESTITO_H
#define PRESTITO_H

class Borrow {
    friend std::ostream& operator<<(std::ostream&, const Borrow&);
    public:
        Borrow(const Book& = Book(), const Date& = Date());                                                   //constructor
        Borrow(const Book&, const Date&, const Date&);           //constructor
        //set functions
        void setBook(const Book&);
        void setBorrowDate(const Date&);
        void setRestitutionDate(const Date&);
        //get functions
        const Book& getBook() const;
        const Date& getBorrowDate() const;
        Date getRestitutionDate() const;

        bool operator<(const Borrow&);
        bool operator !=(const Borrow&);
        bool operator ==(const Borrow&);

        std::string toString() const;
    private:
        Book book;
        Date borrowDate;
        Date restitutionDate; 
};

#endif