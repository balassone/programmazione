#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include <stdexcept>
#include <iostream>
#include "CLinkedList"

template <typename E>
class LinkedQueue {
    public:
        LinkedQueue();
        //~LinkedQueue();
        int size() const;
        bool empty() const;
        const E& front() const;
        //const E& back() const;
        //LinkedQueue<E>& advance();
        LinkedQueue<E>& enqueue(const E& e);
        LinkedQueue<E>& dequeue();
        //std::string toString() const;
    private:
        CLinkedList<E> C;
        int n;
};

template <typename E>
LinkedQueue<E>::LinkedQueue() : C(), n(0) {}

template <typename E>
int LinkedQueue<E>::size() const {
    return n;
}

template <typename E>
bool LinkedQueue<E>::empty() const {
    return n == 0;
}

template <typename E>
const E& LinkedQueue<E>::front() const {
    if (empty()) {
        throw std::runtime_error("Empty queue");
    }
    return C.front();
}

template <typename E>
LinkedQueue<E>& LinkedQueue<E>::enqueue(const E& e) {
    C.add(e);
    C.advance();
    n++;
    return *this;
}

template <typename E>
LinkedQueue<E>& LinkedQueue<E>::dequeue() {
    if (empty()) {
        throw std::runtime_error("Empty queue");
    }
    C.remove();
    n--;
    return *this;
}

#endif