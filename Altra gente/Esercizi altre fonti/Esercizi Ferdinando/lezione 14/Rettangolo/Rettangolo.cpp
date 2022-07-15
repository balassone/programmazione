#include "Rettangolo.h"
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
using std::string;
using std::ostringstream;
using std::invalid_argument;
using std::cout;

Rettangolo::Rettangolo(Punto punto1,Punto punto2,Punto punto3,Punto punto4,char car1,char car2){
    setCoordinate(punto1,punto2,punto3,punto4);
    setCaratterePerimetro(car1);
    setCarattereRiempimento(car2);
}

void Rettangolo::setCoordinate(Punto punto1,Punto punto2,Punto punto3,Punto punto4){
    if((punto1.getX()==punto3.getX()) && (punto2.getX()==punto4.getX()) && (punto1.getY()==punto2.getY()) && (punto3.getY()==punto4.getY()) && (punto1.getX()<punto2.getX()) && (punto1.getY()<punto3.getY())){
        p1=punto1;
        p2=punto2;
        p3=punto3;
        p4=punto4;
    }
    else 
        throw invalid_argument("I punti inseriti non possono formare un rettangolo");
}

void Rettangolo::setCaratterePerimetro(char car1){
    c1=car1;
}

void Rettangolo::setCarattereRiempimento(char car2){
    c2=car2;
}

string Rettangolo::getCoordinate() const{
    ostringstream out;
    out<<"("<<p1.getX()<<","<<p1.getY()<<")";
    out<<"("<<p2.getX()<<","<<p2.getY()<<")";
    out<<"("<<p3.getX()<<","<<p3.getY()<<")";
    out<<"("<<p4.getX()<<","<<p4.getY()<<")";
    return out.str();
}

char Rettangolo::getCaratterePerimetro() const{
    return c1;
}

char Rettangolo::getCarattereRiempimento() const{
    return c2;
}

double Rettangolo::baseRettangolo() const{
    return p2.getX()-p1.getX();
}

double Rettangolo::altezzaRettangolo() const{
    return p3.getY()-p1.getY();
}

double Rettangolo::perimetroRettangolo() const{
    return 2*baseRettangolo()+2*altezzaRettangolo();
}

double Rettangolo::areaRettangolo() const{
    return baseRettangolo()*altezzaRettangolo();
}

bool Rettangolo::quadrato() const{
    if(baseRettangolo()==altezzaRettangolo()){
        return true;
    }
    return false;
}
