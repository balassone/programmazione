#include <iostream>
#include <sstream>

template <typename T>
CircleList<T>::CircleList() : cursor{nullptr} {}

template <typename T>
CircleList<T>::~CircleList() {
    while (!empty()) {
        remove();
    }
}

template <typename T>
bool CircleList<T>::empty() const {
    return cursor == nullptr;
}

template <typename T>
const T& CircleList<T>::front() const {
    return cursor->next->elem;
}

template <typename T>
const T& CircleList<T>::back() const {
    return cursor->elem;
}

template <typename T>
CircleList<T>& CircleList<T>::advance() {
    cursor = cursor->next;
    return *this;
}

template <typename T>
CircleList<T>& CircleList<T>::add(const T& e) {
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
CircleList<T>& CircleList<T>::remove() {
    CNode<T>* old = cursor->next;
    if (old==cursor){
        cursor = nullptr;
    } else {
        cursor->next = old->next;
    }
    return *this;
}

template <typename T>
std::string CircleList<T>::toString() const {
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