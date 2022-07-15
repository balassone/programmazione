#ifndef LIST_H
#define LIST_H

template <typename T>
class List{
private:
    class Node{
        friend class List<T>;
    private:
        T elemento;
        Node* next;
        Node* prev; 
    };

public:
    class Iterators{
    public:
        T& operator*();
        bool operator==(const Iterators&);
        bool operator!=(const Iterators&);
        Iterators& operator++();
        Iterators& operator--();
        friend class List<T>;

    private:
        Node* v;
        Iterators(Node* s);
    };

    List();
    int size() const;
    bool empty() const;
    Iterators begin() const;
    Iterators end() const;
    void insertionFront(const T&);
    void insertionBack(const T&);
    void insert(const Iterators&,const T&);
    void removeFront();
    void removeBack();
    void remove(const Iterators&);
    void insertOrder(const T&);

private:
    Node* header;
    Node* trailer;
    int n;

};

template <typename T>
List<T>::Iterators::Iterators(Node* s){
    v=s;
}

template <typename T>
T& List<T>::Iterators::operator*(){
    return v->elemento;
}

template <typename T>
bool List<T>::Iterators::operator==(const Iterators& i){
    return v==i.v;
}

template <typename T>
bool List<T>::Iterators::operator!=(const Iterators& i){
    return v!=i.v;
}

template <typename T>
typename List<T>::Iterators& List<T>::Iterators::operator++(){
    v=v->next;
    return *this;
}

template <typename T>
typename List<T>::Iterators& List<T>::Iterators::operator--(){
    v=v->prev;
    return *this;

}

template <typename T>
List<T>::List(){
    header=new Node;
    trailer=new Node;
    header->next=trailer;
    trailer->prev=header;
    trailer->next=nullptr;
    header->prev=nullptr;
    n=0;
}

template <typename T>
int List<T>::size() const{
    return n;
}

template <typename T>
bool List<T>::empty() const{
    return n==0;
}

template <typename T>
typename List<T>::Iterators List<T>::begin() const{
    return Iterators(header->next);
}

template <typename T>
typename List<T>::Iterators List<T>::end() const{
    return Iterators(trailer);
}

template <typename T>
void List<T>::insert(const List::Iterators& p, const T& ele){
    Node* w=p.v;
    Node* u=w->prev;
    Node* v=new Node;
    v->elemento=ele;
    v->next=w;
    w->prev=v;
    v->prev=u;
    u->next=v;
    n++;
}

template <typename T>
void List<T>::insertionFront(const T& ele){
    insert(begin(),ele);
}

template <typename T>
void List<T>::insertionBack(const T& ele){
    insert(end(),ele);
}

template <typename T>
void List<T>::remove(const Iterators& p){
    Node* v=p.v;
    Node* w=v->next;
    Node* u=v->prev;
    u->next=w;
    w->prev=u;
    delete v;
    n--;
}

template <typename T>
void List<T>::removeFront(){
    remove(begin());
}

template <typename T>
void List<T>::removeBack(){
    remove(--end());
}

template <typename T>
void List<T>::insertOrder(const T& ele){
    Node* w=header->next;
    Node* v=new Node;
    v->elemento=ele;
    while(w!=trailer){
        if(ele<w->elemento) break;
        w=w->next;
    }
    v->next=w;
    v->prev=w->prev;
    w->prev->next=v;
    w->prev=v;
}











#endif