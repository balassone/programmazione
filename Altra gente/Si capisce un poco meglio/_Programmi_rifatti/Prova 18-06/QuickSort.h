//QuickSort.h
#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::vector;
using std::endl;

template<typename T>
int partition(vector<T>& A, int p, int q);

template<typename T>
void quickSort(vector<T>& A, int p, int r){
    if (p<r){
        int q=partition(A, p, r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}

template<typename T>
void swap(vector<T>& A, int x, int y){
    T temp=A[x];
    A[x] = A[y];
    A[y]=temp;
}

template<typename T>
int partition(vector<T>& A, int p, int r){
    T x= A[p];
    int i=p-1;
    int j=r+1;
    while(true){
        do
            j=j-1;
        while (x < A[j]);
        do
            i=i+1;
        while (A[i]<x);
        if(i<j){
            swap(A,i,j);
        }
        else{
            return j;
        }
    }
}
