#ifndef FATTURA_H
#define FATTURA_H

#include <string>

class Fattura{

public:
    //costruttore
    Fattura(std::string =" ",std::string =" ", int = 0,int = 0, double = 0.2, double = 0.0);
    //funzioni set e get
    void setCodiceArticolo(std::string);
    void setDescrizioneArticolo(std::string);
    void setNumeroArticoli(int);
    void setPrezzoArticolo(int);
    void setIva(double);
    void setScontoArticolo(double);
    std::string getCodiceArticolo() const;
    std::string getDescrizioneArticolo() const;
    int getNumeroArticoli() const;
    int getPrezzoArticolo() const;
    double getIva() const;
    double getScontoArticolo() const;

    double getImportoFattura();

private:
    std::string codiceArticolo;
    std::string descrizioneArticolo;
    int numeroArticoli;
    int prezzoArticolo;
    double IVA;
    double scontoArticolo;
};

#endif