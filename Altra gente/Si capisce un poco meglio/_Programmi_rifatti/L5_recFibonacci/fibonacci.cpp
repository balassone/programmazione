//fibonacci.cpp
//recursive Fibonacci's sequence program, using subproblem overlap (dangerous)
//this causes a complexity O(2^n) in the worst case; iterative problem, with a for cicle,
//has a complexity O(n) --> much better

#include<iostream>
using std::cout; using std::cin; using std::endl;

unsigned long fibonacci (unsigned long);

int main() {
    for (int i=0; i<11; i++){
        cout<<"fibonacci ("<<i<<") = "<<fibonacci(i)<<endl;
    }
}

unsigned long fibonacci (unsigned long n){
    if (n==0|| n==1){       //base cases
        return n;
    } else {                //recusrive step
        return fibonacci(n-1)+fibonacci(n-2);
    }
}