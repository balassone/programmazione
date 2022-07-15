#include "HeapVector.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main(){
    
    vector<int> vector{4,1,3,2,16,9,10,14,8,7};
    cout <<vector.size()<<": is the number of nodes in the tree \n";
    cout << "\n input \n";
    for(int i=0; i<10; i++){
        cout <<vector[i]<<" ";
    }
    //cout << "\n heapify \n";
    //heapSort(vector);
    //cout << "\n heapSort \n";
    //for(int i=0; i<10; i++){
    //    cout <<vector[i]<<" ";
    //}
    buildHeap(vector);
    cout << "\n buildHeap before insert \n";
    for(int i=0; i<vector.size(); i++){
        cout <<vector[i]<<" ";
    }
    heapInsert(vector, 15);

    cout << "\n after insert \n";
    for(int i=0; i<vector.size(); i++){
        cout <<vector[i]<<" ";
    }

    heapInsert(vector, 17);
    
    cout << "\n after insert \n";
    for(int i=0; i<vector.size(); i++){
        cout <<vector[i]<<" ";
    }


    
    

}