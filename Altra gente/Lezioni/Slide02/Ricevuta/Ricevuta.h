//Invoice.h
//Class that represent an invoice

#include <string>

class Invoice{
    public:
    Invoice(std::string id, std::string description, int quantitu, int price);
    double getVAT() const;
    double getDiscount() const;
    int getPricePerItem() const;
    int getItemQuantity() const;
    std::string getPartNumber() const;
    std::string getProductDescription() const;
    void setVAT(double VATVariation);
    void setDiscount(double Discount);
    void setPricePerItem(int price);
    void setItemQuantity(int quantity);
    void setProductDescription(std::string description);
    void setPartNumber(std::string id);
    double getInvoiceAmount();
    private:
    std::string partNumber;
    std::string productDescription;
    int itemQuantity;
    int pricePerItem;
    double VAT;
    double discountRate;
};