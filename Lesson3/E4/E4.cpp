#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int powerTwo(int n){
	int two=1;

	while (n!=0){
		two*=2;
		n--;
	}
	return two;
}

int main(){
	int bin,dec{0}, r,i=0;

	cout << "Dammi il numero binario: " << endl;
	cin >> bin;

	while(bin!=0){
	r=bin%10;
	bin/=10;
	dec+=r*powerTwo(i);
	i++;
	}

	cout << endl << dec << endl;





	return 0;
}
