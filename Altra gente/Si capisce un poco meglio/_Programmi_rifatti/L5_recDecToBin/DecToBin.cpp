//DecToBin
//conversion from base 10 to base 2
#include<iostream>
#include<string>
using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
    int num;
    cout<<"Insert an integer number"<<endl;
    cin>>num;
    string str;
    while (num != 0){
        str=std::to_string(num%2)+str;
        num=num/2;
    }
    cout<<"Conversion . . .\t"<<str<<endl;
}