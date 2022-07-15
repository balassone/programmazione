#include "Rilevatore.h"
#include "list"
#include <iostream>
#include <exception>
using std::invalid_argument;
using std::list;


Rilevatore::Rilevatore(int x,int y,int id,const list<Rilevamento>& ril){
    setCoordx(x);
    setCoordy(y);
    setIdStation(id);
    BlueSky.setQuartiere(coord_x,coord_y,id_station);
    setList(ril);
}


void Rilevatore::setCoordx(int x){
    if(x>0 && x<=20) coord_x=x;
    else{
        throw invalid_argument("La coord_x è fuori range");
    }
}

void Rilevatore::setCoordy(int y){
    if(y>0 && y<=20) coord_y=y;
    else{
        throw invalid_argument("La coord_y è fuori range");
    }
}

void Rilevatore::setIdStation(int id){
    id_station=id;
}

void Rilevatore::setList(const list<Rilevamento>& ril){
    rilevazioni=ril;
}

void Rilevatore::addRilevamento(const Rilevamento& ril){
    rilevazioni.push_front(ril);
    rilevazioni.sort();

}

