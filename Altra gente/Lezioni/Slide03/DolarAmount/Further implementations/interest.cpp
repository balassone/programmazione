//Interest.cpp
// Compond-interest calculation with class DollarAmount and integers.
#include <iostream>
#include <iomanip>
#include <string>
#include "DollarAmountEnhanced.h"
using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main(){
    DollarAmount d1{123,45}; // 123.45
    DollarAmount d2{15,76}; // 15.76
    //set floating-point number format 
    cout << "After adding d2 ( " <<d2.toString () <<") into d1 (" 
        << d1.toString() << "), d1 = ";
    d1.add(d2); // modifies object d1
    cout << d1.toString() << "\n ";

    cout << "After subtracting d2 ( " <<d2.toString () <<") into d1 (" 
        << d1.toString() << "), d1 = ";
    d1.subtract(d2); // modifies object d1
    cout << d1.toString() << "\n ";

    cout << "After subtracting d1 ( " <<d1.toString () <<") into d2 (" 
        << d2.toString() << "), d2 = ";
    d2.subtract(d1); // modifies object d1
    cout << d2.toString() << "\n \n";

    cout << "Enter integer interest rate and divisor. For example: \n"
        << "for     2%, enter 2 100 \n"
        << "for   2,3%, ente 23 1000 \n"
        << "for  2.37%, enter 237 1000 \n"
        << "for 2,375%, ente 2375 10000 \n >    ";
    int rate; //whole-number interest rate
    int divisor; // divisor for rate
    cin >> rate >> divisor;





    DollarAmount  balance{1000,00}; // initial principal amount in pennies


    cout<< "Initial balaance: " << balance.toString() << endl;


    //display headers
    cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

    // calculate amount on deposit for each of ten years
    for (unsigned int year{1}; year <=10; year++) {
        // calculate amount on deposit at the end od the specified year
        balance.addInterest(rate, divisor);

        //display the year and the amount
        cout<< setw(4) << year << setw(20) << balance.toString() << endl;
    }
}