//Matrix.cpp
#include"Matrix.h"
#include<sstream>

//constructor
Matrix::Matrix(int m, int n) : nrows{m}, ncols{n} {
    elements = new double* [nrows];
    for (int i=0; i<m; i++){
            elements[i] = new double[ncols] {};     //initializing empty matrix
    }
}

//destructor
//erasing first columns and then rows
Matrix::~Matrix() {
    for (int i=0; i<nrows; i++){
        delete[] elements[i];
    }
    delete[] elements;
}

//copy constructor
Matrix::Matrix(const Matrix& mat) {
    nrows=mat.nrows;
    ncols=mat.ncols;
    //allocate memory
    elements = new double* [mat.nrows];
    for (int i=0; i<nrows; i++){
        elements[i] = new double[ncols];
    }
    for (int i=0; i<nrows; i++){
        for (int j=0; j<ncols; j++){
            elements[i][j]=mat.elements[i][j];
        }
    }
}

//operator=
Matrix& Matrix::operator=(const Matrix& mat) {
    if (this==&mat){
        return *this;
    }
    //release memory
    for (int i=0; i<nrows; i++){
        delete[] elements[i];
    }
    delete[] elements;

    nrows=mat.nrows;
    ncols= mat.ncols;
    elements = new double* [nrows];
    for (int i=0; i<nrows; i++){
        elements = new double*[ncols];
        for (int j=0; j<ncols; j++){
            elements[i][j]=mat.elements[i][j];
        }
    }
    return *this;
}

//overloading operator+
Matrix& Matrix::operator+(const Matrix& mat){
    if (ncols == mat.ncols && nrows == mat.nrows) {
        for (int i=0; i<nrows; i++){
            for (int j=0; j<ncols; j++){
                elements[i][j]+=mat.elements[i][j];
            }
        }
        return *this;
    }
    else throw std::invalid_argument("Dimension of matrices has to be the same");
}

//overloading operator-
Matrix& Matrix::operator-(const Matrix& mat){
    if (ncols == mat.ncols && nrows == mat.nrows) {
        for (int i=0; i<nrows; i++){
            for (int j=0; j<ncols; j++){
                elements[i][j]=elements[i][j]-mat.elements[i][j];
            }
        }
        return *this;
    }
    else throw std::invalid_argument("Dimension of matrices must be the same");
}

//overloading operator* (product rows*columns)
Matrix Matrix::operator*(const Matrix& mat){
    if (ncols != mat.nrows){
        throw std::invalid_argument("Product between matrices requires nrows=ncols. Error.");
    }
    Matrix newMat(nrows, mat.ncols);
    
    for (int i=0; i<newMat.nrows; i++){
        for (int k=0; k<newMat.ncols; k++){
            newMat.elements[i][k] = 0.0;
            for (int j=0; j<ncols; j++){
                newMat.elements[i][k] += elements[i][j]*mat.elements[j][k];
            }
        }
    }
    return newMat;
}

//setValue function
Matrix& Matrix::setValue(int i, int j, double val) {
    if (i<nrows && j<ncols){
        elements[i][j] = val;
        return *this;
    }
    else throw std::invalid_argument("out of range");
}

//getValue function
double Matrix::getValue(int i, int j) const {
    return elements[i][j];
}
