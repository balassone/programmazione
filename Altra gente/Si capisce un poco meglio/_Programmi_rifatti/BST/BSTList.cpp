//BSTList.cpp

template<typename T>
BSTList<T>::BSTList() : root(nullptr) {}

template<typename T>
BSTList<T>::~BSTList() {}

template<typename T>
void BSTList<T>::inOrder(BSTNode<T>* x) {
    if (x){
        inOrder(x->left_child);
        cout<<x->key<<" ";
        inOrder(x->right_child);
    }
}

template<typename T>
BSTNode<T>* BSTList<T>::search(T key, BSTNode<T>* x){
    if (x == nullptr){
        return NULL;
    }
    if (x->key == key){
        return x;
    }
    if (key < x->key){
        return search(key, x->left_child);
    }
    if (x->key < key){
        return search(key, x->right_child);
    }
}

//maximum
template<typename T>
BSTNode<T>* BSTList<T>:: maximum(BSTNode<T>* subroot){
    BSTNode<T>* x = subroot;
    while (x->right_child){
        x = x->right_child;
    }
    return x;
}

//minimum
template<typename T>
BSTNode<T>* BSTList<T>:: minimum(BSTNode<T>* subroot){
    BSTNode<T>* x = subroot;
    while (x->left_child){
        x = x->left_child;
    }
    return x;
}

//successor
template<typename T>
BSTNode<T>* BSTList<T>::successor(BSTNode<T>* x) {
    BSTNode<T>* succ = nullptr;
    if (x->right_child){
        succ = minimum(x->right_child);
    }    
    else {
        succ = x->parent;
        while (succ && succ->right_child == x){
            x = succ;
            succ = x->parent;
        }
    }
    return succ;
}

//predecessor
template<typename T>
BSTNode<T>* BSTList<T>::predecessor(BSTNode<T>* x){
    BSTNode<T>* pred = nullptr;
    if (x->left_child){
        pred = maximum(x->left_child);
    }
    else {
        pred = x->parent;
        while (pred && pred == x){
            x = pred;
            pred = x->parent;
        }
    }
    return pred;
}

//insert
template<typename T>
BSTNode<T>* BSTList<T>::insert(T key) {
    if (search(key)){
        return nullptr;
    }
    BSTNode<T>* x = root;
    BSTNode<T>* y = nullptr;                //y serve per puntare al padre di x
    BSTNode<T>* z = new BSTNode<T> (key);
    while (x){
        y=x;                    
        if(z->key < x->key){
            x = x->left_child;
        } else x= x->right_child;
    }
    z->parent = y;
    if (y == nullptr){
        root = z;
    } else {
        if (z->key < y->key){
            y->left_child = z;
        } else {
            y->right_child = z;
        }
    }
    return z;
}