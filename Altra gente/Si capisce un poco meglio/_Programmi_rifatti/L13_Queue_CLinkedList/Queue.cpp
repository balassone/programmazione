//Queue.cpp
//implementation of Queue class functions

template<typename E>
Queue<E>::Queue() : C(), n(0) {}

template<typename E>
int Queue<E>::size() const {
    return n;
}

template<typename E>
bool Queue<E>::empty() const {
    return n==0;
}

template<typename E>
const E& Queue<E>::front() {
    return C.front();
}

template<typename E>
void Queue<E>::enqueue(const E& e) {
    C.add(e);
    C.advance();
    n++;
}

template<typename E>
void Queue<E>::dequeue() {
    C.remove();
    n--;
}