//LinkedList.h
//LinkedList class definition
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Node.h"
#include<string>

template<typename NODETYPE>
class LinkedList {
    public:
        //funzioni base
        LinkedList();                                   //constructor
        ~LinkedList();                                  //destructor
        LinkedList(const LinkedList&);                  //copy constructor
        LinkedList& operator=(const LinkedList&);       //assignment operator
        
        bool empty() const;                             //is list empty?
        const NODETYPE& front() const;                  //front element
        void addFront(const NODETYPE&);                 //add element in front
        void removeFront();                             //remove element from front

        //funzioni "aggiuntive"        
        int size() const;                               //size of the list
        const NODETYPE& operator[](int) const;          //returns element in a specified position    
        int search(const NODETYPE&);                    //search a node containing an element
        void deleteElement(const NODETYPE&);            //delete an element of the list
        std::string toString() const;                   //show all elements in the list
    private:
        Node<NODETYPE>* head;
};

#endif

#include"LinkedList.cpp"