#include<string>

class Invoice{

public:
	Invoice(std::string number, std::string desc, int qtyy, int pricee)
	: pn{number}, pd{desc}, qty{qtyy}, price{pricee}, VAT{0.2}, disc{0} {}

	std::string getNumber() const {
		return pn;
	}

	void setNumber (std::string theNum){
		pn = theNum;
	}

	std::string getDesc() const {
		return pd;
	}

	void setDesc(std::string theDesc){
		pd=theDesc;
	}

	int getQty() const{
		return qty;
	}

	void setQty(int qtyqty){
		if(qtyqty>0){
			qty=qtyqty;
		}
	}

	int getPrice() const{
		return price;
	}

	void setPrice(int newPrice){
		if(newPrice>0){
			price=newPrice;
		}	
	}

	double getVat() const{
		return VAT;
	}

	void setVat(double VATT){
		if(VATT>0){
			VAT=VATT;
		}	
	}

	double getDisc() const{
		return disc;
	}

	void setDisc(double discount){
		if(discount>0){
			disc=discount;
		}	
	}

	double getInvoiceAmount(){
		double full=price*qty;
		full+=full*VAT;
		full-=full*disc;
		return full;
	}

private:
	std::string pn;
	std::string pd;
	int qty;
	int price;
	double VAT;
	double disc;

};
