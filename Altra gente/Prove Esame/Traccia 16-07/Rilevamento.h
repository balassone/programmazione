#ifndef RILEVAMENTO_H
#define RILEVAMENTO_H

#include "Data.h"
#include <string>

class Rilevamento{

public:
    Rilevamento(const Data&,double);
    
    void setDataRilevamento(const Data&);
    void setCO2(double);
    std::string getDataRilevamento() const;
    double getCO2() const;

    bool operator<(const Rilevamento&); 

private:
    Data dataRilevamento;
    double CO2;
};

#endif