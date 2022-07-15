// Static.cpp
// static array initialization and automatic array initialization
#include <iostream>
#include <array>
using std::array;
using std::cout;
using std::endl;

void staticArrayInit(); //function prototype
void automaticArrayInit(); // function prototype
const size_t arraySize{3};

int main() {
    cout << "First call to each function: \n";
    staticArrayInit();
    automaticArrayInit();

    cout << "\n\nSecond call to each gunction:\n";
    staticArrayInit();
    automaticArrayInit();
    cout << endl;
}

//function to demonstrare a static local array
void staticArrayInit(void) {
    // initializes elements to ' frst time function is called
    static array<int, arraySize> array1; // static local array

    cout << "\nValues on entering staticArrayInit:\n";

    // output contents of array1
    for(size_t i{0}; i < array1.size(); ++i) {
        cout << "array1[" << i << "] = " << array1[i] << " ";
    }

    cout << "\nVAlues on exiting staticArrayInit:\n";

    // modify and output contents of array1
    for(size_t j{0}; j < array1.size(); ++j){
        cout << "array1[" << j << "] = "<< (array1[j] +=5 ) << " ";
    }
}

//function to demonstrate an automatic local array
void automaticArrayInit(void) {
    //initiializes elements each time function is called
    array<int, arraySize> array2{1,2,3}; //automatic local array

    cout << "\n\nValues on entering automaticArrayInit:\n";

    //output contents of array2
    for(size_t i{0}; i< array2.size(); ++i){
        cout << "array2["<< i << "] = "<< array2[i] << "  ";
    }
    cout << "\n Values on exiting automaticArrayInit:\n";

    //modify and output contents of array2
    for(size_t j{0}; j < array2.size(); ++j){
        cout << "array2["<<j<<"] = " << (array2[j] +=5 ) << "  ";
    }
}
