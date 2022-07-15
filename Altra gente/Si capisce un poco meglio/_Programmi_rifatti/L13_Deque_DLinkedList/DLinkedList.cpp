//DLinkedList.cpp
//implementation of doubly linked list class
//                            next    next
//                  header ---->------->------> trailer
//                         <---<-------<-------
//                            prev    prev
#include<sstream>
#include<stdexcept>

//constructor
template<typename T>
DLinkedList<T> ::DLinkedList() {
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->prev = nullptr;
    header->next = trailer;
    trailer->next = nullptr;
    trailer->prev = header;
}

//destructor
template<typename T>
DLinkedList<T>::~DLinkedList() {
    while (!empty()){
        removeFront();
    }
    delete header;
    delete trailer;
}

//copy constructor
template<typename T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& list) {
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    trailer->prev = header;
    header->prev = nullptr;
    trailer->next = nullptr;
    for (int i=0; i<list.size(); i++){
        addFront(list[i]);
    }
}

//overloading assignment operator =
template<typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList& list){
    if (this == &list){
        return *this;
    }
    ~DLinkedList();
    //header = new DNode<T>;
    //trailer = new DNode<T>;
    for (int i=0; i< list.size(); i++){
        addFront(list[i]);
    }

}

//is list empty?
template<typename T>
bool DLinkedList<T>::empty() const {
    return (header->next == trailer);
}

//size of the list
template<typename T>
int DLinkedList<T>::size() const {
    DNode<T>* ptr = header->next;
    int count{0};
    while (ptr != trailer) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

//add an element in front of the list
template<typename T>
void DLinkedList<T>::addFront(const T& e){
    add(header->next, e);
}

//add an element in back of the list
template<typename T>
void DLinkedList<T>::addBack(const T& e){
    add(trailer, e);
}

//remove element in front of the list
template<typename T>
void DLinkedList<T>::removeFront() {
    if(empty()){
        throw std::invalid_argument("List is empty, you can't remove elements.");
    }
    remove(header->next);
}

//remove element in back of the list
template<typename T>
void DLinkedList<T>::removeBack() {
    if(empty()){
        throw std::invalid_argument("List is empty, you can't remove elements.");
    }
    remove(trailer->prev);
}

//returns front element 
template<typename T>
const T& DLinkedList<T>::front() const {
    if (!empty()){
         return (header->next->elem);
    }
    else throw std::invalid_argument("list is empty.");
}

//returns back element 
template<typename T>
const T& DLinkedList<T>::back() const {
    if (!empty()){
         return (trailer->prev->elem);
    }
    else throw std::invalid_argument("list is empty.");
}

//add in order
template<typename T>
void DLinkedList<T>::addInOrder(const T& e){
    DNode<T>* ptr = header->next;
    while (ptr != trailer){
        if (ptr->elem < e) {
            break;
        }
        ptr = ptr->next;
    }
    add (ptr, e);
}
   

//add an element in a position specified
template<typename T>
void DLinkedList<T>::add(DNode<T>* v, const T& e) {
    DNode<T>* newNode = new DNode<T>;
    newNode->next =v;
    newNode->prev = v->prev;
    v->prev->next = newNode;
    v->prev =newNode;
    newNode->elem = e;
}

//remove an element from position specified
template<typename T>
void DLinkedList<T>::remove(DNode<T>* v) {
    if (empty()) {
        throw std::invalid_argument("List is empty");
    }
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

//toString function
template<typename T>
std::string DLinkedList<T>::toString() const {
    std::ostringstream out;
    out<<"Header <-> ";
    DNode<T>* ptr = header->next;
    while (ptr!=trailer) {
        out<<ptr->elem<<" ";
        ptr = ptr->next;
    }
    out<<"<-> Trailer";
    return out.str();
}


//operator[]
template<typename T>
const T& DLinkedList<T>::operator[](int i) const {
    DNode<T>* ptr = trailer->prev;
    for (int j=0; j<i; j++){
        ptr = ptr->prev;
    }
    return (ptr->elem);
}


