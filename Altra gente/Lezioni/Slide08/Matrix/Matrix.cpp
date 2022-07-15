//matrix.cpp
//implementation of a Matrix class

#include <iostream>
#include <stdexcept>

#include "Matrix.h"
using std::cout;


Matrix::Matrix(int row, int column): rows{row}, columns{column}{
    matrixImplementation();
    for(int i=0; i<row;i++){for(int j=0; j<column; j++){matrix[i][j]=0;}}
}
Matrix::Matrix(int row, int column, double** mat): rows{row}, columns{column}{
    matrixImplementation();
    for(int i = 0; i<rows; i++){
        for(int j=0; j<columns; j++)
            {
                matrix[i][j] = mat[i][j];
            }
    }
}

Matrix::Matrix(const Matrix &mat): rows{mat.rows}, columns{mat.columns} {
    matrixImplementation();
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<columns; j++){
            matrix[i][j] = mat.matrix[i][j];
            }
    }
}

Matrix::~Matrix(){
    matrixDeletion();
}

Matrix& Matrix::operator=(const Matrix &rhs){
    matrixDeletion();
    this->rows = rhs.rows;
    this->columns = rhs.columns;
    matrixImplementation();
    for(int i = 0; i<rows; i++){
        for(int j = 0; j <columns; j++){
            matrix[i][j]= rhs.matrix[i][j];
        }
    }
    return *this;
}

//Matrix::double getElement(int row, int column){return matrix[row][column];}

void Matrix::print(){
    cout <<"×";for(int i = 0; i<(columns*3);i++){cout << "-";}cout <<"×\n";
    for(int i=0; i<rows; i++){
        cout << "|";
        for(int j=0; j<columns; j++){
            cout <<matrix[i][j] << " ";
        }
        cout << "|\n";
    }
    cout <<"×";for(int i = 0; i<(columns*3);i++){cout << "-";}cout <<"×\n";
}

void Matrix::matrixImplementation(){
    matrix = new double*[rows];
    for(int i = 0; i<rows; i++){matrix[i] = new double[columns];}
}
void Matrix::matrixDeletion(){
    for (int i=0; i<rows; i++)
      {
           delete[] matrix[i];
        }
        delete[] matrix;
}

Matrix Matrix::operator+(const Matrix& rhs){
    if((this->rows==rhs.rows)&&(this->columns==rhs.columns)){
        Matrix answer(this->rows, this->columns);
        for(int i=0; i<answer.rows; i++){
            for(int j=0; j<answer.columns; j++){
                answer.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
            }
        }
        return answer;
    }
    else {
        throw std::invalid_argument("The two matrixes have different dimensions");
    }
}

Matrix Matrix::operator-(const Matrix& rhs){
    if((this->rows == rhs.rows)&&(this->columns==rhs.columns)){
        Matrix answer(this->rows, this->columns);
        for(int i=0; i<answer.rows; i++){
            for(int j=0; j<answer.columns; j++){
                answer.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
            }
        }
        return answer;
    }
    else {
        throw std::invalid_argument("The two matrixes have different dimensions");
    }
}

Matrix Matrix::operator*(const Matrix& rhs){
    if(this->columns==rhs.rows){
        Matrix answer(this->rows, rhs.columns);
        for(int i=0; i<answer.rows; i++){
            for(int j=0; j<answer.columns; j++){
                for(int k=0; k< this->columns; k++){
                    answer.matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
                }
            }
        }
        return answer;
    }
    else {
        throw std::invalid_argument(" A row dimension and B row dimension doesn't match");
    }
}

double* & Matrix::operator[](const int i) const {
// this operator returns the pointer to a  row
// 
// you can apply the [] operator to this array
// ex. matrixC[1][1]=10;
 
    return matrix[i];
}

int Matrix::getNumberOfRows() const {return rows;}
int Matrix::getNumberOfColumns() const {return columns;}