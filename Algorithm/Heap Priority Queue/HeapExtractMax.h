#ifndef HEAPEXTRACTMAX_H
#define HEAPEXTRACTMAX_H
#include "Heapify.h"
#include <vector>
template <typename T>
T HeapExtractMax(std::vector<T>& heap){
    if(heap.size()==0){
        throw std::runtime_error("Heap is empty");
    }
    T max = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    Heapify(heap, 0);
    return max;
}
#endif