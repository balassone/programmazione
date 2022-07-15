#include "Rilevamento.h"
#include <string>
using std::string;

Rilevamento::Rilevamento(const Data& d,double co2){
    setDataRilevamento(d);
    setCO2(co2);
}

void Rilevamento::setDataRilevamento(const Data& d){
    dataRilevamento=d;
}

void Rilevamento::setCO2(double co2){
    CO2=co2;
}

string Rilevamento::getDataRilevamento() const {
    return dataRilevamento.Display();
}

double Rilevamento::getCO2() const{
    return CO2;
}

bool Rilevamento::operator<(const Rilevamento& ril){
    if(dataRilevamento<ril.dataRilevamento) return true;
    else return false;
}

