// overloading.cpp
// Overloaded square functions.
#include <iostream>
using std::cout;
using std::endl;

//function square for int values
int square(int x){
    cout << "square of integer " << x << " is " ;
    return x * x;
}

// function square for double values
double square (double y) {
    cout << "square of double " << y << " is " ;
    return y * y;
}
int main() {
    cout << square(7) << endl; // calls int version
    cout << square(7.5) << endl; // calls double version
}