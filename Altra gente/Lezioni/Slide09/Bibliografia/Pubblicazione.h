#ifndef PUBBLICAZIONE_H
#define PUBBLICAZIONE_H

#include <string>
#include <vector>
#include <algorithm>

class Pubblicazione{

    public:
    Pubblicazione() : titolo{" "}, autori{" "}, annoPubblicazione{1900} {}
    Pubblicazione(const std::string &titolo, const std::vector<std::string> &authors, int anno)
     : titolo{titolo} , annoPubblicazione{anno}, autori{authors} {}
    Pubblicazione(const Pubblicazione&);
    virtual ~Pubblicazione() {
        titolo.erase();
        autori.clear();
        autori.shrink_to_fit();
    } 
    virtual void  print() const;
    std::string getAutori()const;
    std::string getTitolo() const;
    int getAnnoPubblicazione() const;


    friend bool operator<(const Pubblicazione &lhs, const Pubblicazione &rhs);


    private:
    std::string titolo;
    std::vector<std::string> autori;
    int annoPubblicazione;
};


#endif