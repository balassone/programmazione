#include <sstream>
#include <string>
#include <stdexcept>
#include "LinkedList.h"
LinkedList::LinkedList() : head{nullptr} {}

LinkedList::~LinkedList(){
    while(!empty()){
        removeFront();
    }
}

LinkedList::LinkedList(const LinkedList& l){
    if(!l.empty()){
        head = new Node;
        head->elem=l.head->elem;
        Node* curr=l.head->next;
        Node* mine=head;
        while(curr!=nullptr){
            mine->next=new Node;
            mine->next->elem=curr->elem;
            mine=mine->next;
            curr=curr->next;
        }
        mine->next=nullptr;
    } else {
        head=nullptr;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& l){
    while(!empty()){
        removeFront();
    }
    if(!l.empty()){
        head = new Node;
        head->elem=l.head->elem;
        Node* curr=l.head->next;
        Node* mine=head;
        while(curr!=nullptr){
            mine->next=new Node;
            mine->next->elem=curr->elem;
            mine=mine->next;
            curr=curr->next;
        }
        mine->next=nullptr;
    } else {
        head=nullptr;
    }
    return *this;
}
int LinkedList::size() const {
    if(!empty()){
        int i=0;
        Node* curr=head;
        while(curr!=nullptr){
            curr=curr->next;
            i++;
        }
        return i;
    } else{
        return 0;
    }
}

bool LinkedList::empty() const {
    return head==nullptr;
}

LinkedList& LinkedList::removeFront(){
    if(!empty()){
        Node* temp=head;
        head=head->next;
        delete[] temp;
    }
    return *this;
}

LinkedList& LinkedList::addOrder(const Task& t){
    if(!empty()){
        Node* prev=nullptr;
        Node* curr=head;
        while(curr!=nullptr && curr->elem<t){
            prev=curr;
            curr=curr->next;
        }
        if(curr==nullptr){
            prev->next=new Node;
            prev->next->elem=t;
            prev->next->next=nullptr;
        } else {
            prev->next=new Node;
            prev->next->elem=t;
            prev->next->next=curr;
        }
    } else {
        head=new Node;
        head->elem=t;
        head->next=nullptr;
    }
    return *this;
}
std::string LinkedList::toString() const{
    std::ostringstream out;
    Node* curr=head;
    while(curr!=nullptr){
        out << curr->elem.toString() << "\n";
        curr=curr->next;
    }
    return out.str();
}
Task& LinkedList::operator[](int i) {
    if(i<0 || i>=size()){
        throw std::runtime_error("Out of range");
    } else{
        Node* curr=head;
        for(int j{0}; j<i; ++j){
            curr=curr->next;
        }
        return curr->elem;
    }
}