#ifndef RILEVAMENTO_H
#define RILEVAMENTO_H

#include"Date.h"

/* Ogni rilevamento contiene le informazioni sulla data del rilevamento, 
e la quantità di CO2 in parti per milione - ppm (double).*/

class Rilevamento{
    public:
    Rilevamento(Date&, double);

    void setData(Date&);
    void setPPM(double);

    Date getData()const;
    double getPPM()const;






    private:
    Date dataril;
    double ppm;

    
};

#endif