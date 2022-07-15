//testInvoice.cpp
#include"Invoice.h"
#include<iostream>
using std::cout; using std::cin; using std::endl;

int main() {
    Invoice inv1("RPG-132", "Falanghina white wine", 3, 12);

    Invoice inv2("RPG-143", "Iauresi red wine", 3, 22);

    inv2.setDiscountRate(0.1);

    cout<<inv1.getDescription()<<" x"<<inv1.getQuantity()<<" | "<<inv1.getInvoiceAmount()<<" euros"<<endl;
    cout<<inv2.getDescription()<<" x"<<inv2.getQuantity()<<" | "<<inv2.getInvoiceAmount()<<" euros"<<endl;
}