#ifndef DATA_H
#define DATA_H

#include <string>

class Data{

public:
    //Costruttore
    Data(int = 1,int = 1,int = 1900);
    //Funzioni set e get
    void setGiorno(int);
    void setMese(int);
    void setAnno(int);
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;

    bool operator<(const Data&);
    std::string Display() const;

private:
    int giorno;
    int mese;
    int anno;
};

#endif