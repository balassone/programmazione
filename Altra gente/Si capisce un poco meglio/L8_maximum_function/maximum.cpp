//maximum.cpp
//maximum function with a function prototype
#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;

int maximum (int x, int y, int z); //function prototype

int main () {
    cout<<"Enter 3 integer values: ";
    int int1, int2, int3;
    cin>>int1>>int2>>int3;

    //invoke maximum
    cout<<"The maximum integer value is: "<<maximum(int1,int2,int3)<<endl;
}

//function maximum
int maximum (int x, int y, int z) {
    int maximumValue{x};
    if (y>x){
        maximumValue=y;
    }
    if(z>maximumValue) {
        maximumValue=z;
    }
    return maximumValue;
  }