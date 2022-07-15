#ifndef HEAP_H
#define HEAP_H

class Heap{

public:
    Heap(int array[],int dim);
    ~Heap();

private:
    int* A;
    int n;
    void Heapify(int array[],int dim, int i);
    void buildHeap(int array[],int dim);
    void swap(int array[],int i,int j);
};

#endif
