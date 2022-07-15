#include"Rilevamento.h"

Rilevamento::Rilevamento(Date& d, double p){
    setData(d);
    setPPM(p);
}

void Rilevamento::setData(Date& d){
    dataril=d;
}

void Rilevamento::setPPM(double p){
    ppm=p;
}

Date Rilevamento::getData()const{
    return dataril;
}

double Rilevamento::getPPM()const{
    return ppm;
}


