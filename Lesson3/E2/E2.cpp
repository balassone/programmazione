#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int a,b,c,d,e;

	cout << "Inserisci il primo: "; cin >> a;
	cout << "Inserisci il secondo: "; cin >> b;
	cout << "Inserisci il terzo: "; cin >> c;
	cout << "Inserisci il quarto: "; cin >> d;
	cout << "Inserisci il quinto: "; cin >> e;
	if(a==e && b==d) cout << "Palindromo!" << endl;
	else cout << "Non palindromo" << endl;



	return 0;
}
