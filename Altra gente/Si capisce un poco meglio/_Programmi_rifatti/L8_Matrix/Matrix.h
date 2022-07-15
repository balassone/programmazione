//Matrix.h
//class interface
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {

    public:
        //constructor
        Matrix(int=3,int=3);
        
        //THE BIG THREE
        // 1) destructor
        ~Matrix();

        // 2) copy constructor
        Matrix(const Matrix&);

        // 3) assignment (operator=)
        Matrix& operator=(const Matrix&);

        //overloaded operators +=, - and *
        Matrix& operator+(const Matrix&);
        Matrix& operator-(const Matrix&);
        Matrix operator*(const Matrix&);

        //set value of Matrix
        Matrix& setValue(int, int, double);
        //get value of Matrix
        double getValue(int,int) const;


    private:
        int nrows;
        int ncols;
        double** elements;
};


#endif