#include <iostream>
#include <string>
#include <array>

using std::cout;
using std::endl;
using std::array;
using std::string;

template <typename T>
T max(const T& a, const T& b){
	return (a<=b) ? b : a;
}
const size_t row{9};
const size_t col{8};

void printMat(const array<array<int, col>,row>&);
void lcs(array<array<int, col>, row>&, const string&, const string&);
int main(){
	string s{"ATACCAGA"}, t{"CTCCTAG"};
	
	array <array<int, col>, row> myArray{};
	lcs(myArray, s, t);
	printMat(myArray);
	return 0;
}

void printMat(const array<array<int, col>, row>& a){

	for (const auto& row : a){
		for (const auto& elem : row){
			cout << elem << " ";
		}
		cout << endl;
	}

}

void lcs(array<array<int, col>, row>& A,const string& s,const string& t){


	for(unsigned int i{0}; i<row; ++i){
		for(unsigned int j{0}; j<col; ++j){
			if (i==0 || j==0){
				A[i][j]=0;
			}	
			else if(s[i-1]==t[j-1]){
				A[i][j]=1+A[i-1][j-1];
			}
			else
				A[i][j]=max(A[i-1][j], A[i][j-1]);
		}
	}
}
