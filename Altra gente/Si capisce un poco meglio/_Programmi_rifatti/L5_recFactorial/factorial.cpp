//factorial.cpp
//recursive factorial program
#include<iostream>
using std::cout; using std::cin; using std::endl;

unsigned long factorial(unsigned long);

int main() {
    for (int i=0; i<11; i++){
        cout<<i<<"! = "<<factorial(i)<<"\n";
    }
}

unsigned long factorial(unsigned long n){
    if (n<=1){
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}