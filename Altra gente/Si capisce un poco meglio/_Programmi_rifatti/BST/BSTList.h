//BSTList.h

#ifndef BSTLIST_H
#define BSTLIST_H
#include"BSTNode.h"
#include<iostream>

template<typename T>
class BSTList{
    protected:
        BSTNode<T>* root;
    public:
        BSTList();                                                      //constructor
        ~BSTList() {release(root)};                                     //destructor

        //traverse
        void inOrder(BSTNode<T>* x);                                    //Tree walk in order
        void inOrder() {return inOrder root;};                          //Tree walk in order from root

        //additive
        BSTNode<T>* search(T key, BSTNode<T>* x);                       //search from node x
        BSTNode<T>* search(T key)  { return search(key, root)}          //search from root
        BSTNode<T>* maximum(BSTNode<T>* x);                             //MAX
        BSTNode<T>* maximum(){return maximum(root)};                    //MAX
        BSTNode<T>* minimum(BSTNode<T>* x);                             //MIN
        BSTNode<T>* minimum() {return minimum(root)};                   //MIN
        BSTNode<T>* successor(BSTNode<T>* x);                           //Predecessor
        BSTNode<T>* predecessor(BSTNode<T>* x);                         //Successor

        //Modfifiers
        BSTNode<T>* insert(T key);
        void release(BSTNode<T>* x);
        
    private:
        BSTNode<T>* root;
};
#endif

#include"BSTList.cpp"