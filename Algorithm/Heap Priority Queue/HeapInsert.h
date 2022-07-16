#ifndef HEAPINSERT_H
#define HEAPINSERT_H
#include <vector>
template <typename T>
//heap insert with vector
void HeapInsert(std::vector<T>& A, const T& x){
    int i=A.size()-1;
    while(i>0 && A[i]>A[(i-1)/2]){
        A[i]=A[(i-1)/2];
        i=(i-1)/2;
    }
    A[i]=x;
}
#endif