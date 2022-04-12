#include <iostream>
#include <array>
#include <string>
using std::array;
using std::cout;
using std::endl;
using std::string;

const size_t col{8};
const size_t row{9};

void printArray(const array<array<int, col>, row>& A);

void LCS(array<array<int, col>, row>& A, string, string);

int main(){
	string p{"ATACCAGA"}, s{"CTCCTAG"};
	
	

	array<array<int, col>, row> myarr;
	for(unsigned int i{0} ; i<row; ++i){
		for(unsigned int j{0}; j<col; ++j){
			myarr[i][j]=0;
		}
	}

	LCS(myarr,p,s);
	printArray(myarr);
	return 0;
}

void LCS(array<array<int, col>,row>& A, string p, string s){
	for(unsigned int i{0}; i<row; ++i){
		int count{0};
		for(unsigned int j{0}; j<col; ++j){
			A[i][j]=count;
			if (i==0 || j==0){
				A[i][j]=0;
			}
			else{
				if(p[i-1]==s[j-1]){
					A[i][j]=++count;
				}
				else if(A[i-1][j-1]>A[i][j]){
					A[i][j]=A[i-1][j-1];
				}
				else if(A[i][j-1]>A[i][j]){
					A[i][j]=A[i][j-1];
				}
				else if(A[i-1][j]>A[i][j]){
					A[i][j]=A[i-1][j];
				}
			}
		}
	}

}

void printArray(const array<array<int,col>,row>& A){

	for (auto row : A){
		for(auto elem : row){
			cout << elem << "\t";
		}
		cout << endl;
	}

}
