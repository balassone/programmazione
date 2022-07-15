//matrix.h 
//definition of a Matrix class
#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H
class Matrix{
public:
    explicit Matrix(int row = 2, int column = 2);    
    Matrix(int row, int column, double** mat);    //basic constructor
    Matrix(const Matrix &mat);            //copy constructor
    ~Matrix();                      //destructor

    //operators
    Matrix operator*(const Matrix& rhs); 
    Matrix operator-(const Matrix& rhs);
    Matrix operator+(const Matrix& rhs);
    Matrix& operator= (const Matrix& rhs);  //between two matrix
        //addition between matrix
    //friend Matrix operator+(double, Matrix&);
   // friend Matrix operator+(Matrix&, double);
    
    int getNumberOfRows() const;
    int getNumberOfColumns() const;
    //double getElement(int row, int column);
    void print();
    double*& operator [] (const int i) const ;


private:    //stores the rows, the columns and the matrix itself
int rows; 
int columns;
double **matrix;

//private functions
void matrixImplementation();    //Implements the matrix for the constructors
void matrixDeletion();          //deletes the matrix for the destructor and the '=' operator


};

    

#endif