#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int bin[100], num, dim{0};
	do{
		cout << "Dammi un numero base 10 intero: "; cin >> num;
	} while(num==0);

	while(num!=0){
		bin[dim]=num%2;
		num=num/2;
		dim++;
	}
	cout << "Il numero binario e': ";
	for (int i=(dim-1);i>-1;i--){
		cout << bin[i];
	}

	cout << endl;





	return 0;
}
