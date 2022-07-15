//recDec2Bin
//program that converts a number from decimal to binary using a recursive function

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

std::string recDec2Bin (int number){
    if (number==0){
        return (""); //andrebbe messo 0, ma così non esce il bit più significativo che altrimenti sarebbe sempre 0
    }
    else {
        return recDec2Bin(number/2)+std::to_string(number%2);
    }
}

int main() {
    int number;
    cout<<"Enter an integer: ";
    cin>>number;
    cout<<"\nThe binary representation of "<<number<<" is: "<<recDec2Bin(number)<<"\n"<<endl;
}