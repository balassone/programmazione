#include<iostream>
#include<string>
#include"E2.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){

	Invoice scontrino{"0001","Cassa Bluetooth",1,15};

	cout << "L'articolo " << scontrino.getNumber() << " e' " << scontrino.getDesc() << " la cui quantita' e' " << scontrino.getQty() << endl;
	cout << "Il prezzo finale e' " << scontrino.getInvoiceAmount() << endl;

	cout << "Quanto sconto vuoi?(0.x) ";
	double sconto;
	cin >> sconto;
	scontrino.setDisc(sconto);
	cout << "Il nuovo prezzo e': " << scontrino.getInvoiceAmount() << endl;



	return 0;
}
