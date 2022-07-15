
#include"LinkedList.h"
#include "Node.h"



LinkedList::LinkedList(){
    head=nullptr;
}


LinkedList::~LinkedList(){
    while(!empty()){
        removeFront();
    }
}


bool LinkedList::empty() const{
    if(head==nullptr){
        return true;
    }
    return false;
}

int LinkedList::size(){
    int s=0;
    Node* v= head;
    while(v!=nullptr){
        s++;
        v=v->next;

    }
    return s;
}

Task& LinkedList::operator[](int i){
    if(i<size()){
        int j=0;
        Node* v=head;
        while(j<i){
            v=v->next;
            j++;
        }
    return v->elemento;
} else {
    throw runtime_error("Indice non contemplato");
}
}

void LinkedList::addFront(const Task &e) { 			//add to front of list
	Node* v = new Node ;
	v-> elemento = e;
	v-> next = head;
	head = v;
}

void LinkedList::addOrder(const Task& e){
    Node * u = new Node;
    u->elemento = e;
    if(empty()){
        head = u;
        head->next = nullptr;
        std::cout << "print1 \n";
    }
    else{
        Node * v = head;
        Node * p = nullptr;
        while (v != nullptr){
            if (u->elemento < v->elemento) break;
            p = v;
            v = v->next;  
            std::cout << "printx \n";       
        }
        if(p != nullptr){
            p->next = u;
            u->next = v;
            std::cout << "print2 \n ";
        }
        else{
            u->next = head;
            head = u;
            std::cout << "print3 \n";
        }
    }
    
}

void LinkedList::print(){
    Node* v=head;
    while (v != nullptr)
    {
        std::cout<<v->elemento.getNomeT() << " data scadenza "<<v->elemento.getDataSca()<< "\n";
        v=v->next;
    }
    
}



void LinkedList::removeFront(){
    if(!empty()){
        Node* old=head;
        head=head->next;
        delete old;
    }
    else 
        throw runtime_error("La lista è vuota");
}

void LinkedList::addBack(const Task& e){
    Node* tsk = new Node;
    tsk->next = nullptr;
    tsk->elemento = e;
    if(!empty()){
        Node* i = head;
        while(i->next != nullptr){i = i->next;}
        i->next = tsk;
    }
    else{
        head = tsk;
        head->next = nullptr;
    }
}

LinkedList::LinkedList(const LinkedList& lhs){
    head = nullptr;
    if(lhs.head != nullptr){    
        Node* v = lhs.head;
        while (v != nullptr){
            addBack(v->elemento);
            v=v->next;
        }
    }
    else{
        head = nullptr;
    }

}

void LinkedList::add(const Task& e, Node* p){
	Node* n = new Node;
	n->elemento = e;
	n->next = p->next;
	p->next = n;
}

/*

nodo v = head
nodo u = l.head

*/
