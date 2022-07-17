#ifndef HEAPINSERT_H
#define HEAPINSERT_H
#include <vector>
template <typename T>
//heap insert with vector
void heapInsert(std::vector<T>& heap, T elem){
    heap.push_back(elem);
    int i = heap.size()-1;
    while(i>0 && heap[i]>heap[(i-1)/2]){
        T temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        
        i = (i-1)/2;
    }
}
#endif