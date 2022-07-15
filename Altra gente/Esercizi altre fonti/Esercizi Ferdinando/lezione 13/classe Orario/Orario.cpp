#include "Orario.h"
#include <iostream>
#include <exception>
#include <sstream>
#include <iomanip>
#include <string>
using std::string;
using std::ostringstream;
using std::setw;
using std::setfill;
using std::invalid_argument;

Orario::Orario(int h,int m,int s){
    setOrario(h,m,s);
}

void Orario::setOrario(int h,int m,int s){
    if(h>=0 && h<24){
        ora=h;
    }
    else
        throw invalid_argument("L'ora inserita è fuori range");
    if(m>=0 && m<60){
        minuti=m;
    }
    else 
        throw invalid_argument("I minuti inseriti sono fuori range");
    if(s>=0 && s<60){
        secondi=s;
    }
    else 
        throw invalid_argument("I secondi inseriti sono fuori range");
}

string Orario::getUniversalOrario() const{
    ostringstream out;
    out<<setw(2)<<setfill('0')<<ora<<":"<<setw(2)<<setfill('0')<<minuti<<":"<<setw(2)<<setfill('0')<<secondi;
    return out.str();
}

string Orario::getAmericanOrario() const{
    ostringstream out;
    int americanHour;
    americanHour=(ora>12)? ora%12 : ora;
    string meridian=(ora>12)? "p.m":"a.m";
    out<<setw(2)<<setfill('0')<<americanHour<<":"<<setw(2)<<setfill('0')<<minuti<<":"<<setw(2)<<setfill('0')<<secondi
    <<" "<<meridian;
    return out.str();
}