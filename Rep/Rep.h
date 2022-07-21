#include <iostream>
template <typename Key> class BST;
template <typename Key>
class BSTNode{
    public:
        BSTNode(Key k, BSTNode<Key>* p=nullptr, BSTNode<Key>* l=nullptr, BSTNode<Key>*r=nullptr): key(k), parent(p), left(l), right(r) {}
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
        BSTNode<Key>* root;
    public:
        BST(BSTNode<Key>* r=nullptr): root(r) {}
        ~BST(){
            release(root);
        }
        
        //traverse
        BST<Key>& inOrderTreeWalk(BSTNode<Key>* x);
        BST<Key>& inOrderTreeWalk(){inOrderTreeWalk(root);}
        BST<Key>& preOrderTreeWalk(BSTNode<Key>* x);
        BST<Key>& preOrderTreeWalk(){preOrderTreeWalk(root);}
        BST<Key>& postOrderTreeWalk(BSTNode<Key>* x);
        BST<Key>& postOrderTreeWalk(){postOrderTreeWalk(root);}

        BSTNode<Key>* root() const {return root;}
        BSTNode<Key>* search(BSTNode<Key>* x, Key key);
        BSTNode<Key>* search(Key key){return search (root,key);}
        BSTNode<Key>* recSearch(BSTNode<Key>* x, Key key);
        BSTNode<Key>* recSearch(Key key){return recSearch (root,key);}
        BSTNode<Key>* minimum(BSTNode<Key>* x);
        BSTNode<Key>* minimum() {return minimum(root);}
        BSTNode<Key>* maximum(BSTNode<Key>* x);
        BSTNode<Key>* maximum() {return maximum(root);}
        BSTNode<Key>* predecessor(BSTNode<Key>* x);
        BSTNode<Key>* successor(BSTNode<Key>* x);
        BSTNode<Key>* insert(BSTNode<Key>* x);
        BSTNode<Key>* remove(BSTNode<Key>* x);
        BST& release(BSTNode<Key>* x);

};

template <typename Key>
BST<Key>& BST<Key>::preOrderTreeWalk(BSTNode<Key>* x){
    if(x){
        std::cout << x->key << "\n";
        preOrderTreeWalk(x->left);
        preOrderTreeWalk(x->right):
    }
    return *this;
}
template <typename Key>
BST<Key>& BST<Key>::inOrderTreeWalk(BSTNode<Key>* x){
    if(x){
        inOrderTreeWalk(x->left);
        std::cout << x->key << "\n";
        inOrderTreeWalk(x->right);
    }
    return *this;
}

template <typename Key>
BST<Key>& BST<Key>::postOrderTreeWalk(BSTNode<Key>* x){
    if(x){
        postOrderTreeWalk(x->left);
        postOrderTreeWalk(x->right);
        std::cout << x->key << "\n";
    }
    return *this;
}
template <typename Key>
BSTNode<Key>* BST<Key>::search(BSTNode<Key>* x, Key key){
    while(x){
        if(x->key==key) return x;
        else if(x->key<key) x=x->right;
        else x=x->left;
    }
    return nullptr;
}
template <typename Key>
BSTNode<Key>* BST<Key>::recSearch(BSTNode<Key>* x, Key key){
    if(x){
        if(x->key==key) return x;
        if(x->key<key) return recSearch(x->right,key);
        else return recSearch(x->left,key);
    }
    return nullptr;
}

template <typename Key>
BSTNode<Key>* BST<Key>::minimum(BSTNode<Key>* x){
    BSTNode<Key>*a=x;
    if(a){
        while(a->left) a=a->left;
    }
    return a;
}

template <typename Key>
BSTNode<Key>* BST<Key>::maximum(BSTNode<Key>* x){
    BSTNode<Key>* a=x;
    if(a){
        while(a->right) a=a->right;
    }
    return a;
}

