#include <iostream>
using std::cout;
using std::endl;
int main(){

	for (int i{0}; i<9; ++i){

		cout << "#";

		for(int j{0}; j<7; ++j){
			if(i==0 || i==8){
				cout << "#";
			}
			else {
				cout << "*";
			}
		}

		cout << "#"<<endl;

	}

	return 0;
}
