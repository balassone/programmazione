#include<iostream>

using std::cin;
using std::cout;

bool palindrome(const int&);

int main(){
	int a;
	cout << "Dammi un numero: "; cin >> a;
	cout << (palindrome(a) ? "Palindromo!":"Non palindromo!");
	return 0;
}

bool palindrome(const int& num){
	//Il prof usa il numero di elementi. Vedi un po'.
	bool verifica{false};
	return verifica;
}
