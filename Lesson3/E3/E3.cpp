#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int num, i{1}, r,bin{0};
	
	cout << "Dammi un numero base 10 intero: "; cin >> num;

	while(num!=0){
		r=num%2;
		num/=2;
		bin+=(i*r);
		i*=10;
	}
	cout << "Il numero binario e': "<<bin;


	cout << endl;


	return 0;
}
