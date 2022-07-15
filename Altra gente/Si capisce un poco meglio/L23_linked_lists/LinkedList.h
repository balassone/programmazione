//LinkedList.h

/**********  nullptr<-------<---head     ********/

#include"Node.h"
#include<iostream>

template <typename NODETYPE> class LinkedList {
    public:
        LinkedList();                       //empty list constructor
        
        ~LinkedList();                      //destructor

        
        bool empty() const;                 //is list empty?
        
        const NODETYPE& front() const;      //return front element
        void addFront(const NODETYPE& e);   //add front element
        void removeFront();                 //remove front item list

    private:
        Node<NODETYPE>* head;               //head of the list
};
#include"LinkedList.cpp"