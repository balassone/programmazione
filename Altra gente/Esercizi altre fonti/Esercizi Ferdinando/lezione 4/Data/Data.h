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

    std::string Display() const;
    
    //overloading operator <
    bool operator<(const Data&);
	
private:
    int giorno;
    int mese;
    int anno;
};

#endif
