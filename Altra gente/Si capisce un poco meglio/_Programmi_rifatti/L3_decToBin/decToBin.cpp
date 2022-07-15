//decToBin.cpp
#include<iostream>
#include<string>
using std::string;
using std::cout; using std::cin; using std::endl;

string decToBin(unsigned int);

int main() {
    cout<<"Enter integer positive number to convert in binary"<<endl;
    unsigned int num;
    cin>>num;
    cout<<"BIP BIP . . . Conversion . . ."<<endl;
    cout<<num<<" in binary is : "<<decToBin(num);
}

string decToBin(unsigned int number) {
    string bin;
    while(number != 0){
        bin = std::to_string(number%2) + bin;
        number = number/2;
    }
    return bin;
}