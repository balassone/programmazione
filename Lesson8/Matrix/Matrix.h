#ifndef MATRIX_H
#define MATRIX_H
#include<ostream>
class Matrix{
friend std::ostream& operator<<(std::ostream& out, const Matrix&);
public:
	explicit Matrix(int=0, int=0);
	Matrix(const Matrix&);
	~Matrix();
	Matrix& operator=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator-(const Matrix&);
	void setNumber(int, int, double);
	double getNumber(int, int) const;
	void setMatrix();
	void printMatrix();
	
private:
	int n, m;
	double **p;
};

#endif
