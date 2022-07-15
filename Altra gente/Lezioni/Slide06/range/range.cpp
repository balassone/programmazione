// range.cpp
// Usinge range-based for to multiply an array's elements by 2.
#include <iostream> 
#include <array>
using std::cout;
using std::array;
using std::endl;

int main() {
    array<int,5> items{1,2,3,4,5};

    //display items before modification
    cout << "items before modification: ";
    for(int item : items) {
        cout << item << " ";
    }

    //multiply the elements of items by 1
    for(int& itemRef : items) {
        itemRef *= 2;
    }

    //display items after modification
    cout << "\nitems after modification: ";
    for( int item: items){
        cout << item << " ";
    }
    cout << endl;
}