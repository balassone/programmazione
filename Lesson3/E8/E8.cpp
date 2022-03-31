#include <iostream>

using std::cout;
using std::endl;
int main(){
	int quadk;
	for(int i{1}; i<=500; ++i){
		for(int j{i}; j<=500; ++j){
			for(int k{j}; k<=500; ++k){
				quadk=k*k;

				if(quadk==(i*i+j*j)){
					cout << "Cateto 1: " << i << endl;
					cout << "Cateto 2: " << j << endl;
					cout << "Ipotenusa: " << k << endl;
					cout << endl;

				}

			}
		}


	}


	return 0;
}
