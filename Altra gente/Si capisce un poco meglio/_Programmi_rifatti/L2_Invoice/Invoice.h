#ifndef INVOICE_H
#define INVOICE_H

#include<string>

class Invoice{
    public:
        Invoice(std::string, std::string, int, int);

        //Set functions and get functions
        void setNumber(std::string&);
        std::string getNumber() const;
        void setDescription(std::string&);
        std::string getDescription() const;
        void setQuantity(int);
        int getQuantity() const;
        void setPricePerItem(int);
        int getPricePerItem() const;
        void setVAT(double);
        double getVAT() const;
        void setDiscountRate(double);
        double getDiscountRate() const;

        //get Invoice amount
        double getInvoiceAmount() const;

    private:
        std::string number;
        std::string description;
        int quantity;
        int pricePerItem;
        double VAT;     //IVA
        double discountRate;
};

#endif