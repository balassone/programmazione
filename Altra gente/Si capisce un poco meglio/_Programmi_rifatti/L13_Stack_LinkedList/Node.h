//Node.h
//Node class definition

#ifndef NODE_H
#define NODE_H

#include<string>
#include<sstream>
#include<iostream>

template<typename NODETYPE> class LinkedList;

template<typename NODETYPE>
class Node {
    private:
        NODETYPE elem;
        Node* next;
        
        friend class LinkedList<NODETYPE>;

};


#endif