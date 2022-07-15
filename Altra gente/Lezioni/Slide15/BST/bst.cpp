

template<typename Key>
void BST<Key>::inOrderTreeWalk(BSTNode<Key>* x) {
	if(x) {
		inOrderTreeWalk(x->left);
		//visit the node: here you can substitute your visitor function
		cout << x->key <<" \n";
		inOrderTreeWalk(x->right);
		}	
}

template<typename Key>
BSTNode<Key>* BST<Key>::search(BSTNode<Key> *x, Key key) {
	while (x) {
		if(x->key == key) break;
		else if( x->key < key) x = x->right;
		else x = x->left;
	}
	return x;
}

template<typename Key>
BSTNode<Key>* BST<Key>::search(Key key) {
	return search(root, key);
}

template <typename Key>
BSTNode<Key>* BST<Key>::minimum(BSTNode<Key> *subroot) {
	BSTNode<Key>* x = subroot;
	if(x){
		while (x->left) x = x->left;
	}	
	return x;
}

template<typename Key>
BSTNode<Key>* BST<Key>::maximum(BSTNode<Key> *subroot) {
	BSTNode<Key>* x = subroot;
	if(x){
		while (x->right) x = x->right;
	}
	return x;
}

template<typename Key>
BSTNode<Key>* BST<Key>::predecessor(BSTNode<Key>* x) {
	BSTNode<Key>* prev = NULL;
	if(x->left) prev = maximum(x->left);
	else{
		prev = x->parent;
		while(prev && prev->left == x) {
			x = prev;
			prev = x->parent;
		}
	}
	return prev;
}

template <typename Key>
BSTNode<Key>* BST<Key>::successor(BSTNode<Key>*x) {
	BSTNode<Key>* succ = nullptr;
	if (x->right) succ = minimum(x->right);
	else {
		succ = x->parent;
		while (succ && succ->right == x) {
			x = succ;
			succ = x->parent;
		}
	}
	return succ;	
}

template <typename Key>
BSTNode<Key>* BST<Key>::insert(Key key) {
	if (search(key)) return nullptr;
	BSTNode<Key> *x = root;
	BSTNode<Key> *y = nullptr;
	BSTNode<Key>* z = new BSTNode<Key>(key);
	while(x) {
		y = x;
		if(z->key < x->key) x = x->left;
		else x = x->right;
	}
	z->parent = y;
	if(y==nullptr)
		root = z;
	else {
		if(z->key < y->key)
			y->left = z;
		else
			y->right = z;
	}
	return z;
}
template <typename Key>
void BST<Key>::release(BSTNode<Key>* x) {delete x; }

template <typename Key>
void BST<Key>::deleteNode(Key key){
	if(search(key) == nullptr) return;
	BSTNode<Key> *z = search(key);
	BSTNode<Key> *y = nullptr;
	BSTNode<Key> *x = nullptr;
	if((z->left == nullptr) || (z->right == nullptr)) 
		{y = z;}
	else {y = successor(z);}

	
	if (y->left != nullptr)
		{x = y->left;}
	else 
		{x = y->right;}
	
	if (x != nullptr)
		{x->parent = y->parent;}

		
	if (y->parent == nullptr)
		{root = x;}
	
	else if (y == y->parent->left)
		{y->parent->left = x;}
	
	else 
		{y->parent->right = x;}
	
	if (y!= z)
		{z->key = y->key;}
	
	release(y);
	
}
template <typename Key>

BSTNode<Key>* BST<Key>::searchRecursive(Key key){return searchRecursive(root, key);}
template <typename Key>
BSTNode<Key>* BST<Key>::searchRecursive(BSTNode<Key>* x, Key key){
	if(x == nullptr){
		return nullptr;
	}
	else {
		if (x->key == key){
			return x;
		}
		else if(x->key > key){
			return searchRecursive(x->left, key);
		}
		else{
			return searchRecursive(x->right, key);
		}
	}
}


template <typename Key>
BSTNode<Key>* BST<Key>::insertRecursive(Key key){
	if(search(key)){return nullptr;}
	else{
		return insertRecursive(root, nullptr, key);
	}
}
template <typename Key>
BSTNode<Key>* BST<Key>::insertRecursive(BSTNode<Key> *x, BSTNode<Key> *y, Key k){
    if(x == nullptr){
		BSTNode<Key> *z = new BSTNode<Key>(k)
        if (y == nullptr)
        {
            root = z;
            return z;
        }
        else {
            z->parent = y;
            (y->key > z->key) ? y->left = z : y->right = z;
            return z;
        }
    }
    else
    {
        y = x;
        (x->key > z->key)? x = x->left : x = x->right;
        return insertRecursive(x,y,z);
    }
    
}
template <typename Key>
BST<Key>::BST(const BST<Key>& t){
	//paradigma di inserimento secondo il preOrderTreeWalk
	BSTNode<Key>* x = t.root;
	if(x){
		root = new BSTNode<Key>(t.root->key);
		preOrderTreeInsert(x);
	}
	else 
	root = nullptr;
	
}

template <typename Key>
void BST<Key>::preOrderTreeInsert(BSTNode<Key>*x){
	if(x)
	{
		insert(x->key);
		preOrderTreeInsert(x->left);
		preOrderTreeInsert(x->right);
	}
}

template <typename Key>
void BST<Key>::preOrderTreeWalk(BSTNode<Key>*x){
	if(x)
	{
		cout << x->key <<" \n";
		preOrderTreeWalk(x->left);
		preOrderTreeWalk(x->right);
	}
}
template <typename Key>
void BST<Key>::postOrderTreeWalk(BSTNode<Key>*x){
	if(x)
	{
		postOrderTreeWalk(x->left);
		postOrderTreeWalk(x->right);
		cout << x->key << "\n";	
		
	}
}