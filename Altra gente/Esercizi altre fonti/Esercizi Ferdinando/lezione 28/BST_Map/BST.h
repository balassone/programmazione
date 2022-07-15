#ifndef BST_H
#define BST_H

#include "Node.h"
#include <iostream>

template <typename T>
class BST{

public:
    BST(Node<T>* = nullptr);
    ~BST();
    void inorder(Node<T>*); //modalità di esplorazione dell'albero
    Node<T>* getRoot();
    Node<T>* search(T key); //modalità di ricerca che prende come argomento solo l'elemento da ricercare
    Node<T>* search(Node<T>*,T)//modalità di ricerca che prende il ingresso oltre all'ellemento da ricercare anche il nodo da cui partire
    Node<T>* minimum();
    Node<T>* minimum(Node<T>*); //funzione che trova il minimo a partire da un nodo
    Node<T>* maximum();
    Node<T>* maximum(Node<T>*); //funzione che trova il massimo a partire da un nodo
    Node<T>* predecessor(Node<T>*);
    Node<T>* successor(Node<T>*);

    Node<T>* insert(T); //se ritorna nullptr, allora la chiave già esiste
    void release(Node<T>*);

private:
    Node<T>* root;
};

template <typename T>
BST<T>::BST(Node<T>* r)
    : root{r};

template <typename T>
BST<T>::~BST(){
    release(root);
}

template <typename T>
BST<T>::getRoot() {return root;}

template <typename T>
void BST<T>::inorder(Node<T>* x){
    if(x!=nullptr){
        inorder(x->left);
        std::cout<<(x->key);
        inorder(x->right);
    }
}

template <typename T>
Node<T>* BST<T>::search(Node<T>* x,T key){
    while(x!=nullptr){
        if(x->key==key) return x;
        else if(x->key>key) x=x->left;
        else x=x->right;
    }
}

template <typename T>
Node<T>* BST<T>::search(T key){
    return search(root,key);
}

template <typename T>
Node<T>* BST<T>::minimum(Node<T>* x){
    if(x!=nullptr){
        while(x->left) x=x->left;
    }
    return x;
}

template <typename T>
Node<T>* BST<T>::maximum(Node<T>* x){
    if(x!=nullptr){
        while(x->right) x=x->right;
    }
    return x;
}

template <typename T>
Node<T>* BST<T>::minimum(){
    minimum(root);
}

template <typename T>
Node<T>* BST<T>::maximum(){
    maximum(root);
}

template <typename T>
Node<T>* BST<T>::predecessor(Node<T>* x){
    Node<T>* prev=nullptr;
    if((x->left)!=nullptr) prev=maximum(x->left);
    else{
        prev=x->parent;
        while(prev!=nullptr && prev->left==x){
            x=prev;
            prev=x->parent;
        }
    }
    return prev;
}

template <typename T>
Node<T>* BST<T>::successor(Node<T>* x){
    Node<T>* succ=nullptr;
    if((x->right)!=nullptr) prev=minimum(x->right);
    else{
        succe=x->parent;
        while(succ!=nullptr && succ->right==x){
            x=succ;
            succ=x->parent;
        }
    }
    return succ;
}

template <typename T>
Node<T>* BST<T>::insert(T key){
    if(search(key)) return nullptr;
    Node<T>* x=root;
    Node<T>* y=nullptr;
    Node<T>* z=new Node<T>(key);
    while(x!=nullptr){
        y=x;
        if(z->key < x->key) x=x->left;
        else x=x->right;
    }
    z->parent=y;
    if(y==nullptr) root=z;
    else{
        if(z->key<y->key) y->left=z;
        else y->right=z;
    }
    return z;
}


#endif