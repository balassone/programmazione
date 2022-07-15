#include "matrice.h"
#include <iostream>
#include <exception>
using std::cout;
using std::endl;
using std::invalid_argument;

Matrice::Matrice(int righe,int colonne){
    numeroRighe=righe;
    numeroColonne=colonne;
    array=new double*[numeroRighe]; //alloco spazio in memoria per contenere numeroRighe array di puntatori a double
    for(int i=0;i<numeroRighe;++i){
        array[i]=new double[numeroColonne]{}; //per ogni riga alloco spazio in memoria per conentere numeroColonne puntatori a double inizializzati a 0    
    }
}

Matrice::Matrice(const Matrice& mat){
    numeroRighe=mat.numeroRighe;
    numeroColonne=mat.numeroColonne;
    array=new double*[numeroRighe];
    for(int i=0;i<numeroRighe;++i){
        array[i]=new double[numeroColonne];
    }
    for(int i=0;i<numeroRighe;++i){
        for(int j=0;j<numeroColonne;++j){
            array[i][j]=mat.array[i][j];
        }
    }
}

Matrice::~Matrice(){
    for(int i=0;i<numeroRighe;++i){
        delete[] array[i];
    }
    delete[] array;
}

Matrice& Matrice::operator=(const Matrice& mat){
    if(this==&mat){
        return *this;
    }
    else{
        for(int i=0;i<numeroRighe;++i){
            delete[] array[i];
        }
        delete[] array;
        numeroRighe=mat.numeroRighe;
        numeroColonne=mat.numeroColonne;
        array=new double*[mat.numeroRighe];
        for(int i=0;i<numeroRighe;++i){
            array[i]=new double[mat.numeroColonne];
        }
        for(int i=0;i<numeroRighe;++i){
            for(int j=0;j<numeroColonne;++j){
                array[i][j]=mat.array[i][j];
            }
        }
        return *this;
    }
}

Matrice Matrice::operator+(const Matrice& mat){
    Matrice nuovaMatrice(this->numeroRighe,this->numeroColonne);
    if(numeroRighe==mat.numeroRighe && numeroColonne==mat.numeroColonne){
        for(int i=0;i<numeroRighe;++i){
            for(int j=0;j<numeroColonne;++j){
                nuovaMatrice.array[i][j]=array[i][j]+mat.array[i][j];
            }
        }
        return nuovaMatrice;
    }
    else 
        throw invalid_argument("Le due matrici devono avere le stesse dimesioni");
}

Matrice Matrice::operator-(const Matrice& mat){
    Matrice nuovaMatrice(this->numeroRighe,this->numeroColonne);
    if(numeroRighe==mat.numeroRighe && numeroColonne==mat.numeroColonne){
        for(int i=0;i<numeroRighe;i++){
            for(int j=0;j<numeroColonne;++j){
                nuovaMatrice.array[i][j]=array[i][j]-mat.array[i][j];
            }
        }
        return nuovaMatrice;
    }
    else 
        throw invalid_argument("Le due matrici devono avere le stesse dimensioni");
}

Matrice Matrice::operator*(const Matrice& mat){
    if(numeroColonne==mat.numeroRighe){
        Matrice nuovaMarice(numeroRighe,mat.numeroColonne);
        for(int i=0;i<nuovaMarice.numeroRighe;++i){
            for(int k=0;k<nuovaMarice.numeroColonne;++k){
                nuovaMarice.array[i][k]=0.0;
                for(int j=0;j<numeroColonne;++j){
                    nuovaMarice.array[i][j]+=array[i][j]*mat.array[j][k];
                }
            }
        }
        return nuovaMarice;
    }
    else
        throw invalid_argument("Le due matrici devono essere compatibili");

}

Matrice& Matrice::setMatrice(int r,int c,double x){
        array[r][c]=x;
        return *this;
}

double Matrice::getMatrice(int r,int c) {
        return array[r][c];
}