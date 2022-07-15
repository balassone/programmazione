//recDecToBin.cpp
#include<iostream>
#include<string>
using std::cin; using std::cout; using std::endl;
using std::string;

string recDec2Bin(int);

int main() {
    cout<<"Insert an integer value"<<endl;
    int num;
    cin>>num;
    cout<<"Binary conversion. . ."<<endl;
    string str;
    str=recDec2Bin(num);
    cout<<str;
    
}

string recDec2Bin(int n){
    if (n==0){
        return ("");
    }
    else {
        return recDec2Bin(n/2)+std::to_string(n%2);
    }

}
