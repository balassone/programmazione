#include "City.h"

City::City(int r,int c)
    : righe{r},colonne{c} {
        quartiere=new int*[righe];
        for(int i=0;i<righe;++i){
            quartiere[i]=new int[colonne];
        }
        for(int i=0;i<righe;++i){
            for(int j=0;j<colonne;++j){
                quartiere[i][j]=0;
            }
        }
    }

City::~City(){
    for(int i=0;i<righe;++i){
        delete[] quartiere[i];
    }
    delete[] quartiere;
}

City::City(const City& c)
    : righe{c.righe}, colonne{c.colonne} {
        quartiere=new int*[c.righe];
        for(int i=0;i<righe;++i){
            quartiere[i]=new int[c.colonne];
        }
        for(int i=0;i<righe;++i){
            for(int j=0;j<colonne;++j){
                quartiere[i][j]=c.quartiere[i][j];
            }
        }
    }

City& City::operator=(const City& c){
    if(this==&c){
        return *this;
    }
    else{
        righe=c.righe;
        colonne=c.colonne;
        for(int i=0;i<righe;++i){
            delete[] quartiere[i];
        }
        delete[] quartiere;
        quartiere=new int*[righe];
        for(int i=0;i<righe;++i){
            quartiere[i]=new int[colonne];
        }
        for(int i=0;i<righe;++i){
            for(int j=0;j<colonne;++j){
                quartiere[i][j]=c.quartiere[i][j];
            }
        }
        return *this;
    }
}

City& City::setQuartiere(int i,int j,int k){
    quartiere[i][j]=k;
    return *this;
}

