#include "Heap.h"

void Heap::Heapify(int array[],int dim,int i){
    int largest=i;
    int l=2*i+1; //nodo figlio sx
    int r=2*i+2; //nodo filgio dx
    if(l<dim && array[l]>array[i]) largest=l;
    if(r<dim && array[r]>array[i]) largest=r;
    if(largest!=i){
        swap(array,largest,i);
        Heapify(array,dim,largest);
    }
}

void Heap::swap(int array[],int i,int j){
    int temp=array[i];
    array[i]=array[j];
    array[j]=temp;
}

void Heap::buildHeap(int array[],int dim){
    for(int i=dim-1; i>=0; i--){
        Heapify(array,dim,i);
    }
}


Heap::Heap(int array[],int dim)
    : A{new int[dim]}, n{dim} {
        for(int i=0;i<dim;i++){
            A[i]=array[i];
        }
        buildHeap(A,n);
    }

Heap::~Heap(){
    delete[] A;
}