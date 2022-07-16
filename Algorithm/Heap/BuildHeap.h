#ifndef BUILDHEAP_H
#define BUILDHEAP_H
#include <vector>
#include "Heapify.h"
template <typename T>
//Build heap with Heapify function in Heapify.h
void BuildHeap(std::vector<T>& A){
    for(int i=A.size()/2; i>=0; i--){
        Heapify(A,i);
    }
}
#endif