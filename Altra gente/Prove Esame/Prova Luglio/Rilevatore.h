#ifndef RILEVATORE_H
#define RILEVATORE_H

#include"RilevList.h"

#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

/*I rilevatori di CO2, mantenuti in un vettore, 
sono distribuiti in diversi quartieri, 
le informazioni di ciascun rivelatore sono: 
id_station (intero), coord_x (intero), coord_y(intero) 
e una lista di rilevamenti mantenuta in ordine di data di rilevamento
*/


class Rilevatore{
    public:
    Rilevatore() : id{0}, coordx{0}, coordy{0}{RilevList rilevamenti;}
    Rilevatore(int, int, int, RilevList&);
    //Big Three
    Rilevatore(const Rilevatore&);
    ~Rilevatore();
    Rilevatore& operator=(const Rilevatore&);

    void setId(int);
    void setCx(int);
    void setCy(int);
    void setList(RilevList&);

    Rilevatore& operator[](int);

    int getId()const;
    int getCx()const;
    int getCy()const;
    RilevList& getLista()const;

    void addMeasurement(const Rilevamento&);

    double meanCO2Rilevator(Date d1, Date d2);


    private:
    int id;
    int coordx;
    int coordy;
    RilevList rilevamenti;

};


#endif