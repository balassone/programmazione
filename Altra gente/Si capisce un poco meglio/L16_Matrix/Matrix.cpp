//Matrix.cpp
#include"Matrix.h"
#include<stdexcept>

//constructor
Matrix::Matrix(int r, int c){
    nrow=r;
    ncol=c;
    //alloco spazio per contenere una matrice di dimensione (nrow,ncol)
    array=new double* [nrow]; //in questo modo istanzio un vettore che contiene tanti puntatori a double quante
                              //sono le righe; ora per ciascuno degli elementi double* (ovvero per ciascuna riga)
                              //alloco memoria. In pratica vedo una matrice come un vettore di righe dove ogni riga punta alle c colonne che sono qu quella riga;
                              //quindi ho r righe tutte lunghe c elementi, ovvero il numero di colonne della matrice
    for (int i=0; i<r; ++i) {
         array[i]= new double[ncol]{}; //inizializzo anche a 0 ogni elemento con {}
    }
}
//Copy Constructor
Matrix::Matrix(const Matrix& m ) {
    nrow=m.nrow;
    ncol=m.ncol;
    //allocate memory
    array=new double* [m.nrow];
    for (int i=0; i<nrow; ++i) {
        array[i]=new double[ncol];  
    }
    for (int i=0; i<nrow;++i) {
        for (int j=0; j<ncol;++j) {
            array[i][j]=m.array[i][j];
        }
    }
}

//Destructor
//cancello gli elementi al contrario (--> prima le colonne e poi le righe)
Matrix::~Matrix() {
    for (int i=0; i<nrow; ++i){
        delete[] array[i];
    }
    delete[] array;
}

//Operator =
Matrix& Matrix::operator=(const Matrix& m) {
    if (this == &m) {
        return *this;
    }
    //release memory
    for (int i=0; i< nrow; ++i) {
        delete[] array[i];
    }
    delete[] array;

    nrow=m.nrow;
    ncol=m.ncol;
    array=new double* [m.nrow];
    for (int i=0; i<nrow; ++i) {
        array[i]=new double[m.ncol];
    }
    for (int i=0; i<nrow; ++i) {
        for (int j=0; j<ncol;++j) {
            array[i][j]=m.array[i][j];
        }
    }
    return *this;
} 
//Operator +
Matrix& Matrix::operator+(const Matrix& m){
    if (ncol==m.ncol && nrow==m.nrow) {
        for (int i=0; i<m.nrow; ++i){
            for (int j=0;j<m.ncol;++j) {
                array[i][j]+=m.array[i][j];
            }
        }
        return *this;
    }
    else throw std::invalid_argument ("Matrix 1 and 2 must have the same number of rows and columns");
}

Matrix Matrix::operator*(const Matrix&m){
    if(ncol!=m.nrow) {
        throw std::invalid_argument("Matrix must be compatible");
    }
    Matrix newMat(nrow,m.ncol); 
    for (int i=0; i<newMat.nrow;++i){
        for (int k=0;k<newMat.ncol;k++) {
            //compute the scalar product between row i of object and column k
            newMat.array[i][k]=0.0;
            for (int j=0; j<ncol;++j){
                newMat.array[i][k]+=array[i][j]*m.array[j][k];
            }
        }
    }
    return newMat; //non posso restituire un riferimento poiché newMat viene eliminato alla fine della funzione
}

/*
        *   *   *                       *   *
        *   *   *       *   *           *   *
        *   *   *       *   *    ==     *   *
        *   *   *       *   *           *   *

        (4,3)           (3,2)           (4,2)
*/

//Operator -
Matrix& Matrix::operator-(const Matrix& m){
    if (ncol==m.ncol && nrow==m.nrow) {
        for (int i=0; i<m.nrow; ++i){
            for (int j=0;j<m.ncol;++j) {
                array[i][j]=array[i][j]-m.array[i][j];
            }
        }
        return *this;
    }
    else throw std::invalid_argument ("Matrix 1 and 2 must have the same number of rows and columns");
}

//Set e get
Matrix& Matrix::setValue(int n, int m, double value) {
    //dovremmo anche effettare il check che n ed m siano indici compresi nella matrice
    array[n][m]=value;
    return *this;
}

double Matrix::getValue(int n, int m) {
    return array[n][m];
}