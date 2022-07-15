//Heap.h
#include<sstream>
#include<stdexcept>
#include<iostream>
using std::cout;

//empty constructor
template<typename T>
Heap<T>::Heap() : v{} {}

//constructor
template<typename T>
Heap<T>::Heap(vector<T> a) : v(a) {
    buildHeap(v);
}

template<typename T>
bool Heap<T>::empty() const {
    return v.size() == 0;
}

template<typename T>
int Heap<T>::heapSize() const {
    return v.size();
}

template<typename T>
T Heap<T>::front() const {
    if (empty()) {
        throw std::invalid_argument("List is empty. Can't show any element.");
    }
    return v[0];
}

//heapInsert inserisce l'elemento come foglia e poi risale lungo l'albero

template<typename T>
void Heap<T>::heapInsert(const T& key) {
    v.push_back(key);
    int i= v.size()-1;
    while (i>0 && v[i/2]<key){
        v[i] = v[i/2];
        i = i/2;
    }
    v[i] = key;
}

template<typename T>
T Heap<T>::heapExtractMax() {
    if (empty()){
        throw std::invalid_argument("List is empty. Can't remove elements");
    }
    T max = v[0];
    v[0] = v[v.size()-1];
    v.resize(v.size()-1);
    heapify(v,0);
    return max;
}

template<typename T>
void swap (T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
}

template<typename T>
void buildHeap(vector<T>& A){
    for (int i=(A.size()/2)-1; i>=0; i--){
        heapify(A,i);
    }
}

template<typename T>
void heapify(vector<T>& A, unsigned int i) {
    unsigned int largest{0};
    unsigned int l=2*i;
    unsigned int r=2*i + 1;
    if (l < A.size() && A[l]>A[i]) {
        largest = l;
    }
    else largest = i;
    if (r < A.size() && A[r] > A[largest]){
        largest = r;
    }
    if (largest != i){
        swap(A[i], A[largest]);
        heapify(A, largest);
    }
}

//toString
template<typename T>
std::string Heap<T>::toString() const {
    std::ostringstream out;
    if (empty()){
        out<<"Heap empty";
        return out.str();
    }
    for (int i=0; i<heapSize(); i++){
        out<<v[i]<<" ";
    }
    return out.str();
}

//Heapsort
template<typename T>
void heapSort(vector<T>& A) {
    buildHeap(A);
    vector<T> B {A};
    int size = A.size();
    for (int i = size-1; i>=0; i--){
        A[i] = B[0];
        swap(B[0], B[i]);
        B.resize(i);
        heapify(B, 0);
    }
}
