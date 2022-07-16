#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "Heapify.h"
#include "BuildHeap.h"
#include <vector>
template <typename T>
//HeapSort with BuildHeap and Heapify function in Heapify.h and BuildHeap.h
void HeapSort(std::vector<T>& A){
    BuildHeap(A);
    for(int i=A.size()-1; i>0; i--){
        T temp=A[0];
        A[0]=A[i];
        A[i]=temp;
        Heapify(A,0);
    }
}
#endif