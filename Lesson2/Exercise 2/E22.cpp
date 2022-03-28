#include<string>

#include"E2.h"

	Invoice::Invoice(std::string number, std::string desc, int qtyy, int pricee)
	: pn{number}, pd{desc}, qty{qtyy}, price{pricee}, VAT{0.2}, disc{0} {}

	std::string Invoice::getNumber() const {
		return pn;
	}

	void Invoice::setNumber (std::string theNum){
		pn = theNum;
	}

	std::string Invoice::getDesc() const {
		return pd;
	}

	void Invoice::setDesc(std::string theDesc){
		pd=theDesc;
	}

	int Invoice::getQty() const{
		return qty;
	}

	void Invoice::setQty(int qtyqty){
		if(qtyqty>0){
			qty=qtyqty;
		}
	}

	int Invoice::getPrice() const{
		return price;
	}

	void Invoice::setPrice(int newPrice){
		if(newPrice>0){
			price=newPrice;
		}	
	}

	double Invoice::getVat() const{
		return VAT;
	}

	void Invoice::setVat(double VATT){
		if(VATT>0){
			VAT=VATT;
		}	
	}

	double Invoice::getDisc() const{
		return disc;
	}

	void Invoice::setDisc(double discount){
		if(discount>0){
			disc=discount;
		}	
	}

	double Invoice::getInvoiceAmount(){
		double full=price*qty;
		full+=full*VAT;
		full-=full*disc;
		return full;
	}
