#include "Node.h"
#include <string>

template <typename NODETYPE>
class LinkedList{
public:
    LinkedList();
    LinkedList(const LinkedList<NODETYPE>&);
    ~LinkedList();
    LinkedList<NODETYPE>& operator=(const LinkedList<NODETYPE>&);
    bool isEmpty() const;
    LinkedList<NODETYPE>& addFront(const NODETYPE&);
    const NODETYPE& getFront() const;
    LinkedList<NODETYPE>& removeFront();
    LinkedList<NODETYPE>& reverse();
    std::string toString() const;
    NODETYPE& operator[](int);
    int getLength() const;
    LinkedList<NODETYPE>& clear();
    LinkedList<NODETYPE>& addBack(const NODETYPE&);
    LinkedList<NODETYPE>& removeBack();
    LinkedList<NODETYPE>& remove(const int&);
    LinkedList<NODETYPE>& addOrder(const NODETYPE&);
    int search(const NODETYPE&) const;
private:
    Node<NODETYPE>* head;
};

#include "LinkedList.cpp"
