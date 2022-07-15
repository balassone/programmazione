#include"City.h"
#include"Rilevatore.h"


City::City(int r, int c){
    righe=r;
    colonne=c;
    vect= new Rilevatore*[righe];
    for(int i=0; i<righe; i++){
       vect[i]= new Rilevatore[colonne];
    }
}

City::City(const City& citta){
    righe=citta.righe;
    colonne=citta.colonne;
    vect= new Rilevatore*[citta.righe];
     for(int i=0; i<righe; i++){
       vect[i]= new Rilevatore[colonne];
    }
        for(int i=0; i<righe; i++){
            for(int j=0; i<colonne; j++){
                vect[i][j]=citta.vect[i][j];
            }
        }
}

City& City::operator=(const City& citta){
    if(this==&citta){
        return *this;
    } else {
    righe=citta.righe;
    colonne=citta.colonne;
    vect= new Rilevatore*[citta.righe];
     for(int i=0; i<righe; i++){
       vect[i]= new Rilevatore[colonne];
    }
        for(int i=0; i<righe; i++){
            for(int j=0; i<colonne; j++){
                vect[i][j]=citta.vect[i][j];
            }
        }
    }
    return *this;
}

double City::meanCO2Zone(Date d1, Date d2, int coordx1, int coordx2, int coordy1, int coordy2){
    int mx = (coordx1 < coordx2) ? mx=coordx1 : mx=coordx2;
    int MX=(coordx1 > coordx2) ? MX=coordx1 : MX=coordx2;
    int my=(coordy1 < coordx2) ? my=coordy1 : my=coordy2;
    int MY=(coordy1 > coordx2) ? MY=coordy1 : MY=coordy2;

    for(int i=mx; i<MX; i++){
        for(int j=my; j<MY; j++){
        }
    } 
}



