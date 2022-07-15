#include "ListaP.h"
#include<exception>
#include<sstream>
#include<iostream>

using std::ostringstream;
using std::string;
using std::invalid_argument;

ListaP::ListaP(){
    head=nullptr;
}

ListaP::~ListaP(){
    while(!empty()) remove();
}
bool ListaP::empty() const{
    return head == nullptr;
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

int ListaP::summarizeWarehouse(){
    int prezzo{0};
    NodoP* v=head;
    while(v!=nullptr){
        prezzo += v->elem->getPrezzo();
        v=v->next;
    }
    return prezzo;
}

void ListaP::insertTable(const Piano* e){
    NodoP* u= new NodoP;
    if(dynamic_cast<const Triangolo*>(e) != nullptr){
        u->elem = new Triangolo(*(dynamic_cast<const Triangolo*>(e)));
    }
    else if(dynamic_cast<const Cerchio*>(e) != nullptr){
        u->elem = new Cerchio(*(dynamic_cast<const Cerchio*>(e)));
    }
    else if(dynamic_cast<const Rettangolo*>(e) != nullptr){
        u->elem = new Rettangolo(*(dynamic_cast<const Rettangolo*>(e)));
    }
    else{
        throw std::runtime_error("tipo di dato non valido");
    }
    if(empty()){
        head = u;
        head->next = nullptr;
    }
    else{
        NodoP * v = head;
        NodoP * p = nullptr;
        while (v != nullptr){
            if (u->elem->getArea() < v->elem->getArea()) break;
            p = v;
            v = v->next;       
        }
        if(p != nullptr){
            p->next = u;
            u->next = v;
        }
        else{
            u->next = head;
            head = u;
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

Piano& ListaP::operator[](int i){
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

string ListaP::toString(){
    NodoP*v = head; 
    ostringstream output;
    output << "STAMPA INVENTARIO \n";
    while (v != nullptr)
    {
        output << v->elem->toString() <<"\n";
        v = v->next;
    }
    return output.str();
    

}
/*
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
    out<<" ................ \n\n\n" <<v->elem->stampaPiano();
    v=v->next;

    while(v!=nullptr){
        out<<v->elem->stampaPiano();
        v=v->next;
    }
    return out.str();
    
}
*/
//povera funzione empty te la sei dimenticata :(











