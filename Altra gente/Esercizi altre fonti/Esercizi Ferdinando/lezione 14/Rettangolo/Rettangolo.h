#ifndef RETTANGOLO_H
#define RETTANGOLO_H

#include "Punto.h"
#include <string>

class Rettangolo{

public:
    //Costruttore
    Rettangolo(Punto=Punto(0.0,0.0),Punto=Punto(0.0,0.0),Punto=Punto(0.0,0.0),Punto=Punto(0.0,0.0),char='-',char='*');
    //set coordinate
    void setCoordinate(Punto,Punto,Punto,Punto);
    void setCaratterePerimetro(char);
    void setCarattereRiempimento(char);
    std::string getCoordinate() const;
    char getCaratterePerimetro() const;
    char getCarattereRiempimento() const;
    //funzioni memebro
    double baseRettangolo() const;
    double altezzaRettangolo() const;
    double perimetroRettangolo() const;
    double areaRettangolo() const;
    bool quadrato() const;

private:
    Punto p1;
    Punto p2;
    Punto p3;
    Punto p4;
    char c1; //carattere perimentro
    char c2; //carattere riempimento
};

#endif