#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <string>

class LinkedList{
public:
    LinkedList();
    LinkedList(const LinkedList&);
    ~LinkedList();
    LinkedList& operator=(const LinkedList&);
    bool empty() const;
    LinkedList& addBack(const int&);
    std::string toString();
    const int& operator[](int i);
    LinkedList& removeFront();
    int size() const;
    void clear();
private:
    Node* head;
};

#include "LinkedList.cpp"
#endif