// fibonacci.cpp
// Recursive function fibonacci.
#include <iostream>
using std::cout;
using std::endl;

unsigned long fibonacci(unsigned long); // function prototype

int main(){
    //calculate the fibonacci values of 0 through 10
    for (unsigned int counter{}; counter <= 10; ++counter) {
        cout << "fibonacci(" << counter << ") = " << fibonacci(counter) << endl;
    }

    //display higher fibonacci values
    cout << "\nfibonacci(20) = " << fibonacci(20) << endl;
    cout << "fibonacci(30) = " << fibonacci(20) << endl;
    cout << "fibonacci(35) = " << fibonacci(20) << endl;
}

// recursive function fibonacci
unsigned long fibonacci(unsigned long number) {
    if((0 == number) || ( 1 == number)) { // base case
        return number;
    }
    else{ // recursion step
    return fibonacci(number - 1 )+ fibonacci ( number - 2);

    }
}