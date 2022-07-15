//main.cpp
#include<iostream>
using std::cout; using std::endl;
#include"Heap.h"


int main(){
    vector<int> A{1,5,3,4,7,6,9,8,2,10};
    cout<<"Vettore A: \n";
    for (int i=0; i< A.size(); i++){
        cout<<A[i]<<" ";
    }
    Heap<int> h{A};
    cout<<"\nHeap h derived from vector A :\n"<<h.toString()<<endl;
    cout<<"size of heap h: "<<h.heapSize()<<endl;
    cout<<"front oh heap h: "<<h.front()<<endl; 
    h.heapInsert(12);
    cout<<"Insert 12 in h. . ."<<endl;
    cout<<h.toString()<<endl;
    h.heapInsert(11);
    cout<<"Insert 11 in h. . ."<<endl;
    cout<<h.toString()<<endl;
    heapSort(A);
    cout<<"Sorting vector A. . ."<<endl;
    for (int i=0; i<A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl<<"Max of heap: "<<
    h.heapExtractMax();
}

