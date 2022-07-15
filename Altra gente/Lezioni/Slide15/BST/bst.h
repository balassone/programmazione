#ifndef BST_H
#define BST_H
#include <iostream>
using std::cout;
template <typename Key> class BST;


template <typename Key>
class BSTNode {
public:
	BSTNode(Key k, BSTNode<Key> *p = nullptr, BSTNode<Key> *l = nullptr, BSTNode<Key> *r = nullptr)
		: key(k), left (l), right(r), parent(p) {}
	friend class BST<Key>;
private:
	Key key;
	BSTNode<Key> *left;
	BSTNode<Key> *right;
	BSTNode<Key> *parent;	
};

template <typename Key>
class BST{
protected:
	BSTNode<Key> *root;
public:
	//constructors
	BST(BSTNode<Key>* r = nullptr): root(r) {}
	~BST() {release(root);}
	BST(const BST<Key> &t);
	
	//traverse
	void inOrderTreeWalk(BSTNode<Key>* x);
	void inOrderTreeWalk() {inOrderTreeWalk(root);}
	void preOrderTreeWalk(BSTNode<Key>*x);
	void preOrderTreeWalk(){preOrderTreeWalk(root);}
	void postOrderTreeWalk(BSTNode<Key>*x);
	void postOrderTreeWalk(){postOrderTreeWalk(root);}
	
	
	//accessors
	BSTNode<Key>* getRoot() {return root;}
	BSTNode<Key>* search(Key key);
	BSTNode<Key>* search(BSTNode<Key> *x, Key key);
	BSTNode<Key>* minimum() {return minimum(root);}
	BSTNode<Key>* minimum(BSTNode<Key> *subroot);
	BSTNode<Key>* maximum() {return maximum(root);}
	BSTNode<Key>* maximum(BSTNode<Key> *subroot);
	BSTNode<Key>* predecessor(BSTNode<Key>* x);
	BSTNode<Key>* successor(BSTNode<Key>* x);
	BSTNode<Key>* searchRecursive(Key key);
	BSTNode<Key>* searchRecursive(BSTNode<Key> *x, Key key);

	


	
	//modifiers
	void preOrderTreeInsert(BSTNode<Key>*x);
	BSTNode<Key>* insert(Key key);	//if return NULL; the key already exists
	BSTNode<Key>* insertRecursive(Key key);
	BSTNode<Key>* insertRecursive(BSTNode<Key> *x, BSTNode<Key> *y, BSTNode<Key> *z);
	void release(BSTNode<Key>* x);
	void deleteNode(Key key);
	// if return NULL, the key does not exsists
};

#endif

#include "bst.cpp"