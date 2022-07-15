#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <exception>
#include <string>
#include <sstream>
using std::runtime_error;
using std::endl;
using std::cout;

template <typename NODETYPE>
class LinkedList{

public:
    LinkedList();
    ~LinkedList();
    /*
    LinkedList(const LinkedList<NODETYPE> &);
    LinkedList<NODETYPE>& operator=(const LinkedList<NODETYPE>&);
    */
    bool empty() const;
    const NODETYPE& front() const;
    void addFront(const NODETYPE&);
    void removeFront();
    int size() const;
    NODETYPE& operator[](int);
    int search(NODETYPE&) const;
    void removeElement(NODETYPE&);
    void addBack(const NODETYPE&);
    void reverse();

    std::string toString();

private:
    Node<NODETYPE>* head;
};

template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList()
    : head{nullptr} {}

template <typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList(){
    while(!empty()){
        removeFront();
    }
}

/*

template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList(const LinkedList<NODETYPE>& L){
	if(L.empty()==true){
		head=nullptr;
	}
	else{
		head=new Node<NODETYPE>;
		head->elemento=L.head->elemento;
		Node<NODETYPE>* ptr1=head;
		Node<NODETYPE>* ptr2=L.head;
		while(ptr2->next!=nullptr){
			ptr1->next=new Node<NODETYPE>;
			ptr1->next->elemento=ptr2->next->elemento;
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
	}
}


template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::operator=(const LinkedList<NODETYPE>& L){
	if(this==&L){
		return *this;
	}
	else{
		while(!((*this).empty())){
			removeFront();
		}
		if(L.empty()==true){
			head=nullptr;
		}
		else{
			head=new Node<NODETYPE>;
			head->elemento=L.head->elemento;
			Node<NODETYPE>* ptr1=head;
			Node<NODETYPE>* ptr2=L.head;
			while(ptr2->next!=nullptr){
				ptr1->next=new Node<NODETYPE>;
				ptr1->next->elemento=ptr2->next->elemento;
				ptr1=ptr1->next;
				ptr2=ptr2->next;
			}
				
		}
		
		return *this;
		
	}
	
}


*/


template <typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const{
    if(head==nullptr){
        return true;
    }
    return false;
}

template <typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::front() const{
    if(!empty()){
        return head->elemento;
    }
    else
        throw runtime_error("La lista è vuota");
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE& ele){
    Node<NODETYPE>* v=new Node<NODETYPE>;
    v->elemento=ele;
    v->next=head;
    head=v;
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::removeFront(){
    if(!empty()){
        Node<NODETYPE>* old=head;
        head=head->next;
        delete old;
    }
    else 
        throw runtime_error("La lista è vuota");
}

template <typename NODETYPE>
int LinkedList<NODETYPE>::size() const{
    int num=0;
    Node<NODETYPE>* v=head;
    while(v!=nullptr){
        num++;
        v=v->next;
    }
    return num;
}

template <typename NODETYPE>
NODETYPE& LinkedList<NODETYPE>::operator[](int i){
    int ind=0;
    Node<NODETYPE>* v=head;
    if(i<0 || i>(this->size()-1)) {
        throw runtime_error("L'indice eccede il valore massimo");
    }
    while(i>ind){
        ind++;
        v=v->next;
    }
    return v->elemento;
}

template <typename NODETYPE>
int LinkedList<NODETYPE>::search(NODETYPE& ele) const{
    for(int i=0;i<size();i++){
        if(this->operator[](i)==ele) return i;
    }
    return -1;
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::removeElement(NODETYPE& ele){
    Node<NODETYPE>* v=head;
    bool flag=false;
    if(v->elemento==ele){
        removeFront();
    }
    else{
        while(flag==false){
            if((v->next)!=nullptr){
                Node<NODETYPE>* s=v->next;
                if(s->elemento==ele){
                    v->next=s->next;
                    delete s;
                    flag=true;
                }
                else{
                    v=v->next;
                }
            }
            else{
            cout<<"L'elemento inserito non è nella lista"<<endl;
            flag=true;
            }
        }
    }
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::addBack(const NODETYPE& ele){
    Node<NODETYPE>* v=head;
    if(v==nullptr){
        addFront(ele);
    }
    else{
        while(v->next!=nullptr){
            v=v->next;
        }
        Node<NODETYPE>* s=new Node<NODETYPE>;
        s->elemento=ele;
        v->next=s;
        s->next=nullptr;
    }
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::reverse() {
    LinkedList<NODETYPE> T;
    while(!(this->empty())){
        NODETYPE x=(this->front());
        (this->removeFront());
        T.addFront(x);
    }
    while(!T.empty()){
        NODETYPE x=T.front();
        T.removeFront();
        (this->addBack(x));
    }
}

template <typename NODETYPE>
std::string LinkedList<NODETYPE>::toString(){
    std::ostringstream out;
    Node<NODETYPE>* v=head;
    while(v!=nullptr){
        out<<v->elemento<<endl;
        v=v->next;
    }
    return out.str();
}

#endif
