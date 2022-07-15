//Pubblicazione.h

#ifndef PUBBLICAZIONE_H
#define PUBBLICAZIONE_H

#include<string>
#include<vector>
using std::vector;
using std::string;

class Pubblicazione{
    public:
        Pubblicazione(string, vector<string>, int=1800);          //constructor

        //set & get function
        void setTitolo(string&);
        string getTitolo() const;

        void setAutori(vector<string>&);
        vector<string> getAutori() const;
        
        void setAnno(int);
        int getAnno() const;

        bool operator<(const Pubblicazione&);

        virtual string toString();

    private:
        std::string titolo;
        vector<string> autori;
        int anno;

};

#endif