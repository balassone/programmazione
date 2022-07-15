#include<stdexcept>
#include<vector>
#include<sstream>

//buildHeap
template<typename T>
void buildHeap(vector<T>& v){
    for (int i = v.size()/2 ; i>=0; i--){
        heapify(v,i,v.size()-1);
    }
}
//heapify
template<typename T>
void heapify(vector<T>& v, int i, int last){
    int largest{0};
    int left = 2*i;
    int right = 2*i+1;
    if (left <= last && v[i] < v[left]){
        largest = left;
    } else largest = i;
    if (right <= last && v[largest] < v[right]){
        largest = right;
    } 

    if (largest != i){
        swap (v[i], v[largest]);
        heapify(v,largest,last);
    }
}

//help function, swap
template<typename T>
void swap(T& a, T& b){
    T temp = a;
    a=b;
    b=temp;
}

//sorting with heapSort
template<typename T>
void heapSort(vector<T>& v){
    int last = static_cast<int>(v.size()-1);
    buildHeap(v);
    for (int i = v.size()-1; i>=0; i--){
        swap(v[0], v[i]);
        last--;
        heapify(v,0,last);
    }
}


/***********    member functions    ***********/

//constructor
template<typename T>
Heap<T>::Heap(const vector<T>& vettore) : v(vettore), heapSize(static_cast<int>(vettore.size())) {
    buildHeap(v);
}

//is heap empty?
template<typename T>
bool Heap<T>::empty() const {
    return heapSize == 0;
}

//heap size
template<typename T>
int Heap<T>::size() const {
    return heapSize;
}

//front element of heap (max)
template<typename T>
const T& Heap<T>::front() const {
    return v[0];
}

//insert an element in heap
template<typename T>
void Heap<T>::heapInsert(const T& e){
    int i= heapSize;
    heapSize +=1;
    while (i>1 && v[i/2]< e){
        int parent_i = ((i % 2 = 0) ? i/2 : (i-1)/2);
        v[i] = v[parent_i];
        i=parent_i;
    }
    v[i] = e;
}

//extract element (max) from heap
template<typename T>
T Heap<T>::heapExtract() {
    if (empty()) {
        throw std::invalid_argument("Heap is empty, can't remove.");
    }
    T max = v[0];
    v[0] = v[heapSize-1];
    heapSize--;
    heapify(v,0,heapSize-1);
    return max;
}

//toString
template<typename T>
string Heap<T>::toString() const {
    std::ostringstream out;
    for (int i=0; i< heapSize; i++){
        out<<v[i]<<" ";
    }
    return out.str();
}
