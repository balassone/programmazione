#include "StringLinkedList.h"
#include <string>
#include <exception>
#include <iostream>
using std::runtime_error;
using std::string;

StringLinkedList::StringLinkedList()
    : head{nullptr} {} //Inizializzo la testa della coda che è un puntatore con un puntatore nullo

StringLinkedList::~StringLinkedList(){
    while(!empty()){ 
        removeFront(); //Elimino i nodi fino a quando la lista non è vuota
    }
}

bool StringLinkedList::empty() const{
    if(head==nullptr){
        return true;
    }
    return false;
}

const string& StringLinkedList::front() const{
    if(!empty()){
        return head->elemento;
    }
    else
        throw runtime_error("La lista è vuota");
}

void StringLinkedList::addFront(const string& ele){
    StringNode* v; //definisco un puntatore alla classe StringNode
    v=new StringNode; //alloco spazio in memoria per contenere un nuovo nodo
    v->elemento=ele; //faccio puntare v al nuovo elemento
    v->next=head; //faccio puntare v alla testa della lista
    head=v; //il puntatore v è la nuova testa della lista
}

void StringLinkedList::removeFront(){
    if(!empty()){
        StringNode* v=head; //conservo il puntatore alla testa della lista
        head=head->next; //il puntatore al prossimo nodo sarà la nuova testa
        delete v; //dealloco la memoria che avevo usato per conservare il puntatore alla testa della lista
    }
    else
        throw runtime_error("La lista è vuota");
}

