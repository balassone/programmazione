//Libro.h
#include<string>
#include<vector>

#ifndef BOOK_H                         //guardie di inclusione
#define BOOK_H

class Book {
    public:                                                             
        Book(std::string = "0000", std::vector<std::string> = {" - "}, std::string = " ", int = 0, std::string = "- ", double = 0.0);          //constructor
        
        //set functions
        void setBookID(const std::string&);
        void setAuthors(const std::vector<std::string>&);
        void setTitle(const std::string&);
        void setYear(int);
        void setPosition(const std::string&);
        void setValue(double);

        //getfunctions
        const std::string& getBookID() const;
        const std::vector<std::string>& getAuthors() const;
        const std::string& getTitle() const;
        int getYear() const;
        const std::string& getPosition() const;
        double getValue() const;

        bool operator<(const Book&);
        bool operator ==(const Book&);
        bool operator !=(const Book&);

        std::string toString() const;                                                   //print book informations

    private:
        std::string book_id;
        std::vector<std::string> authors;
        std::string title;
        int year;
        std::string position;
        double value;
};

#endif