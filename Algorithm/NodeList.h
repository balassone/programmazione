#ifndef NODELIST_H
#define NODELIST_H
template <typename T>
class NodeList{
private:
    class Node{
        friend class NodeList<T>;
    private:
        T elem;
        Node *prev;
        Node* next;
    };
public:
    class Iterator{
        public:
            T& operator*();
            bool operator==(const Iterator& p) const;
            bool operator!=(const Iterator& p) const;
            Iterator& operator++();
            Iterator& operator--();
            friend class NodeList<T>;
        private:
            Node* v;
            Iterator(Node* u);

    };
public:
    NodeList();
    int size() const;
    bool empty() const;
    Iterator begin() const;
    Iterator end() const;
    NodeList<T>& insertFront(const T& e);
    NodeList<T>& insertBack(const T& e);
    NodeList<T>& insert(const Iterator& p, const T& e);
    void eraseFront();
    void eraseBack();
    void erase(const Iterator& p);
private:
    int n;
    Node* header;
    Node* trailer;
};
template <typename T>
NodeList<T>::Iterator::Iterator(Node* u){
    v=u;
}
template <typename T>
T& NodeList<T>::Iterator::operator*(){
    return v->elem;
}
template <typename T>
bool NodeList<T>::Iterator::operator==(const Iterator& p) const{
    return v==p.v;
}
template <typename T>
bool NodeList<T>::Iterator::operator!=(const Iterator& p) const{
    return v!=p.v;
}
template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator++(){
    v=v->next;
    return *this;
}
template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator--(){
    v=v->prev;
    return *this;
}

template <typename T>
NodeList<T>::NodeList(){
    n=0;
    header=new Node;
    trailer=new Node;
    header->next=trailer;
    trailer->prev=header;
}

template <typename T>
int NodeList<T>::size() const{
    return n;
}

template <typename T>
bool NodeList<T>::empty() const{
    return n==0;
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::begin() const{
    return Iterator(header->next);
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::end() const{
    return Iterator(trailer);
}

template <typename T>
NodeList<T>& NodeList<T>::insert(const NodeList::Iterator& p, const T& e){
    Node* w = p.v;
    Node* u = w->prev;
    Node* v = new Node;
    v->elem=e;
    v->next=w;
    w->prev=v;
    v->prev=u;
    u->next=v;
    n++;
    return *this;
}

template <typename T>
NodeList<T>& NodeList<T>::insertFront(const T& e){
    insert(begin(),e);
    return *this;
}
template <typename T>
NodeList<T>& NodeList<T>::insertBack(const T& e){
    insert(end(),e);
    return *this;
}

template <typename T>
void NodeList<T>::eraseFront(){
    erase(begin());
}
template <typename T>
void NodeList<T>::eraseBack(){
    erase(--end());
}

template <typename T>
void NodeList<T>::erase(const NodeList::Iterator& p){
    Node* v = p.v;
    Node* u = v->prev;
    Node* w = v->next;
    u->next=w;
    w->prev=u;
    delete[] v;
    n--;
}
#endif