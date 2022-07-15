#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

class Data{
friend Data operator+(const Data&,int);
friend Data operator+(int,const Data&);
friend std::ostream& operator<<(std::ostream&,Data&);

public:
    //Costruttore 
    Data(int=1,int=1,int=1900);
    //funzioni set e get
    void setData(int,int,int);
    static const int mesiAnno{13};
    //Overloading degli operatori
    bool operator<(Data&);
    bool operator==(const Data&);
    bool operator>(const Data&);
    bool operator>=(const Data&);
    bool operator<=(const Data&);
    bool operator!=(const Data &);
    Data& operator++();
    Data& operator+=(int);
    Data& operator-(int);
    std::string getData() const;
  

private:
    int giorno;
    int mese;
    int anno;
    bool validaGiorno(int,int,int);
    void helpSomma(int);
    void helpDifferenza(int);
};


#endif