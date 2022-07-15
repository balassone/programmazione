#include"Invoice.h"

using std::string;

//constructor
Invoice:: Invoice(string num, string descr, int qty, int price) {
    setNumber(num);
    setDescription(descr);
    setQuantity(qty);
    setPricePerItem(price);
    setVAT(0.20);
    setDiscountRate(0.0);
}

//set and get functions (12 functions)

void Invoice::setNumber(string& num){
    num=number;
}
string Invoice::getNumber() const {
    return number;
}

void Invoice::setDescription(string& descr){
    description=descr;
}
string Invoice::getDescription() const {
    return description;
}

void Invoice::setQuantity(int qty){
    if (qty>0){
        quantity=qty;
    }
}
int Invoice::getQuantity() const {
    return quantity;
}

void Invoice::setPricePerItem(int price){
    if (price>0){
        pricePerItem=price;
    }
}
int Invoice::getPricePerItem() const{
    return pricePerItem;
}

void Invoice::setVAT(double vat){
    if (vat>=0 && vat<=1){
        VAT=vat;
    }
}
double Invoice::getVAT() const {
    return VAT;
}

void Invoice::setDiscountRate(double disc) {
    if (disc>=0 && disc<=1){
        discountRate=disc;
    }
}
double Invoice::getDiscountRate() const {
    return discountRate;
}

//get Invoice amount
double Invoice::getInvoiceAmount() const {
    double amount = quantity*pricePerItem;
    //apply VAT and discount
    amount = amount - amount*discountRate;
    return amount + amount * VAT;
}