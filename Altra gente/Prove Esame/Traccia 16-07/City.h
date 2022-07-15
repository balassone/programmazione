#ifndef CITY_H
#define CITY_H

class City{
public:
    City(int = 20,int = 20);
    ~City();
    City(const City&);
    City& operator=(const City&);
    
    City& setQuartiere(int,int,int); //setto un quartiere

private:
    int righe;
    int colonne;
    int** quartiere;
};

#endif