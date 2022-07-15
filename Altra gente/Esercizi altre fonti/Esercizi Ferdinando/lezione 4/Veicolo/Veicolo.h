#ifndef VEICOLO_H
#define VEICOLO_H

#include <string>

class Veicolo{

public:
    //Costruttore
    Veicolo(std::string = " ",std::string = " ",int = 0,std::string = " ",int = 0);
    //funzioni set e get
    void setMarca(std::string);
    void setTipoCarburante(std::string);
    void setAnnoProduzione(int);
    void setColore(std::string);
    void setPotenza(int);
    std::string getMarca() const;
    std::string getTipoCarburante() const;
    int getAnnoProduzione() const;
    std::string getColore() const;
    int getPotenza() const;

    void getInformazioni() const;

private:
    std::string marca;
    std::string tipoCarburante;
    int annoProduzione;
    std::string colore;
    int potenza;
};

#endif