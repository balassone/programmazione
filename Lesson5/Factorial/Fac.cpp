#include<iostream>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
int factorial(const int& num);

int main(){
	int x{0};
	do{
	cout << "Dammi x: ";
	cin >> x;
	} while (x<0);
	cout << "Il fattoriale e': " << factorial(x) << endl;
	return 0;
}

int factorial(const int& num){
	if(num==0){
		return 1;
	}
	else{
		return num*factorial(num-1);
	}
}
