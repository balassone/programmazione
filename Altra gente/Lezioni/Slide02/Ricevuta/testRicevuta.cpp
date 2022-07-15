#include <iostream>
#include <string>
#include "Ricevuta.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
	Invoice vinelloBuono{"7413", "vinello buono" , 2, 8};
	cout<<vinelloBuono.getInvoiceAmount()<<endl;
	cout<<vinelloBuono.getPartNumber()<<endl;
	Invoice grappino{"6969", "grappino fetentino" , 9, 10};
	double sconto = 0.8;
	grappino.setDiscount(sconto);
	cout<<"fra stai pagando "<<grappino.getItemQuantity()<<" bottiglie di "<<grappino.getProductDescription()<<" a un prezzo stracciato di "<<grappino.getInvoiceAmount()<<endl;
	if(sconto > 0)
		{
			double totale = grappino.getPricePerItem()*grappino.getItemQuantity();
			cout <<"bucchiniè tamm fatt o prezz buon! ben "<<sconto*100<<"% di sconto! A facc ro cazz mo t scass malament"<<endl;
			cout<<"un pezzo di sto cesso costa "<<grappino.getPricePerItem()<<" quindi a fuss pavat tutt cos "<<totale<<" euro ... 	e tamm trattat facc e cazz! sij pur minorenn quindi ta fussm mannat a nisid.";
			sconto = sconto/100;
		}
}