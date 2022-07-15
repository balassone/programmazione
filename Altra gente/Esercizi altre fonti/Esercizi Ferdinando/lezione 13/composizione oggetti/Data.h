#ifndef DATA_H
#define DATA_H

#include <string>

class Data{

public:
    //Costruttore
    Data(int=1,int=1,int=1900); //Costruttore di default
    //Funzioni set e get
    void setData(int,int,int);
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;

    std::string getData() const;

private:
    int giorno;
    int mese;
    int anno;
    bool checkGiorno(int,int,int);
};

#endif