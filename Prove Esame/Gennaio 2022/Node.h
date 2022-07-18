#include "Pacco.h"
#ifndef NODE_H
#define NODE_H
class LinkedList;

class Node{
    private:
        Node* next;
        Pacco* elem;
        friend class LinkedList;
};
#endif