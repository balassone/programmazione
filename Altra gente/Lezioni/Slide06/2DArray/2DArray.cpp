// 2DArray.cpp
//Compute the matrix product between A and B
#include <iostream>
#include <array>

using std::array;
using std::cout;
using std::endl;

// defining prefixed size for both matrix
const size_t m = 4;
const size_t n = 3;
const size_t k = 2;

//function prototypes
template <size_t rows, size_t columns>
void printArray(array<array<int, columns>, rows>& matrice);
template <typename T, size_t u, size_t v, size_t w>
// u = rows first matrix, v = column first matrix, rows second matrix, w = column second matrix
void product(array<array<T, v>, u >&A, array<array<T, w>, v>&B);


template <typename T, size_t u, size_t v, size_t w> 
void product(array<array<T, v>, u >&A, array<array<T, w>, v>&B){
	// will be defined a temporary matrix, with the row count of the first matrix and the column count of the second matrix
	//This matrix will be able to host the product between the matrix A and the matrix B
	array<array<T, w>, u> product{0};
	
	// allows to do the product between matrix
	//first two for cycles allows to visit the matrix
	//given a mxn matrix and a nxk matrix, the index will have a max of m for the rows and a max of k for the columns
	// the index uses the 
	for (int i = 0; i<A.size(); i++){
		for(int j = 0; j < B[i].size(); j++){
			
			// the third for cycle allows us to do the product between the row and the column of the two matrix
			// given a mxn matrix and a nxk matrix, the index will pair the column of the first matrix
			// with the row of the second matrix 
			for (int k = 0; k < A[j].size(); k++)
			{
				product[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	printArray(product);
		
}
// prints the array
template <size_t rows, size_t columns>
void printArray(array<array<int, columns>, rows>& matrice)
{
	for(int i = 0; i < matrice.size(); i++){
		for(int j = 0; j < matrice[i].size(); j++) {
			cout << matrice[i][j] << " ";
		}
		cout<<endl;
	}
}

int main(){ // driver
	// array declarations
	array<array<int, n>,m> matrice1{1,2,3,4,5,6,7,8,9,10,11,12};
	array<array<int, k>, n> matrice2{1,2,3,4,5,6};
	
	
	//testing the program
	cout << "Stampa prima matrice \n";
	printArray(matrice1);
	cout <<endl;
	cout << "stampa seconda matrice \n";
	printArray(matrice2);
	
	//checks if the column of the first matrix is equal to the row of the second matrix
	if(matrice1[0].size() == matrice2.size()){
		cout << " stampa prodotto tra due matrici \n";
		product(matrice1, matrice2);	
	}	
	
}