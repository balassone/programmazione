//Heap.h
//declaration and implementation of functions heapify and buildHeap
#include<vector>
#include<string>
using std::vector;
#ifndef HEAP_H
#define HEAP_H

template<typename T>
void heapSort(vector<T>&);

template<typename T>
void buildHeap(vector<T>&);

template<typename T>
void heapify(vector<T>&, unsigned int);

template<typename T>
void swap(T&, T&);

template<typename T>
class Heap {
    friend void heapSort<T>(vector<T>&);
    friend void buildHeap<T>(vector<T>&);
    friend void heapify<T>(vector<T>&, unsigned int);
    public:
        Heap();                                 //empty constructor
        Heap(vector<T>);                        //constructor
        int heapSize() const;                   //size of heap
        bool empty() const;                     //is heap empty?
        T front() const;                       //front element of heap
        void heapInsert(const T&);              //insert element in heap
        T heapExtractMax();              //extract max element from heap


        std::string toString() const;           //toString
    private:
        vector<T> v;
};


#include"Heap.cpp"
#endif



