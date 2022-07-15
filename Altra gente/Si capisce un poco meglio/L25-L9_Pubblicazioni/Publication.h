//Publication.h
#ifndef PUBLICATION_H
#define PUBLICATION_H
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
using std::vector;
using std::cout;
using std::ostringstream;

class Publication{
    public:
        //constructor
        Publication(std::string ti, vector<std::string> au, int yr) : title{ti}, authors{au}, year{yr} {}
        
        //get and set functinos
        void setTitle(std::string ti){
            title=ti;
        }
        std::string getTitle() const{
            return title;
        }
        void setAuthors(vector<std::string> au){
            authors=au;
        }
        vector<std::string> getAuthors() const{
            return authors;
        }
        void setYear(int yr){
            year=yr;
        }
        int getYear() const {
            return year;
        }
        //overloading of operator <
        bool operator<(const Publication& B) {
            if (authors == B.getAuthors()){
                return year < B.getYear();
            }
            return authors<B.authors;
        }
        virtual std::string toString(){
            ostringstream out;
            out<<"-\t";
            for (int i=0; i<authors.size(); i++){
                out<<authors[i];
                out<<((i==(authors.size()-1))? " " : ", "); 
            }
            out<<"("<<year<<"): "<<title;
            return out.str();
        }

    private:
        std::string title;
        vector<std::string> authors;
        int year;
};

#endif