#include <iostream>
#include "polynomial.h"

// Constructor 
// Creates a default polynomial p of the form p(x) = 0.0
Polynomial::Polynomial(): size{1}, coefs{new double[1]} {coefs[0] = 0.0;}

// Constructor
// Ginven an array of coefficients C ( and it's size N ) creates a polynomial 
// p(x) = c[N-1] x^(n-1) + ... + C[2]xˆ2+ C[1]x+C[0]
Polynomial::Polynomial(double coefficients[], int number) :
	size{number}, coefs {new double[number]} {
		for (int i{0}; i<size; i++) {
			coefs[i] = coefficients[i];
		}
}

// Constructor
// Given a constant term A, creates the polynomial p(x) = A
Polynomial::Polynomial(double const_term) : size{1}, coefs{new double[1]} {coefs[0] = const_term;}

// the big three

// Copy cnstructor
// creates a polynomial from the given polynmia
Polynomial::Polynomial(const Polynomial & rhs) : size{rhs.size}, coefs{new double [rhs.size]} {
	for (int i{0}; i< size; i++)
	{
		coefs[i] = rhs.coefs[i];
	}
}

// destructor
Polynomial::~Polynomial() {delete [] coefs;}

// overload assignment = 
Polynomial & Polynomial::operator=( const Polynomial & rhs) {
	if (this == &rhs) {return *this;}
	else {
		delete [] coefs; 
		coefs = new double[rhs.size];
		size = rhs.size;
		for (int i{0}; i < size; i++) {
			coefs[i] = rhs.coefs[i];
		}
	}
	return *this;
}

// overloaded operators ( member functions) 

// overloaded assignemnt +=

Polynomial & Polynomial::operator+=(const Polynomial &rhs) {
	int newSize = (rhs.size > size) ? rhs.size : size;
	double *newCoef = new double [newSize];
	
	for( int i = 0; i < newSize; i++) {
		newCoef[i] = 0;
	}
	for (int i = 0; i < rhs.size; i++) {
		newCoef[i] += rhs.coefs[i];
	}
	for (int i = 0; i<size; i++){
		newCoef[i] += coefs[i];
	}
	delete [] coefs;
	coefs = newCoef;
	size = newSize;
	return *this;
}

// Overloaded assignment *= so it supports scalar multiplication
Polynomial & Polynomial::operator*=(double rhs){
	for (int i{0}; i< size; i++){
		coefs[i] *= rhs;
	}
	return *this;
}

//Overloaded operators (non-member functions)

// Overload +

Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs) {
	Polynomial answer{lhs};
	answer += rhs;
	return answer;	
}

// Overload * so it suports scalar multiplication. Note that we overload it twise so we can do either
// polynomial * scalar 	or 	scalar * polynomial

Polynomial operator* (const Polynomial & lhs, double rhs) {
	Polynomial answer{lhs};
	answer *= rhs;
	return answer;
}	

Polynomial operator*(double lhs, const Polynomial & rhs) {
	Polynomial answer{rhs};
	answer *= lhs;
	return answer;
}

// Overloading I/O

// prints the polynomial to the given ostream

void Polynomial::print(std::ostream & out) const {
	if (size == 0) {return;}
	
	for (int i=size-1; i>0;i--){out << coefs[i] << "x^" << i << "+";}
	out << coefs[0];	
}

// overload << for output
std::ostream & operator<<(std::ostream & out, const Polynomial & p) {
	p.print(out);
	return out;
}



// relational operator ==

bool operator==( const Polynomial & lhs, const Polynomial & rhs) {
	if (lhs.size != rhs. size) {return false;}
	
	for (int i = 0; i< lhs.size; i++) {
		if (lhs.coefs[i] != rhs.coefs[i]) {return false;}
	}
	return true;
}


// exercise
// overload * operator between two polynomials
Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs){
	int newSize = (lhs.degree()+rhs.degree()+1);
	double *newCoefs = new double[newSize]{0};
	/*
	for(int i = 0; i< newSize; i++){
		if(i == 0){
			newCoefs[i] = lhs.coefs[i] * rhs.coefs[i];
		}
		else if(i <= lhs.degree() && i <= rhs.degree() && i != 0){
			int k = 0;
			while(k <= i){
				newCoefs[i] += lhs.coefs[i-k]*rhs.coefs[k];
				k++;
				
			}
			
		}
		else if((i > lhs.degree() || i > rhs.degree()) && i+1 < newSize){
			int maxDegree = (rhs.degree() > lhs.degree())? rhs.degree() : lhs.degree();
			int k = i-maxDegree;
			int j = 0;
			while((k+j) <= maxDegree){
				newCoefs[i] += (maxDegree = rhs.degree())?
					lhs.coefs[maxDegree-j]*rhs.coefs[k+j] : lhs.coefs[k+j]*rhs.coefs[maxDegree-j];
				j++;
			}
		}
		else{
		newCoefs[i] = lhs.coefs[lhs.size -1] * rhs.coefs[rhs.size -1];
		}
		
	}
	*/
	for (int i = 0; i<newSize; i++)
    	newCoefs[i] = 0;
 
   // Multiply two polynomials term by term
 	// Take ever term of first polynomial
   for (int i=0; i<lhs.size; i++)
   {
     // Multiply the current term of first polynomial
     // with every term of second polynomial.
     for (int j=0; j<rhs.size; j++)
         newCoefs[i+j] += lhs.coefs[i]*rhs.coefs[j];
   }
	Polynomial answer{newCoefs, newSize};
	return answer;
}
