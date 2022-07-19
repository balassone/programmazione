#include "Matrix.h"
#include<ostream>
#include<stdexcept>
#include <iostream>
Matrix::Matrix(const int& npeople): n(npeople){
	p=new int*[n];
	for(int i=0;i<n;i++){
		p[i]=new int[n];
	}
	//Inizializzo con zeri: azzero tutte le amicizie che saranno opportunamente popolate nella classe Community
	for(int i{0}; i<n; i++){
		for(int j{0}; j<n; j++){
			p[i][j]=0;
		}
	}
}
//Costruttore copia base
Matrix::Matrix(const Matrix& mat) : n(mat.n) {
	p=new int*[n];
	for(int i{0}; i<n; ++i){
		p[i] = new int[n];
	}

	for(int i{0}; i<n; ++i){
		for(int j{0}; j<n; ++j){
			setNumber(i,j,mat.p[i][j]);
		}
	}

}
//Distruttore, sarà chiamato automaticamente quando il contenitore viene distrutto
Matrix::~Matrix(){
	for(int i{0}; i<n; ++i){
		delete[] p[i];
	}
	delete[] p;
}
//Operatore di assegnazione, controlla che la matrice non sia la stessa, la dealloca e opportunamenteo la rialloca.
Matrix& Matrix::operator=(const Matrix& mat){
	if(this==&mat){
		return *this;
	}
	else{
		for(int i{0}; i<n; ++i){
			delete[] p[i];
		}
		delete[] p;

		n=mat.n;

		p = new int*[n];
		for(int i=0; i<n; ++i){
			p[i]=new int[n];
		}

		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				setNumber(i,j,mat.p[i][j]);
			}
		}
		return *this;
	}
}

Matrix& Matrix::setNumber(const int& i, const int& j, const int& num){
	if(i<0 || i>=n || j<0 || j>=n){
		throw std::out_of_range("Indice non valido");
	} else {
		p[i][j]=num;
	}
	return *this;
}
//Preferibile const int& piuttosto che int per evitare shallow copy (int occupa solo 4byte, ma su sistemi poco capienti potrebbe fare la differenza)
const int& Matrix::getNumber(int i, int j) const{
	if(i<0 || i>=n || j<0 || j>=n){
		throw std::out_of_range("Indice non valido");
	} else {
		return p[i][j];
	}
}
//Overloading dell'operatore << per facilitare notevolmente la stampa. Dichiarato friend per poter accedere alle variabili private
std::ostream& operator<<(std::ostream& out, const Matrix& mat){
	for(int i=0; i<mat.n; ++i){
		for(int j=0; j<mat.n; ++j){
			out << mat.getNumber(i,j) << "\t";
		}
		out << std::endl;
	}
	return out;
}
