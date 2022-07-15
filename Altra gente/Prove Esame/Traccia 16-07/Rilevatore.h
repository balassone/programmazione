#ifndef RILEVATORE_H
#define RILEVATORE_H

#include "City.h"
#include <list>
#include "Rilevamento.h"

class Rilevatore{
public:
    Rilevatore(int=0,int=0,int=0,const std::list<Rilevamento>& = {});
    
    void setCoordx(int);
    void setCoordy(int);
    void setIdStation(int);
    void setList(const std::list<Rilevamento>&);
    void addRilevamento(const Rilevamento&);

private:
    int coord_x;
    int coord_y;
    int id_station;
    City BlueSky;
    std::list<Rilevamento> rilevazioni;
};
#endif