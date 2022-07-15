#ifndef BSTNODE_H
#define BSTNODE_H

template<typename T>
class BSTList;

template<typename T>
class BSTNode {
    friend class BSTList<T>;
    BSTNode(T k, BSTNode<T> l = nullptr, BSTNode<T> r = nullptr, BSTNode<T> p = nullptr) : key(k), left_child(l), right_child(r), parent(p){}
    private:
        T key;
        BSTNode<T>* left_child;
        BSTNode<T>* right_child;
        BSTNode<T>* parent;
};

#endif

