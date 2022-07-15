//DNode.h
#ifndef DNODE_H
#define DNODE_H

template<typename T>
class Iterator;

template<typename T>
class DList;

template<typename T>
class DNode {
    friend class DList<T>;
    friend class Iterator<T>;
    private:
        DNode<T>* next;
        DNode<T>* prev;
        T elem;
};

#endif