#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <exception>
#include "Task.h"
using std::runtime_error;


class Progetto;
class LinkedList{

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& lhs);
    void addBack(const Task& t);
    void addFront(const Task& e);
    LinkedList& operator=(const LinkedList &lhs);
    bool empty() const;
    void removeFront();
    void addOrder(const Task&);
    int size();
    void add(const Task& e, Node* p);
    Task& operator[](int);

    void print();
    

private:
    Node* head;

friend class Progetto;
};






#endif
