#ifndef NODE_H
#define NODE_H

template <typename T> class BST;

template <typename T>
class Node{

public:
    Node(T k,Node<T>* l=nullptr,Node<T>* r=nullptr,Node<T>* p=nullptr)
        : key{k}, left{l}, right{r}, parenti{p} {}
    //ogni nodo avrà 3 puntatori e una chiave
    
    friend class BST<T>;

private:
    T key;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

};

#endif