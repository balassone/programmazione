// factorial.cpp
// recursive function factorial
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

unsigned long factorial(unsigned long); //function prototype

int main(){
    //calculate the factiorial of 0 through 10
    for(unsigned int counter{0}; counter <= 10; ++counter) {
        cout << setw(2) << counter << "! =  " << factorial(counter) << endl; 
    }
}

//recursive definition of a function factorial
unsigned long factorial(unsigned long number) {
    if(number <= 1){ // test for base case
        return 1; // base cases: 0! = 1 and 1! = 1
    }
    else { // recursion step
        return number * factorial (number -1); 
    }
}