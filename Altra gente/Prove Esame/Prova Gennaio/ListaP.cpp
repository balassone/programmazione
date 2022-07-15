#include "ListaP.h"
#include<exception>
#include<sstream>
#include<iostream>

using std::ostringstream;

using std::invalid_argument;

ListaP::ListaP(){
    head=nullptr;
}

ListaP::~ListaP(){
    while(!empty()) remove();
}

void ListaP::remove(){
    if(!empty()){
        NodoP* old=head;
        head=old->next;
        delete old;
    } else {
        throw invalid_argument("Lista già vuota");
    }
}

void ListaP::add(const Pacco* e){
    NodoP* u= new NodoP;
   
    if(dynamic_cast<const PaccoExtra*>(e) != nullptr){
        u->elem = new PaccoExtra(*dynamic_cast<const PaccoExtra*>(e));
    }
    else u->elem = new Pacco (*e);
    if(empty()){
        head = u;
        head->next = nullptr;
        std::cout << "print1 \n";
    }
    else{
        NodoP * v = head;
        NodoP * p = nullptr;
        while (v != nullptr){
            if (u->elem < v->elem) break;
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



int ListaP::size(){
    int s=0;
    NodoP* v=head;
    while(v!=nullptr){
        s++;
        v=v->next;
    }
    return s;
}

Pacco& ListaP::operator[](int i){
    if(!empty()){
    NodoP* v= head;
    if (i<size()){
        for(int j=0; j<i; j++){
            v=v->next;
        }
        return *(v->elem);
    } else {
        throw invalid_argument("coefficiente non valido");
        } 

    } else {
        throw invalid_argument("Lista vuota");

    }
}

int ListaP::weeklyEarnings(){
    int somma=0;
    NodoP* v= head;
    while (v!=nullptr){
        somma+= v->elem->compensobase();
        v=v->next;
    }
    return somma;
}

string ListaP::toString(){
    NodoP* v=head;
    ostringstream out;
    out<<" ................ \n\n\n" <<v->elem->stampaPacco();
    v=v->next;

    while(v!=nullptr){
        out<<v->elem->stampaPacco();
        v=v->next;
    }
    return out.str();
    
}
//povera funzione empty te la sei dimenticata :(
bool ListaP::empty() const{
    return head == nullptr;
}










