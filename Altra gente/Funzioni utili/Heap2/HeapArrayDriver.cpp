#include "HeapArray.h"
#include <iostream>
#include <array>

using std::array;
using std::cout;

int main(){
    array<int, 10> array{1,14,10,8,7,9,3,2,4,16};
    cout <<array.size()<<": is the number of nodes in the tree \n";
    cout << "input \n";
    for(int i=0; i<10; i++){
        cout <<array[i]<<" ";
    }
    cout << "\n heapify \n";
    heapSort(array);
    cout << "\n heapSort \n";
    for(int i=0; i<10; i++){
        cout <<array[i]<<" ";
    }
    

}

