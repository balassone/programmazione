//DList.cpp
#include<stdexcept>
//empty constructor
template<typename T>
DList<T>::DList() : n{0} {
    n=0;
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->prev = nullptr;
    header->next = trailer;
    trailer->prev = header;
    trailer->next = nullptr;
}

//copy constructor
template<typename T>
DList<T>::DList(const DList<T>& l) {
    n=0;
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    header->prev = nullptr;
    trailer->next = nullptr;
    trailer->prev = header;
    for (int i=0; i<l.size(); i++){
        addBack(l[i]);
    }
}

//operator = (assignment)
template<typename T>
DList<T>& DList<T>::operator=(const DList<T>& l){
    if (this == &l){
        return *this;
    }
    while (!empty()){
        removeFront();
    }
    n=0;
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    header->prev = nullptr;
    trailer->next = nullptr;
    trailer->prev = header;
    for (int i=0; i<l.size(); i++){
        addBack(l[i]);
    }
    return *this;
}

//destructor
template<typename T>
DList<T>::~DList() {
    while (!empty()){
        removeFront();
        n--;
    }
}

//get size
template<typename T>
int DList<T>::size() const {
    return n;
}

//is list empty?
template<typename T>
bool DList<T>::empty() const {
    return n==0;
}

//begin iterator
template<typename T>
Iterator<T> DList<T>::begin() const {
    return (Iterator<T>(header->next));
}

//end iterator
template<typename T>
Iterator<T> DList<T>::end() const {
    return (Iterator<T>(trailer));
}

//add
template<typename T>
void DList<T>::add(const Iterator<T>& p, const T& e) {
    DNode<T>* w = p.v;
    DNode<T>* u = w->prev;
    DNode<T>* newDNode = new DNode<T>;
    newDNode->elem = e;
    newDNode->next = w;
    w->prev = newDNode;
    newDNode->prev = u;
    u->next = newDNode;
    n++;
}

//remove
template<typename T>
void DList<T>::remove(const Iterator<T>& p){
    DNode<T>* old = p.v;
    old->prev->next = old->next;
    old->next->prev = old->prev;
    delete old;
    n--;
}

//addFront
template<typename T>
void DList<T>::addFront(const T& e) {
    add(begin(), e);
}

//addBack
template<typename T>
void DList<T>::addBack(const T& e) {
    add(end(), e);
}

//removeFront
template<typename T>
void DList<T>::removeFront() {
    if (empty()) throw std::invalid_argument("Can't remove front, list is empty.");
    remove(begin());
}

//removeBack
template<typename T>
void DList<T>::removeBack() {
    if (empty()) throw std::invalid_argument("Can't remove back, list is empty.");
    remove(--end());
}

//operator[]
template<typename T>
const T& DList<T>:: operator[](int i) const {
    Iterator<T> p (begin());
    int j=0;
    while (j<i){
        ++j;
        ++p;
    }
    return p.v->elem;
}
