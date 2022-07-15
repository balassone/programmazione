#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <vector>
#include <string>

class Libro{

public:
    Libro(int=0,const std::vector<std::string>& ={""},const std::string& =" ",int =0,const std::string& =" ",double=0.0);
    ~Libro() = default;
    //set and get functions
    void setBookID(int);
    void setAuthors(const std::vector<std::string>&);
    void setTitle(const std::string&);
    void setYear(int);
    void setPosition(const std::string&);
    void setValue(double);
    int getBookID() const;
    std::string getAuthors() const;
    std::string getTitle() const;
    int getYear() const;
    std::string getPosition() const;
    double getValue() const;

    bool operator<(const Libro&);
    std::string toString() const;

private:
    int book_id;
    std::vector<std::string> authors;
    std::string title;
    int year;
    std::string position;
    double value;
};

#endif