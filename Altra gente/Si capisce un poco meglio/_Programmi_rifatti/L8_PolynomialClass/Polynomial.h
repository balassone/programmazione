//Polynomial.h
#include<iostream>
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {
    friend bool operator==(const Polynomial&, const Polynomial&);

    public:
        //constructors
        Polynomial();
        Polynomial(double[], int);
        explicit Polynomial(double const_term);
        //copy constructor
        Polynomial(const Polynomial&);

        //destructor
        ~Polynomial();

        //assignment operators
        Polynomial& operator=(const Polynomial&);
        Polynomial& operator+=(const Polynomial&);
        Polynomial& operator*=(double);
        Polynomial& operator*=(const Polynomial&);              //product betweeen polynomials

        //named member functions
        int degree() const {return size-1;}
        void print(std::ostream& out= std::cout) const;

    private:
        int size;
        double* coefs;
        
};

Polynomial operator+(const Polynomial&, const Polynomial&);
Polynomial operator*(const Polynomial&, double);
Polynomial operator*(double, const Polynomial&);
Polynomial operator*(const Polynomial&, const Polynomial&);

std::ostream& operator<<(std::ostream&, const Polynomial&);

#endif