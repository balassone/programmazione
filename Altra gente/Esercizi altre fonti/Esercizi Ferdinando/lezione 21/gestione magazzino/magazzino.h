#ifndef MAGAZZINO_H
#define MAGAZZINO_H

#include <string>

class Magazzino{
public:
    //Costruttore
    Magazzino(int = 0,const std::string& ="",int = 0,double = 0.0);
    // funzioni set e get
    void setCodice(int);
    void setNome(const std::string&);
    void setQuantita(int);
    void setPrezzo(double);
    int getCodice() const;
    std::string getNome() const;
    int getQuantita() const;
    double getPrezzo() const;

private:
    int codiceArticolo;
    char nome[15];
    int quantita;
    double prezzo;
};

#endif