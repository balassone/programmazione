//CNode.h

#ifndef CNODE
#define CNODE

template<typename T> class CLinkedList;

template<typename T>
class CNode {
    friend class CLinkedList<T>;
    private:
        T elem;
        CNode* next;
};

#endif