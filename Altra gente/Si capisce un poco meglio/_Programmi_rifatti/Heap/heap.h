#ifndef HEAP_H
#define HEAP_H
#include<vector>
#include<string>
using std::string;
using std::vector;


template<typename T>
void buildHeap(vector<T>&);

template<typename T>
void heapify(vector<T>&, int,int);

template<typename T>
void swap(T&, T&);

template<typename T>
void heapSort(vector<T>&);

template<typename T>
class Heap {
    friend void heapify<T>(vector<T>&, int,int);
    friend void buildHeap<T>(vector<T>&);
    friend void heapSort<T>(vector<T>&);
    public:
        Heap(const vector<T>& = {});   //constructor

        bool empty() const;                     //is heap empty?
        int size() const;                       //number of elements in heap
        const T& front() const;                 //front element (max)

        void heapInsert(const T&);              //insert element in heap
        T heapExtract();                        //extract element from heap

        string toString() const;

    private:
        vector<T> v;
        int heapSize;
};

#include"heap.cpp"

#endif



