#include "Task.h"
#include <string>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList&);
        LinkedList& operator=(const LinkedList&);
        int size() const;
        bool empty() const;
        LinkedList& removeFront();
        LinkedList& addOrder(const Task&);
        std::string toString() const;
        Task& operator[](int i);
    private:
        Node* head;
};
#endif