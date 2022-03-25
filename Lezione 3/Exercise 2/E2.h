#include<string>

class Invoice{

public:
	Invoice(std::string, std::string, int, int);

	void setNumber (std::string);
	std::string getNumber() const;
	void setDesc(std::string);
	std::string getDesc() const;
	int getQty() const;

	void setQty(int);

	int getPrice() const;

	void setPrice(int);

	double getVat() const;

	void setVat(double);

	double getDisc() const;

	void setDisc(double);

	double getInvoiceAmount();

private:
	std::string pn;
	std::string pd;
	int qty;
	int price;
	double VAT;
	double disc;

};
