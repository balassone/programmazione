#include <string>
#include <sstream>
#include <stdexcept>
LinkedList::LinkedList() : head{nullptr} {}
LinkedList::LinkedList(const LinkedList& l){
    
    head = new Node;
    head->elem=l.head->elem;
    Node* curr=l.head->next;
    Node* act=head;
    while(curr!=nullptr){
        act->next=new Node;
        act->next->elem=curr->elem;
        act=act->next;
        curr=curr->next;
    }
    act->next=nullptr;
}
LinkedList::~LinkedList(){
    while(head!=nullptr){
            removeFront();
        }
}
void LinkedList::clear(){
    while(head!=nullptr){
            removeFront();
        }
}
LinkedList& LinkedList::operator=(const LinkedList& l){
    if(!empty()){
        while(head!=nullptr){
            removeFront();
        }
    }
    head = new Node;
    head->elem=l.head->elem;
    Node* curr=l.head->next;
    Node* act=head;
    while(curr!=nullptr){
        act->next=new Node;
        act->next->elem=curr->elem;
        act=act->next;
        curr=curr->next;
    }
    act->next=nullptr;
    return *this;
}
bool LinkedList::empty() const{
    return head==nullptr;
}
LinkedList& LinkedList::addBack(const int& e){
    if(!empty()){
        Node* curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=new Node;
        curr->next->elem=e;
        curr->next->next=nullptr;
    } else {
        head=new Node;
        head->elem=e;
        head->next=nullptr;
    }
    return *this;
}
std::string LinkedList::toString(){
    std::ostringstream out;
    Node* curr=head;
    while(curr!=nullptr){
        out << curr->elem;
        if(curr->next!=nullptr){
            out << " --> ";
        }
        curr=curr->next;
    }
    return out.str();
}
const int& LinkedList::operator[](int i){
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
LinkedList& LinkedList::removeFront(){
    if(!empty()){
        Node* temp=head;
        head=head->next;
        delete[] temp;
    }
    return *this;
}

int LinkedList::size() const{
    Node* curr=head;
    int i{0};
    while(curr!=nullptr){
        i++;
        curr=curr->next;
    }
    return i;
}