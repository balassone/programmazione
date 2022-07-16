#include "Rilevamento.h"

Rilevamento::Rilevamento(const Date& d, const int& pm): data{d}, ppm{pm} {}


Rilevamento& Rilevamento::operator=(const Rilevamento& r){
    data=r.data;
    ppm=r.ppm;
    return *this;
}

Rilevamento& Rilevamento::setDate(const Date& d){
    data=d;
    return *this;
}

const Date& Rilevamento::getDate() const{
    return data;
}

Rilevamento& Rilevamento::setPPM(const int& p){
    ppm=p;
    return *this;
}

int Rilevamento::getPPM() const{
    return ppm;
}