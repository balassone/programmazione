//Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    public:
    //constructors
    Matrix(int=3,int=3);
    //the Big Three
    Matrix(const Matrix&); //copy constructor
    ~Matrix();
    Matrix& operator=(const Matrix&);

    //operators
    Matrix& operator+(const Matrix&);
    Matrix& operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    
    //get and set operators
    Matrix& setValue(int, int, double); //setta i valori della matrice e restituisce la nuova matrice
    double getValue(int,int); //restituisce il valore della matrice in una certa posizione

    private:
        int nrow;
        int ncol;
        double** array;
};




#endif