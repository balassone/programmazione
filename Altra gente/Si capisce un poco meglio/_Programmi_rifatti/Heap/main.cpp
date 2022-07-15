#include"heap.h"
#include<iostream>
using std::cout;
using std::endl;
int main() {
    vector<int> A {5,2,3,8,1,6,7,9,4};
    Heap<int> h{A};
    for (int i=0; i<A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    Heap<int> B{A};
    heapSort(A);
    for (int i=0; i<A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<"Heap B (= A before A was ordered):"<<endl;
    cout<<B.toString();
    
    cout<<"\nExtract max from heap B ... "<<B.heapExtract();
}