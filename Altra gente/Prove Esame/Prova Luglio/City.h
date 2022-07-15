#ifndef CITY_H
#define CITY_H
#include"Rilevatore.h"

//La città e’ divisa in quartieri secondo una matrice 20x20, 
//ogni elemento della matrice corrisponde ad un quartiere della città

class City{
    public:
    City(int=20,int=20);

    //Big Three
    City(const City&);
    ~City();
    City& operator=(const City&);
    double meanCO2Zone(Date d1, Date d2, int coordx1, int coordx2, int coordy1, int coordy2);


    private:
    int righe;
    int colonne;
    Rilevatore** vect;



};

#endif