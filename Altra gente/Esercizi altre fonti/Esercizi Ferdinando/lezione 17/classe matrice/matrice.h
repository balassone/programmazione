#ifndef MATRICE_H
#define MATRICE_H

class Matrice{

public:
    //costruttore
    Matrice(int,int);
    //Big Three
    Matrice(const Matrice&); //Costruttore copia
    ~Matrice(); //Distruttore
    Matrice& operator=(const Matrice&); //Overloading operatore di assegnazione
    //Overloading degli operatori
    Matrice operator+(const Matrice&);
    Matrice operator-(const Matrice&);
    Matrice operator*(const Matrice&);
    //funzioni set e get
    Matrice& setMatrice(int,int,double); //setta un valore della matrice
    double getMatrice(int,int); //restituisce un valore in una determinata posizione della matrice



private:
    int numeroRighe;
    int numeroColonne;
    double** array;
    //rappresento la matrice come un array di puntatori a double
    /*
    [r1]--->[c1,...,cn]
    [r2]--->[c1,...,cn]
    [r3]--->[c1,...,cn]
    ...................
    [rn]--->[c1,...,cn]
    */
};

#endif