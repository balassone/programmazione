//Libro.h
//Interfaccia della classe libro

#ifndef LIBRO_H         //guardie di inclusione
#define LIBRO_H

#include<string>
#include<vector>
using std::vector;
using std::string;

class Libro {
    
    friend class Prestito; //dichiaro la classe Prestito come friend così che possa usufruire dell'accesso completo alla classe
    
    public:
        
        Libro* operator=(Libro*);

        //Constructor
        Libro(string = " ", vector<string> = {" "}, string = " ", int = 0, string = " ", double = 0.0);
        
        //operator <
        bool operator<(const Libro&) const;


        //set & get functions

        //ID
        void setBookID(string&);
        string getBookID() const;

        //Authors
        void setAuthors(vector<string>&);
        vector<string> getAuthors() const;

        //Title
        void setTitle(string&);
        string getTitle() const;

        //Year
        void setYear(int);
        int getYear() const;

        //Position of book
        void setPosition(string&);
        string getPosition() const;

        void setValue(double);
        double getValue() const;

        string toString(); 
    
    private:
        //variabili membro
        string book_id;
        vector<string> authors;
        string title;
        int year;
        string position;
        double value;

};


#endif