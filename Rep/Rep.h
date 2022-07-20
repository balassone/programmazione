#include <iostream>
template <typename Key> class BST;
template <typename Key>
class BSTNode{
    public:
        BSTNode(Key k, BSTNode<Key>* p=nullptr, BSTNode<Key>* l=nullptr, BSTNode<Key>* r=nullptr): key(k), parent(p), left(l), right(r) {}
        friend class BST<Key>;
    private:
        Key key;
        BSTNode<Key>* parent;
        BSTNode<Key>* left;
        BSTNode<Key> right;
};

template<typename Key>
class BST{
    protected:
        BSTNode<Key>* root;
    public:
        BST(BSTNode<Key>* r=nullptr): root(r) {}
        ~BST() {release(root);}

        BST<Key>& inorderTreeWalk(BSTNode<Key>* x);
        BST<Key>& inorderTreeWalk(){return inorderTreeWalk(root);}
        BST<Key>& preorderTreeWalk(BSTNode<Key>* x);
        BST<Key>& preorderTreeWalk(){return preorderTreeWalk(root);}
        BST<Key>& postorderTreeWalk(BSTNode<Key>* x);
        BST<Key>& postorderTreeWalk(){return postorderTreeWalk(root);}

        BSTNode<Key>* root() const {return root;}
        BSTNode<Key>* search(Key k, BSTNode<Key>* x);
        BSTNode<Key>* search(Key k) {return search(k,root);}
        BSTNode<Key>* recSearch(Key k, BSTNode<Key>* x);
        BSTNode<Key>* recSearch(Key k) {return recSearch(k,root);}
        BSTNode<Key>* predecessor(BSTNode<Key>*);
        BSTNode<Key>* successor(BSTNode<Key>*);
        BSTNode<Key>* minimum(BSTNode<Key>*);
        BSTNode<Key>* minimum() {return minimum(root);}
        BSTNode<Key>* maximum(BSTNode<Key>*);
        BSTNode<Key>* maximum(){return maximum(root);}
        BSTNode<Key>* remove(BSTNode<Key>*);
        BSTNode<Key>* insert(Key key);
        BST<Key>& release(BSTNode<Key>*);

};
