//Pubblicazione.cpp

#include <iostream>
#include <vector>
#include <string>
#include "Pubblicazione.h"

std::string Pubblicazione::getAutori()const{
    std::string auth = "";
    for(int i =0; i<autori.size(); i++){auth = auth + autori[i]+ ", ";}
    return auth;}
Pubblicazione::Pubblicazione(const Pubblicazione& p){
    titolo = p.titolo;
    autori = p.autori;
    annoPubblicazione = p.annoPubblicazione;
}
std::string Pubblicazione::getTitolo() const{return titolo;}
int Pubblicazione::getAnnoPubblicazione() const{return annoPubblicazione;}
void Pubblicazione::print() const {
    std::cout << "Pubblicazione :\n"
    << "Titolo: "<<titolo << "\n"
    <<"Autori: ";
    for(int i=0; i<autori.size(); i++) std::cout <<autori[i]<< ", ";
    std::cout <<  "\n"
    <<"AnnoPubblicazione: "<< annoPubblicazione<<"\n"
    <<"Tipologia: INDEFINITA"; 
}


bool operator<(const Pubblicazione &lhs, const Pubblicazione &rhs){
    if(lhs.autori < rhs.autori){return true;}
    if(lhs.autori == rhs.autori && lhs.annoPubblicazione < rhs.annoPubblicazione){return true;}
    return false;

}


