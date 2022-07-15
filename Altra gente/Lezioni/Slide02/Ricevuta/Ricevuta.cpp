#include <string>
#include "Ricevuta.h"
using std::string;

Invoice::Invoice(std::string id, std::string description, int quantity, int price) : partNumber{id} , productDescription{description}, VAT{0.2}, discountRate{0}{
	if(quantity > 0){
		itemQuantity = quantity;
	}
	if(price > 0){
		pricePerItem = price;
	}
}
double Invoice::getVAT() const{
	return VAT;
}
double Invoice::getDiscount() const{
	return discountRate;
}
int Invoice::getPricePerItem() const{
	return pricePerItem;
}
int Invoice::getItemQuantity() const{
	return itemQuantity;
}
std::string Invoice::getPartNumber() const{
	return partNumber;
}
std::string Invoice::getProductDescription() const{
	return productDescription;
}
void Invoice::setVAT(double VATvariation){
	if(VATvariation > 1){
		VAT=VATvariation;
	}
}
void Invoice::setDiscount(double discount){
	if(discount < 1){
		discountRate = discountRate - discount;
	}
}
void Invoice::setPricePerItem(int price){
	if(price > 0){
		pricePerItem = price;
	}
}
void Invoice::setItemQuantity(int quantity){
	if(quantity > 0){
		itemQuantity = quantity;
	}
}
void Invoice::setProductDescription(std::string description){
	productDescription = description;
}
void Invoice::setPartNumber(std::string id){
	partNumber = id;
}

double Invoice::getInvoiceAmount(){
	double invoiceAmount{itemQuantity*pricePerItem*VAT*discountRate};
	return invoiceAmount;
}