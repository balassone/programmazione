#include "Task.h"
#ifndef NODE_H
#define NODE_H
class LinkedList;

class Node{
    private:
        Node* next;
        Task elem;
        friend LinkedList;
};
#endif