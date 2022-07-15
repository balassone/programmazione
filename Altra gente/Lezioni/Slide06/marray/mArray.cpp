// mArray.cpp
// Initializing multidimensional arrays.
#include <iostream>
#include <array>
using std::cout;
using std::array;
using std::endl;

const size_t rows {2};
const size_t columns {3};
void printArray(const array<array<int, columns>,rows>&);

int main() {
    array<array<int, columns>, rows> array1{1,2,3,4,5,6};
    array<array<int, columns>, rows> array2{1,2,3,4,5};

    cout << "Values in array1 by row are:" << endl;
    printArray(array1);

    cout << "\nValues in array2 by row are:" << endl;
    printArray(array2);
}

// output array with tho rows and three colums
void printArray(const array<array<int, columns>, rows>& a){
    //loop through array's rows
    for (auto const& row : a ){
        // loop through colums of current row
        for(auto const& element : row) {
            cout <<element << ' ';
        }

        cout << endl; // start new line of output
    }
}