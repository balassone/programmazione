//Polynomial.cpp
#include"Polynomial.h"
using std::cout;
using std::ostream;

//constructors
Polynomial::Polynomial() : size{1}, coefs{new double[1]} {
    coefs[0]=0.0;
}

Polynomial::Polynomial(double coefficients[], int num) : size{num}, coefs{new double[size]} {
    for (int i=0; i<size; i++){
        coefs[i]=coefficients[i];
    }
}

Polynomial::Polynomial(double costante) : size{1}, coefs{new double[size]}{
    coefs[0]=costante;
}

//copy constructor
Polynomial::Polynomial(const Polynomial& pol){
    size = pol.size;
    coefs = new double[pol.size];
    for (int i=0; i<pol.size; i++){
        coefs[i]= pol.coefs[i];
    }
}

//destructor
Polynomial::~Polynomial() {
    delete[] coefs;
}

//assignment operators
Polynomial& Polynomial::operator=(const Polynomial& pol){
    if (this==&pol){
        return *this;
    }
    else {
        delete[] coefs;
        size=pol.size;
        coefs=new double[pol.size];
        for (int i=0; i < pol.size; i++){
            coefs[i]=pol.coefs[i];
        }
    }
    return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& pol){
    int newsize= (pol.size>size) ? pol.size : size;
    double* newCoef = new double[newsize];
    for (int i=0; i<newsize; i++) {
        newCoef[i]= 0;
    }
    for (int i=0; i<size; i++) {
        newCoef[i]+= coefs[i];
    }
    for (int i=0; i<pol.size; i++) {
        newCoef[i]+= pol.coefs[i];
    }
    delete[] coefs;
    size=newsize;
    coefs=newCoef;
    return *this;
}

Polynomial& Polynomial::operator*=(double n){
    for (int i=0; i<size; i++){
        coefs[i]*=n;
    }
    return *this;
}

//product between polynomials
Polynomial& Polynomial::operator*=(const Polynomial& p){
    int newsize=(size-1)+(p.size-1)+1;
    double* newCoef = new double[newsize];
    for (int i=0; i<newsize; i++){
        newCoef[i]=0;
    }
    for (int i=0; i<size; i++){
        for (int j=0; j<p.size; j++){
            for (int k=0; k<newsize; k++){
                if((i+j) == k){
                    newCoef[k]+=(coefs[i]*p.coefs[j]);
                }
            }
        }
    }
    delete[] coefs;
    size=newsize;
    coefs = newCoef;
    return *this;
}

//operator == (friend function)
bool operator==(const Polynomial&  p1, const Polynomial& p2){
    if (p1.size != p2.size){
        return false;
    }

    for (int i=0; i<p1.size; i++){
        if (p1.coefs[i] != p2.coefs[i]) {
            return false;
        }
    }
    return true;
}

//overloaded operators (non-member functions)
Polynomial operator+(const Polynomial& p1, const Polynomial& p2){
    Polynomial sum{p1};
    sum+=p2;
    return sum;
}

Polynomial operator*(const Polynomial& p, double n){
    Polynomial product{p};
    product*=n;
    return product;
}

Polynomial operator*(double n, const Polynomial& p){
    Polynomial product{p};
    product*=n;
    return product;
}

Polynomial operator*(const Polynomial& p1, const Polynomial& p2){
    Polynomial product{p1};
    product*=p2;
    return product;
}

void Polynomial::print(ostream& out) const{
    if (size==0){
        return;
    }

    for (int i=size-1; i>0; i--){
        out<< coefs[i]<<"x^"<<i<<" + ";
    }
    out<<coefs[0];
}

std::ostream& operator<<(std::ostream & out, const Polynomial & p){
    p.print(out);
    return out;
}
