#include"RilevList.h"
#include <iostream>
#include<exception>

using std::invalid_argument;

RilevList::RilevList() : head{nullptr}{}

RilevList::~RilevList(){
    while(!empty()){
        remove();
    }
}

bool RilevList::empty() const{
    return head==nullptr;
}

const Rilevamento& RilevList::front() const{
    return head->elem;
}


void RilevList::remove(){
    if(!empty()){
    NodoRil* old=head;

    head=old->next;

    delete old;
    } else {
           throw invalid_argument("La lista è vuota");
    }
}

int RilevList::size(){
    int size=0;
    if(!empty()){
    NodoRil* v= head;
    while(v!=nullptr){
        size++;
        v=v->next;
    }
    return size;
    } else {
           return size;
}
}

Rilevamento& RilevList::operator[](int i){
    NodoRil* v= head;
    if(i<size()){
        for(int j=0; j<i; j++){
            v=v->next;
        } 
        return v->elem;
    } else {
        throw invalid_argument("L'indice è fuori lista");

    }
    
}



void RilevList::insertBack(const Rilevamento& plus){
    NodoRil* v= head;
    NodoRil* u= new NodoRil;
    for(int i=0; i<size(); i++ ){
        v=v->next;
    }
    u->elem=plus;
    v->next=u;
    u->next=nullptr;

}




 RilevList& RilevList::operator=(const RilevList& l){
    RilevList* newLista= new RilevList;
    NodoRil* v= l.head;
    while(v!=nullptr){
        newLista->insertBack(v->elem);
        v=v->next;
    }
 }


 