#include "Matrix.h"
#include<ostream>
#include<stdexcept>
#include <iostream>
Matrix::Matrix(int row, int col)
: n{row}, m{col} {

	p = new double*[n];
	for(int i{0}; i<n; ++i){
		p[i]=new double[m]{};
	}

}

Matrix::Matrix(const Matrix& mat) : n{mat.n}, m{mat.m} {
	
	p=new double*[n];
	for(int i{0}; i<n; ++i){
		p[i] = new double[m];
	}

	for(int i{0}; i<n; ++i){
		for(int j{0}; j<m; ++j){
			setNumber(i,j,mat.p[i][j]);
		}
	}

}

Matrix::~Matrix(){
	for(int i{0}; i<n; ++i){
		delete[] p[i];
	}
	delete[] p;
}

Matrix& Matrix::operator=(const Matrix& mat){
	for(int i{0}; i<n; ++i){
		delete[] p[i];
	}
	delete[] p;

	n=mat.n;
	m=mat.m;

	p = new double*[n];
	for(int i=0; i<n; ++i){
		p[i]=new double[m];
	}

	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			setNumber(i,j,mat.p[i][j]);
		}
	}

	return *this;
}

Matrix Matrix::operator+(const Matrix& mat){
	if(n==mat.n && m==mat.m){
		Matrix hello{*this}; 
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				hello.p[i][j]+=mat.p[i][j];
			}
		}
		return hello;
	}
	else throw std::invalid_argument("Le matrici non sono sommabili!");
	
}

Matrix Matrix::operator-(const Matrix& mat){
	if(n==mat.n && m==mat.m){
		Matrix hello{*this};
		for(int i{0}; i<n; ++i){
			for(int j{0}; j<m; ++j){
				hello.p[i][j]-=mat.p[i][j];
			}
		}
		return hello;
	}
	else throw std::invalid_argument("Le matrici non hanno le stesse dimensioni!");
}

Matrix Matrix::operator*(const Matrix& mat){

	if(m==mat.n){
		Matrix ciao{n,mat.m};
		for(int i{0}; i<n; ++i){
			for(int j{0}; j<mat.m; ++j){
				for(int k{0}; k<m; ++k){
					ciao.p[i][j]+=(p[i][k]*mat.p[k][j]);
				}
			}
		}
		return ciao;
	}

	else throw std::invalid_argument("Non e' possibile effettuare la moltiplicazione");

}

void Matrix::setNumber(int i, int j, double num){
	p[i][j]=num;
}

double Matrix::getNumber(int i, int j) const{
	return p[i][j];
}

void Matrix::setMatrix(){
	double num;
	for(int i{0}; i<n; ++i){
		for(int j{0}; j<m; ++j){
			std::cout << "Inserire l'elemento [" << i << "][" << j << "] ";
			std::cin >> num;
			setNumber(i,j,num);
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Matrix& mat){
	for(int i=0; i<mat.n; ++i){
		for(int j=0; j<mat.m; ++j){
			out << mat.getNumber(i,j) << "\t";
		}
		out << std::endl;
	}
	return out;
}
