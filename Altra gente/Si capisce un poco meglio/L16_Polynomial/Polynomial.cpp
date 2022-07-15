#include<iostream>
#include "Polynomial.h"

//Constructor
//Creates a default polynomial p of the form p(x)=0.0
Polynomial::Polynomial(): size{1}, coefs{new double[1]} {
    coefs[0]=0.0;
}

//Constructor
//Given an array of coefficients and its size creates a polynomial
//p(x)=C[N-1]x^(N-1)+C[N-2]x^(N-2)+...+C[0]
Polynomial::Polynomial(double coefficients[], int number): size{number}, coefs{new double[number]} {
    for (int i=0; i<size; i++) {
        coefs[i]= coefficients[i];
    }
}

//Constructor
//Given a constant term A creates the polynomial p(x)=A
Polynomial::Polynomial(double const_term) : size{1}, coefs{new double[1]} {
    coefs[0]=const_term;
}

//****THE BIG THREE*****
//1
//Copy constructor
//Creates a polynomial from the given polynomial
Polynomial::Polynomial(const Polynomial & rhs) : size{rhs.size}, coefs{new double[rhs.size]} {
    for (int i=0; i<size; i++) {
        coefs[i]=rhs.coefs[i];
    }
}

//2
//Destructor
Polynomial::~Polynomial () {
    delete [] coefs;
}

//3
//Overload assignment =
Polynomial & Polynomial::operator=(const Polynomial & rhs) {
    if (this==&rhs) {
        return *this;
    }
    else {
        delete[] coefs; //Faccio spazio in memoria ed elimino lo spazio allocato per il vettore prima della copia
        coefs=new double [rhs.size];
        for (int i=0; i<size; i++) {
            coefs[i]=rhs.coefs[i];
        }
    }
    return *this;
}

//Overload assignment += 
Polynomial & Polynomial::operator+=(const Polynomial & rhs) {
    int newSize=(rhs.size>size) ? rhs.size:size; //calcolo il massimo tra le 2 dimensioni
    double* newCoef=new double[newSize];
    //inizializzo a 0 esplicitamente il vettore che voglio creare; potevo anche mettere delle parentesi graffe vuote più semplicemente
    for (int i=0; i<newSize; i++) {
        newCoef[i]=0;
    }
    for (int i=0; i<rhs.size; i++) {
        newCoef[i]+=rhs.coefs[i];
    }
    for (int i=0; i<size; i++) {
        newCoef[i]+=coefs[i];
    }
    delete[] coefs;
    coefs=newCoef;
    size=newSize;
    return* this;
}

Polynomial & Polynomial::operator*=(double rhs) {
    for (int i=0; i<size; i++) {
        coefs[i]*=rhs;
    }
    return* this;
}

//Overload ==
bool operator==(const Polynomial & lhs, const Polynomial & rhs){
    if(lhs.size!=rhs.size) {
        return false;
    }
    for (int i=0; i<lhs.size; i++) {
        if (lhs.coefs[i]!=rhs.coefs[i]) {
            return false;
        }
    }
    return true;
}

//Overload + per la somma di 2 polinomi
//Si sfrutta la funzione membro già definita +=, motivo per cui questa non accede alle variabili membro della classe

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial answer{lhs}; //viene invocato il copy constructor
    answer+=rhs;
    return answer;
}

//Overload * (scalar*polynomial o polynomial*scalar)
Polynomial operator*(const Polynomial& lhs, double rhs) {
    Polynomial answer{lhs};
    answer *= rhs;
    return answer;
}
Polynomial operator*(double lhs, const Polynomial & rhs){
    Polynomial answer{rhs};
    answer *= lhs;
    return answer;
}

//prints the polynomial to the given ostream; it's a member function
void Polynomial::print(std::ostream & out) const {
    if (size==0) {
        return;
    }
    for (int i=size-1; i>0; i--) {
        out<<coefs[i]<<"x^"<<i<<" + ";
    }
    out<<coefs[0]; //evita di stampare x^0
}
//Overload << for output
std::ostream & operator<<(std::ostream& out, const Polynomial & p) {
    p.print(out);
    return out;
}