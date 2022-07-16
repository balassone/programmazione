#include "Rilevatore.h"

Rilevatore::Rilevatore(int id, int xx, int yy) :id_station{id} {
    if(xx>=0 && xx<20) x=xx;
    if(yy>=0 && yy<20) y=yy;
}

Rilevatore::Rilevatore(const Rilevatore& r){
    id_station=r.id_station;
    x=r.x;
    y=r.y;
    rilevamenti=r.rilevamenti;
}

Rilevatore& Rilevatore::operator=(const Rilevatore& r){
    id_station=r.id_station;
    x=r.x;
    y=r.y;
    rilevamenti=r.rilevamenti;
    return *this;
}

Rilevatore& Rilevatore::setID(const int& id){
    id_station=id;
    return *this;
}

const int& Rilevatore::getID() const{
    return id_station;
}

Rilevatore& Rilevatore::setX(const int& xx){
    if(xx>=0 && xx<20) x=xx;
    return *this;
}

const int& Rilevatore::getX() const{
    return x;
}

Rilevatore& Rilevatore::setY(const int& yy){
    if(yy>=0 && yy<20) y=yy;
    return *this;
}

const int& Rilevatore::getY() const{
    return y;
}

Rilevatore& Rilevatore::add(const Date& dat, const int&pm){
    Rilevamento ril{dat,pm};
    std::list<Rilevamento>::const_iterator p;
    for(p=rilevamenti.begin(); p!=rilevamenti.end(); ++p){
        if(!(p->getDate()<dat)){
            rilevamenti.insert(p,ril);
            break;
        }
    }
    return *this;
}