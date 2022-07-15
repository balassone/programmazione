//factorial.cpp
//Recursive function factorial

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

unsigned long factorial(unsigned long); //function prototype

int main(){
    for (unsigned int counter{0}; counter<=10; ++counter) {
        cout<<setw(2)<<counter<<" != "<<factorial(counter)<<endl;
    }
}

//recursive definition of function factorial
unsigned long factorial(unsigned long number) {
    if (number<=1) { //caso base
        return 1;
    }
    else { //caso ricorsivo
        return number*factorial(number-1);
    }
}