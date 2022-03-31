#include <iostream>
using std::cout;
using std::endl;
int main(){

	for (int i{0}; i<9; ++i){

		for (int j{0}; j<9; ++j){
			if(i==0 || i==8 || j==0 || j==8){cout << "#";}
			else if((i<=4 && i-j>=1)){cout << " ";}
			else cout << "*";
		}
		cout << endl;
	}

	return 0;
}
