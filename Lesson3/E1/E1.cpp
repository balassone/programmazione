#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	cout << "Calcolo massimo e minimo di numeri." << endl;
	int sentinel{0};
	cout << "Inserisci numero oppure 0 per uscire: ";
	cin >> sentinel;
	int max{sentinel},min{sentinel};
	while(sentinel!=0){
		if (sentinel>max && max>=min){
			max=sentinel;
		}
		if (sentinel<min && min<=max){
			min=sentinel;
		}
		cout << "Altro numero: ";
		cin >> sentinel;

	}

	cout << "Il massimo e' " << max<<" e il minimo e' " << min << endl;


	return 0;
}
