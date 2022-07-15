//Complex.h
#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H


class Complex {
    // friend functions
    friend bool operator == (Complex &lhs, Complex &rhs);
    friend bool operator > (Complex lhs, Complex rhs);
    friend bool operator < (Complex lhs, Complex rhs);
    friend bool operator >= (Complex lhs, Complex rhs);
    friend bool operator <= (Complex lhs, Complex rhs);
    friend Complex operator * (const Complex &lhs, double rhs);
    friend Complex operator * (double lhs, const Complex &rhs);
    friend Complex operator + (const Complex &lhs, double rhs);
    friend Complex operator + (double lhs, const Complex &rhs);
    friend Complex operator - (const Complex &lhs, double rhs);
    friend Complex operator - (double lhs, const Complex &rhs);
    friend Complex operator / (const Complex &lhs, double rhs);
    friend Complex operator / (double lhs, const Complex &rhs);

    ~Complex();
    Complex();
    explicit Complex(double r = 0.0, double i = 0.0): real{r}, imaginary{i} {}
    Complex(const &Complex num);
    double getReal() const;
    double getImaginary() const;
    void print(ostream & out = cout) const;
    friend std::ostream& operator << (std::ostream& os, Complex num);

    //operators
    Complex& operator++(); //prefix
    Complex operator++(double) //postfix
    Complex& operator = (const Complex &rhs);
    Complex& operator -= (const Complex &rhs);
    Complex& operator += (const Complex &rhs)
    Complex operator +(const Complex &rhs) const;
    Complex operator - (const Complex &rhs) const;
    //std::string getEuleroForm();
    //std::string getExponentialForm();
    //Complex& coniugate(const Complex &term);
    


    


    private:
    double real{0.0};
    double imaginary{0.0};
}





