//arrayMult.cpp
// calculates the multiplication between a mxn and a nxk matrix

#include <iostream>
#include <array>

using std::array;
using std::cout;
using std::cin;

template <size_t i, size_t k> //template for print function
void print(const array<array<int, i>, k>&arr){ // prints the matrix
    for(const auto& row: arr){
        for(const auto& value: row){
            cout << value <<" ";
        }
        cout << "\n";
    }
}
template <size_t i, size_t k> // template for insert function
void insert(array<array<int, i> ,k>&arr){ // inserts the value for the matrix
    cout <<"insert the value for the matrix :";
    for(auto& row: arr){
        for(int& value: row){
            cin>>value;
        }
    }
}

template <size_t n, size_t m, size_t k> //template for print function
void multiplication(const array<array<int,n>,m>& mat1, const array<array<int,k>,n>& mat2, array<array<int, k>,m>& mat3){ // multiplication between two matrix
    cout << "the value of the matrix is:\n";
    for (size_t i = 0; i < mat3.size(); i++)
    {
        for (size_t j = 0; j < mat3[i].size(); j++)
        {
            for (size_t l = 0; l < mat2.size(); l++)
            {
                mat3[i][j] += (mat1[i][l]*mat2[l][j]); 
            }
        }
    }
    
    print(mat3);
}



int main(){
    // parameters for the rows and columns of each matrix
    const int m{2}; 
    const int n{3};
    const int k{4};
    
    //defining the arrays1
    
    array<array<int,n>,m> mat1{0};// has m rows and n columns
    array<array<int,k>,n> mat2{0}; // has n rows and k columns
    array<array<int,k>,m> mat3{0}; //has m rows and k columns

    insert(mat1);
    insert(mat2);
    print(mat2);
    print(mat1);
    multiplication(mat1,mat2,mat3);

}