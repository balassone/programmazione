//Factorial.cpp
//a strange factorial program
#include<iostream>

using std::cout;

long int fact(int n);

int main (){
    int n=4;
    cout<<"Factorial program\n";

    cout<<fact(n)<<"\n";
}

    long int fact(int n) {
        long int factorial;
        factorial=1;
        while (n){
        factorial *=n;
        n--;
        }
    return factorial;
    }