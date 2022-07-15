#include"DNode.h"
//#include"Iterator.h"
#ifndef ITERATOR_H
#define ITERATOR_H

template<typename T>
class Iterator {
    public:
        T& operator*();                                     //reference to element
        bool operator == (const Iterator&) const;           //compare positions
        bool operator != (const Iterator&) const;           //idem
        Iterator& operator++();                             //move to next position (preincrement)
        Iterator& operator--();                             //move to previous position (predecrement)

        friend class DList<T>;

    private:
        DNode<T>* v;
        Iterator(DNode<T>* u);
};

#include"Iterator.cpp"

#endif