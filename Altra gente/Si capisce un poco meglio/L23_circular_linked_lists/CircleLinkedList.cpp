//CircleLinkedList.cpp
#include<iostream>
#include<sstream>

template<typename T>
CircleList<T>::CircleList() : cursor{nullptr}{}             //constructor

template<typename T>                                        //destructor
CircleList<T>::~CircleList(){
    while(!empty()){
        remove();
    }
}

template<typename T>
bool CircleList<T>::empty() const {      //is list empty?
    return cursor==nullptr;
}

template<typename T>                    //advance cursor
void CircleList<T>::advance(){
    cursor=cursor->next;
}

template<typename T>
void CircleList<T>::remove(){           //remove node after cursor
    CNode<T>* old = cursor->next;       //define "old" as a pointer to CNode and as the node to remove (so, after cursor)
    if (old==cursor){                   //if cursor is the only element in the list
        cursor=nullptr;                 //list is now empty
    }
    else{
        cursor->next = old->next;        //now cursor points to next element, which is that after element removed
    }
    delete old;   
}

template<typename T>
void CircleList<T>::add(const T& e){    //add newNode after cursor
    CNode<T>* newNode = new CNode<T>;   //create a new node
    newNode->elem = e;
    if (cursor==nullptr){               //is list empty?
        newNode->next=newNode;          //newNode points to itself
        cursor=newNode;                 //cursor points to newNode
    }
    else {
        newNode->next=cursor->next;     //link the node after the cursor
        cursor->next=newNode;
    }
}

template<typename T>
const T& CircleList<T>::back() const{   //element at the cursor
    if (empty()){
        return nullptr;
    }
    return cursor->elem;
}

template<typename T>
const T& CircleList<T>::front() const{  //element following the cursor
    return cursor->next->elem;
}

template<typename T>
std::string CircleList<T>::toString() {
    std::ostringstream out;
    CNode<T>* u=cursor;
    out<<"Cursor-->";
    out<<u->elem<<"-->";
    u=u->next;
    while (u != cursor){
        out<<u->elem<<"-->";
        u=u->next;
    }
    out<<"Cursor";
    return out.str();
}