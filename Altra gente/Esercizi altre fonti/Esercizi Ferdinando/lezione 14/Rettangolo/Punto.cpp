#include "Punto.h"
#include <iostream>

Punto::Punto(double coordx,double coordy){
    setX(coordx);
    setY(coordy);
}

void Punto::setX(double coordx){
        x=coordx;
    }

void Punto::setY(double coordy){
        y=coordy;
    }

double Punto::getX() const{
    return x;
}

double Punto::getY() const{
    return y;
}
