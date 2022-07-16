#ifndef HEAPIFY_H
#define HEAPIFY_H
//Lo rimetto qui perché serve ad estrarre il max
#include <vector>
template <typename T>
void Heapify(std::vector<T>& A, const int& i){
    int l{(2*i)+1}, r{(2*i)+2};
    int max;
    if(l<=A.size() && A[l]>A[i]){
        max=l;
    } else{
        max=i;
    }
    if(r<=A.size() && A[r]>A[max]){
        max=r;
    }
    if(max!=i){
        T temp=A[i];
        A[i]=A[max];
        A[max]=temp;
        Heapify(A,max);
    }
}
#endif