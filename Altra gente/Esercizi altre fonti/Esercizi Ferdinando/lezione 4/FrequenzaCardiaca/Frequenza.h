#ifndef FREQUENZA_H
#define FREQUENZA_H

#include <string>
#include "Data.h"

class Frequenza{

public:
    //Costruttore
    Frequenza(std::string = " ",std::string = " ",int=0,int=0,int=0);
    //set e get
    void setNome(std::string);
    void setCognome(std::string);
    void setData(int,int,int);
    std::string getNome() const;
    std::string getCognome() const;
    std::string getData() const;

    int eta();
    double frequenzaCardiacaMax();
    std::string frequenzaCardiacaTar();

    
private:
    std::string nome;
    std::string cognome;
    Data DataNascita;




};














#endif