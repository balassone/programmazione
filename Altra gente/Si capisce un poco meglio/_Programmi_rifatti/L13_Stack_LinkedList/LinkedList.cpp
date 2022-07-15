//LinkedList.cpp
//LinkedList class implementation
#include<stdexcept>
#include<sstream>
#include<iostream>


//constructor
template<typename NODETYPE>
LinkedList<NODETYPE>:: LinkedList() : head(nullptr) {}

//copy constructor
template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList(const LinkedList<NODETYPE>& list){
    head=nullptr;
    for (int i=0; i<list.size(); i++){
        addFront(list[i]);
    }
}

//destructor
template<typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList() {
    while (!empty()){
        removeFront();
    }
}

//assignment operator =
template<typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>:: operator=(const LinkedList<NODETYPE>& list){
    if (this==&list){
        return *this;
    }
    while(!empty()){
        this->removeFront();
    }
    delete head;
    head = new Node<NODETYPE>;
    head=nullptr;
    for (int i=0; i<list.size(); i++){
        addFront(list[i]);
    }
    return *this;
}

//is list empty?
template<typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const {
    return (head == nullptr);
}

//return front element
template<typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::front() const {
    if (!empty()){
        return head->elem;
    }
    else throw std::invalid_argument("List is empty");
}

//add element in front
template<typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE& e){
    Node<NODETYPE>* newNode = new Node<NODETYPE>;
    newNode->elem = e;
    newNode->next = head;
    head = newNode;
}

//remove element from front
template<typename NODETYPE>
void LinkedList<NODETYPE>::removeFront() {
    if (!empty()){
        Node<NODETYPE>* old = head;
        head = old->next;
        delete old;
    }
    else {
        throw std::invalid_argument("List is empty");
    }
}

//size of the list
template<typename NODETYPE>
int LinkedList<NODETYPE>::size() const{
    int i=0;
    Node<NODETYPE>* ptr = head;
    while (ptr!= nullptr){
        ptr = ptr->next; 
        i++;
    }
    delete ptr;
    return i;
}

//overloading operator[]
template<typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::operator[](int i) const{
    if (i>=size()){
        throw std::invalid_argument("element outside list dimension");
    }
    Node<NODETYPE>* ptr = head;
    int j=0;
    while (j != size()-1-i) {
        ptr = ptr->next;
        j++;
    }
    return ptr->elem;
    delete ptr;
}

template<typename NODETYPE>
int LinkedList<NODETYPE>::search(const NODETYPE& e) {
    Node<NODETYPE>* ptr = head;
    int i=size()-1;
    int count{0};
    while (ptr!=nullptr && i>=0){
        if(ptr->elem == e){
            count++;
            return i;
        }
        ptr = ptr->next;
        i--;
    }
    if (count==0){
        std::cout<<"L'elemento non e' stato trovato: ";  
    }
    return -1;
}

//delete an element from the list
template<typename NODETYPE>
void LinkedList<NODETYPE>::deleteElement(const NODETYPE& e){
    if (empty()) throw std::invalid_argument("List is empty");
    
    if(size()==1 || e == front()){
        removeFront();
    }
    else {
        Node<NODETYPE>* ptr = head;
        Node<NODETYPE>* prev;
        int i=search(e);
        int j=0;
        while (i != size()-1-j){
            prev = ptr;
            ptr = ptr->next;
            j++;
        }
        prev->next = ptr->next;
        delete[] ptr;
    }
}

//show elements in the list
template<typename NODETYPE>
std::string LinkedList<NODETYPE>::toString() const{
    if (empty()) throw std::invalid_argument("List is empty");

    std::ostringstream out;

    Node<NODETYPE>* ptr = head;
    int i=0;
    NODETYPE elementi[size()];

    while (ptr != nullptr){
        elementi[i] = ptr->elem;
        i++;
        ptr = ptr->next;
    }

    for (i=size()-1; i>=0; i--){
        out<<elementi[i]<<" ";
    }
    
    return out.str();
}
