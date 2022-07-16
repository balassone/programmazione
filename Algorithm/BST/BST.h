#ifndef BST_H
#define BST_H
#include <iostream>
template <typename Key> class BST;

template <typename Key>
class BSTNode{
    public:
        BSTNode(Key k, BSTNode<Key> *p=nullptr, BSTNode<Key> *l=nullptr, BSTNode<Key> *r=nullptr) : key(k), parent(p), left(l), right(r){}
        friend class BST<Key>;
    private:
        Key key;
        BSTNode<Key>* left;
        BSTNode<Key>* right;
        BSTNode<Key>* parent;
};
template <typename Key>
class BST{
    protected:
        BSTNode<int>* root;
    public:
        BST(BSTNode<Key>* r=nullptr) : root(r){}
        //destructor
        ~BST(){
            release(root);
        }
        //traverse
        void inorderTreeWalk(BSTNode<Key>* x);
        void inorderTreeWalk() {inorderTreeWalk(root);}
        void preorderTreeWalk(BSTNode<Key>* x);
        void preorderTreeWalk() {preorderTreeWalk(root);}
        void postorderTreeWalk(BSTNode<Key>* x);
        void postorderTreeWalk() {postorderTreeWalk(root);}
        
        //Accessors
        BSTNode<Key>* getRoot() const {return root;}
        BSTNode<Key>* search(Key key);
        BSTNode<Key>* search(BSTNode<Key>* x, Key key);
        BSTNode<Key>* recSearch(Key key);
        BSTNode<Key>* recSearch(BSTNode<Key>* x, Key key);
        BSTNode<Key>* minimum() {return minimum(root);}
        BSTNode<Key>* minimum(BSTNode<Key>* subroot);
        BSTNode<Key>* maximum() {return maximum(root);}
        BSTNode<Key>* maximum(BSTNode<Key>* subroot);
        BSTNode<Key>* predecessor(BSTNode<Key>* x);
        BSTNode<Key>* successor(BSTNode<Key>* x);
        BSTNode<Key>* deleteNode(BSTNode<Key>* x);
        //Modifiers
        BSTNode<Key>* insert(Key key);
        void release(BSTNode<Key>* x);
};
template <typename Key>
void BST<Key>::inorderTreeWalk(BSTNode<Key>* x){
    if(x!=nullptr){
        inorderTreeWalk(x->left);
        std::cout<<x->key<<"\n";
        inorderTreeWalk(x->right);
    }
}
template <typename Key>
void BST<Key>::preorderTreeWalk(BSTNode<Key>* x){
    if(x!=nullptr){
        std::cout<<x->key<<"\n";
        preorderTreeWalk(x->left);
        preorderTreeWalk(x->right);
    }
}
template <typename Key>
void BST<Key>::postorderTreeWalk(BSTNode<Key>* x){
    if(x!=nullptr){
        postorderTreeWalk(x->left);
        postorderTreeWalk(x->right);
        std::cout<<x->key<<"\n";
    }
}
template <typename Key>
BSTNode<Key>* BST<Key>::search(BSTNode<Key> *x, Key key){
    while(x){
        if(key==x->key)
            break;
        else if(key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    return x;
}

template <typename Key>
BSTNode<Key>* BST<Key>::recSearch(BSTNode<Key>* x, Key key){
    if(x==nullptr){
        return nullptr;
    }
    if(x->key==key){
        return x;
    }
    if(x->key<key){
        return recSearch(x->right, key);
    } else{
        return recSearch(x->left,key);
    }
}

template <typename Key>
BSTNode<Key>* BST<Key>::recSearch(Key key){
    return recSearch(root,key);
}

template <typename Key>
BSTNode<Key>* BST<Key>::search(Key key){
    return search(root, key);
}

template <typename Key>
BSTNode<Key>* BST<Key>::minimum(BSTNode<Key>* subroot){
    BSTNode<Key>* x=subroot;
    if (x){
        while(x->left)
            x=x->left;
        }
    return x;
}
template <typename Key>
BSTNode<Key>* BST<Key>::maximum(BSTNode<Key>* subroot){
    BSTNode<Key>* x=subroot;
    if (x){
        while(x->right)
            x=x->right;
        }
        return x;
}
template <typename Key>
BSTNode<Key>* BST<Key>::predecessor(BSTNode<Key>* x){
    BSTNode<Key>* prev = nullptr;
    if(x->left){
        prev = maximum(x->left);
    }
    else{
        prev = x->parent;
        while(prev && x==prev->left){
            x=prev;
            prev=prev->parent;
        }
    }
    return prev;
}

template <typename Key>
BSTNode<Key>* BST<Key>::successor(BSTNode<Key>* x){
    BSTNode<Key>* succ = nullptr;
    if(x->right){
        succ = minimum(x->right);
    }
    else{
        succ = x->parent;
        while(succ && x==succ->right){
            x=succ;
            succ=succ->parent;
        }
    }
    return succ;
}

template <typename Key>
BSTNode<Key>* BST<Key>::insert(Key key){
    BSTNode<Key>* z = new BSTNode<Key>(key);
    BSTNode<Key>* y = nullptr;
    BSTNode<Key>* x = root;
    while(x){
        y=x;
        if(z->key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    z->parent=y;
    if(!y)
        root=z;
    else if(z->key<y->key)
        y->left=z;
    else
        y->right=z;
    return z;
}
template <typename Key>
//deleteNode
BSTNode<Key>* BST<Key>::deleteNode(BSTNode<Key>* x){
    BSTNode<Key>* y;
    if(!x->left)
        y=x->right;
    else if(!x->right)
        y=x->left;
    else
        y=successor(x);
    if(y->left)
        y->left->parent=x->parent;
    if(!x->parent){
        root=y;
    }
    else if(x==x->parent->left)
        x->parent->left=y;
    else
        x->parent->right=y;
    if(x!=y){
        y->left=x->left;
        x->left->parent=y;
        y->right=x->right;
        x->right->parent=y;
    }
    return y;
}
#endif