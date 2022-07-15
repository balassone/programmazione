//PriorityQueue.cpp

//empty constructor
template<typename T>
PriorityQueue<T>::PriorityQueue() : h{} {
}

//constructor
template<typename T>
PriorityQueue<T>::PriorityQueue(Heap<T> heap){
    h = heap;
}

template<typename T>
bool PriorityQueue<T>::empty() const {
    return h.heapSize()==0;
}

template<typename T>
int PriorityQueue<T>::size() const {
    return h.heapSize();
}

template<typename T>
T PriorityQueue<T>::top() const {
    return h.front();
}

template<typename T>
void PriorityQueue<T>::push(const T& e) {
    h.heapInsert(e);
}

template<typename T>
void PriorityQueue<T>::pop() {
    h.heapExtractMax();
}

