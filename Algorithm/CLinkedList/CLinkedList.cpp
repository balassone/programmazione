#include <iostream>
#include <sstream>

template <typename T>
CLinkedList<T>::CLinkedList() : cursor{nullptr} {}

template <typename T>
CLinkedList<T>::~CLinkedList() {
    while (!empty()) {
        remove();
    }
}

template <typename T>
bool CLinkedList<T>::empty() const {
    return cursor == nullptr;
}

template <typename T>
const T& CLinkedList<T>::front() const {
    return cursor->next->elem;
}

template <typename T>
const T& CLinkedList<T>::back() const {
    return cursor->elem;
}

template <typename T>
CLinkedList<T>& CLinkedList<T>::advance() {
    cursor = cursor->next;
    return *this;
}

template <typename T>
CLinkedList<T>& CLinkedList<T>::add(const T& e) {
    CNode<T> *v = new CNode<T>;
    v->elem = e;
    if (empty()) {
        v->next = v;
        cursor = v;
    } else {
        v->next = cursor->next;
        cursor->next = v;
    }
    return *this;
}

template <typename T>
CLinkedList<T>& CLinkedList<T>::remove() {
    CNode<T>* old = cursor->next;
    if (old==cursor){
        cursor = nullptr;
    } else {
        cursor->next = old->next;
    }
    return *this;
}

template <typename T>
std::string CLinkedList<T>::toString() const {
    std::ostringstream out;
    CNode<T>* u = cursor;
    out << "Cursor --> ";
    out << u->elem << " --> ";
    u = u->next;
    while (u != cursor) {
        out << u->elem << " --> ";
        u = u->next;
    }
    out << "Cursor";
    return out.str();
}

template <typename T>
//bubble sort a circular linked list
CLinkedList<T>& CLinkedList<T>::sort() {
    CNode<T>* u = cursor->next;
    CNode<T>* v = u->next;
    while (u != cursor) {
        while (v != cursor) {
            if (u->elem > v->elem) {
                T temp = u->elem;
                u->elem = v->elem;
                v->elem = temp;
            }
            v = v->next;
        }
        u = u->next;
        v = u->next;
    }
    return *this;
}
template <typename T>
CLinkedList<T>& CLinkedList<T>::reverse() {
    CNode<T>* u = cursor->next;
    CNode<T>* v = u->next;
    while (u != cursor) {
        while (v != cursor) {
            T temp = u->elem;
            u->elem = v->elem;
            v->elem = temp;
            v = v->next;
        }
        u = u->next;
        v = u->next;
    }
    return *this;
}