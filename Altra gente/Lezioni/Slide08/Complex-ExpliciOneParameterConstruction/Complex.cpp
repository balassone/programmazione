//complex.cpp

#include <iostream>
#include "Complex.h"

using std::cout;
using std::ostringstream;


bool operator ==(Complex &lhs, Complex &rhs){return lhs.real == rhs.real && lhs.imaginary == lhs.imaginary;}
bool operator >(Complex &lhs, Complex &rhs){return lhs.real > rhs.real && lhs.imaginary > lhs.imaginary;}
bool operator <(Complex &lhs, Complex &rhs){return lhs.real < rhs.real && lhs.imaginary < lhs.imaginary;}
bool operator >=(Complex &lhs, Complex &rhs){return lhs.real >= rhs.real && lhs.imaginary >= lhs.imaginary;}
bool operator <=(Complex &lhs, Complex &rhs){return lhs.real >= rhs.real && lhs.imaginary >= lhs.imaginary;}

Complex operator * (const Complex &lhs, double rhs){
    Complex answer{lhs};
    answer.real *= rhs;
    return answer;
}
Complex operator * (double lhs, const Complex &rhs){
    Complex answer{rhs};
    answer.real *= lhs;
    return answer;
}

Complex operator + (const Complex &lhs, double rhs){
    Complex answer{lhs};
    answer.real += rhs;
    return answer;
}
Complex operator + (double lhs, const Complex &rhs){
    Complex answer{rhs};
    answer.real += lhs;
    return answer;
}
Complex operator - (const Complex &lhs, double rhs){
    Complex answer{lhs};
    answer.real -= rhs;
    return answer;
}
Complex operator - (double lhs, const Complex &rhs){
    Complex answer{rhs};
    answer.real -= lhs;
    return answer;
}
Complex operator / (const Complex &lhs, double rhs){
    Complex answer{lhs};
    answer.real = answer.real / rhs;
    return answer;
}
Complex operator / (double lhs, const Complex &rhs){
    Complex answer{rhs};
    answer.real = answer.real / lhs;
    return answer;
}

Complex::~Complex(){}
Complex::Complex(): real{0.0}, imaginary{0.0}{}
Complex::Complex(double r, double i): real{r}, imaginary{i} {}
Complex::Complex(const &Complex num){
    real = num.real;
    imaginary = num.imaginary;
}
double Complex::getReal() const {return real;}
double Complex::getImaginary() const {return imaginary;}
void print(ostream & out) const {
    out << real << (imaginary > 0 )? " " : " - " << imaginary << "j";
}
Complex::Complex& operator++(){
    real++;
    return *this;
}

Complex::Complex operator+(double){
    Complex temp{*this};
    ++temp.real;
    return temp;
}



