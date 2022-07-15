// LCSIterative.cpp
// computes the Longest common subsequence using two-dimensions array

#include <iostream>
#include <array>
using std::cout;
using std::endl;
using std::array;
using std::string;
template <typename T>
// template for the max function
 const T& max(const T& x, const T& y) {
    return (x > y)? x:y;
}


template<size_t int1, size_t int2>
int lcs(string X, string Y,array < array <int, int1>, int2>&table){
    

    for(int i = 0; i<=X.size(); i++){ 
        for(int j= 0; j <=Y.size(); j++)
			{ if(i != 0 && j != 0){
				if(X[i-1] == Y[j-1]) table[i][j] = 1 + table[i-1][j-1];
				else table[i][j] = max(table[i-1][j], table[i][j-1]);
				
				}
				cout<< table[i][j] << " ";
			}
			cout << endl;
		}
		return table[X.size()][Y.size()];
}


//test the lcs funtion
int main(){
    string X{"ATACCAGA"};
    string Y{"CTCCTAG"};
    const size_t rows{200};
    const size_t columns{200};
    array < array <int, columns>, rows> table {0};
    cout << "Length of LCS is \n" << lcs(X,Y,table) << endl;
    return 0;
}