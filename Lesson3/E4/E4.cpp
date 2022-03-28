#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

int main(){
	int bin,dec{0}, r,i=0;

	cout << "Dammi il numero binario: " << endl;
	cin >> bin;

	while(bin!=0){
	r=bin%10;
	bin/=10;
	dec+=r*pow(2,i);
	i++;
	}

	cout << endl << dec << endl;





	return 0;
}
