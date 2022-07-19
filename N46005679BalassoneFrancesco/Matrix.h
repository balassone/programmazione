#include<ostream>
#ifndef MATRIX_H
#define MATRIX_H
//Mi serve una funzione per stampare, i big three e la possibilità di settare e ottenere un numero i,j
class Matrix{
friend std::ostream& operator<<(std::ostream& out, const Matrix&);
public:
	explicit Matrix(const int& npeople=0); //explicit: un solo operatore (incluso quello di default), evito conversioni implicite
	//Invoco i big three dato che alloco dinamicamente la matrice. Ripudiamo ogni forma di shallow copy.
	Matrix(const Matrix&);
	~Matrix();
	//Uso Matrix& invece di void per permettere eventuali operazioni in cascata.
	Matrix& operator=(const Matrix&);
	Matrix& setNumber(const int&, const int&, const int&);
	const int& getNumber(int, int) const;
	
private:
	int n; //un solo elemento, la matrice sarà quadrata
	int **p; //puntatore per la gestione della matrice
};

#endif
