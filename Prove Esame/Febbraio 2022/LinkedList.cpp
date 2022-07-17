#include <sstream>
#include <iostream>
template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList() : head{nullptr} {}
template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList(const LinkedList<NODETYPE>& other) {
    Node<NODETYPE>* p = other.head;
    while (p != nullptr) {
        addBack(p->elem);
        p = p->next;
    }
}

template <typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList(){
    while(head!=nullptr){
        Node<NODETYPE>* temp=head;
        head=head->next;
        delete[] temp;
    }
}

template <typename NODETYPE>
//assignment operator
LinkedList<NODETYPE>& LinkedList<NODETYPE>::operator=(const LinkedList<NODETYPE>& other) {
    if (this != &other) {
        clear();
        Node<NODETYPE>* p = other.head;
        while (p != nullptr) {
            addBack(p->elem);
            p = p->next;
        }
    }
    return *this;
}

template <typename NODETYPE>
bool LinkedList<NODETYPE>::isEmpty() const{
    return head==nullptr;
}

template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::addFront(const NODETYPE& e){
    Node<NODETYPE>* temp = new Node<NODETYPE>;
    temp->elem=e;
    temp->next=head;
    head=temp;
    return *this;
}

template <typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::getFront() const{
    if(!isEmpty()){
        return head->elem;
    }
    else{
        throw std::runtime_error("List is empty");
    }
}

template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::removeFront(){
    if(!isEmpty()){
        Node<NODETYPE>* temp=head;
        head=head->next;
        delete[] temp;
    }
    else{
        throw std::runtime_error("List is empty");
    }
    return *this;
}

template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::reverse(){
    if(!isEmpty()){
        Node<NODETYPE>* curr=head;
        Node<NODETYPE>* prev=nullptr;
        Node<NODETYPE>* succ=curr->next;
        while(succ!=nullptr){
            curr->next=prev;
            prev=curr;
            curr=succ;
            succ=succ->next;
        }
        curr->next=prev;
        head=curr;
    }
    else{
        throw std::runtime_error("List is empty");
    }
    return *this;
}

template <typename NODETYPE>
std::string LinkedList<NODETYPE>::toString() const{
    std::ostringstream out;
    Node<NODETYPE>* curr=head;
    while(curr!=nullptr){
        out << curr->elem;
        if(curr->next!=nullptr){
            out << "-->";
        }
        curr=curr->next;
    }
    return out.str();
}
template <typename NODETYPE>
NODETYPE LinkedList<NODETYPE>::operator[](int i){
    if(i<0){
        throw std::runtime_error("Index must be positive");
    }
    if(i>=getLength()){
         throw std::runtime_error("Index out of bounds");
    }
    Node<NODETYPE>* curr=head;
    for(int j=0;j<i;j++){
        curr=curr->next;
    }
    return curr->elem;
}

template <typename NODETYPE>
int LinkedList<NODETYPE>::getLength() const{
    if(isEmpty()){
        return 0;
    }
    else{
        Node<NODETYPE>* curr=head;
        int count{0};
        while(curr!=nullptr){
            count++;
            curr=curr->next;
        }
        return count;
    }
}

template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::clear(){
    if(!isEmpty()){
        Node<NODETYPE>* garbage{head};
        while(head!=nullptr){
            head=head->next;
            delete[] garbage;
        }
    }
    return *this;
}


template <typename NODETYPE>
//addBack
LinkedList<NODETYPE>& LinkedList<NODETYPE>::addBack(const NODETYPE& e){
    if(isEmpty()){
        head=new Node<NODETYPE>;
        head->elem=e;
        head->next=nullptr;
    }
    else{
        Node<NODETYPE>* curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=new Node<NODETYPE>;
        curr->next->elem=e;
        curr->next->next=nullptr;
    }
    return *this;
}
template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::removeBack(){
    if(!isEmpty()){
        Node<NODETYPE>* curr=head;
        while(curr->next->next!=nullptr){
            curr=curr->next;
        }
        delete[] curr->next;
        curr->next=nullptr;
    }
    else{
        throw std::runtime_error("List is empty");
    }
    return *this;
}
template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::remove(const int& i){
    if(i<0 || i>=getLength()){
        throw std::runtime_error("Index out of bounds");
    }
    else{
        Node<NODETYPE>* curr=head;
        for(int j{0}; j<i-1;++j){
            curr=curr->next;
        }
        Node<NODETYPE>* temp=curr->next;
        curr->next=curr->next->next;
        delete[] temp;
    }
    return *this;
}
template<typename NODETYPE>
//addorder
LinkedList<NODETYPE>& LinkedList<NODETYPE>::addOrder(const NODETYPE& e){
    if(isEmpty()){
        head=new Node<NODETYPE>;
        head->elem=e;
        head->next=nullptr;
    }
    else{
        Node<NODETYPE>* curr=head;
        Node<NODETYPE>* prev=nullptr;
        while(curr!=nullptr && *(curr->elem)<(*e)){
            prev=curr;
            curr=curr->next;
        }
        if(curr==nullptr){
            prev->next=new Node<NODETYPE>;
            prev->next->elem=e;
            prev->next->next=nullptr;
        }
        else if(*(curr->elem)==(*e)){
            throw std::runtime_error("Element already exists");
        }
        else{
            prev->next=new Node<NODETYPE>;
            prev->next->elem=e;
            prev->next->next=curr;
        }
    }
    return *this;
}

template <typename NODETYPE>
int LinkedList<NODETYPE>::search(const NODETYPE& a) const{
    if(isEmpty()){
        return -1;
    }
    else{
        Node<NODETYPE>* curr=head;
        int count{0};
        while(curr!=nullptr){
            if(curr->elem==a){
                return count;
            }
            curr=curr->next;
            count++;
        }
        return -1;
    }
}

template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::deleteElem(const NODETYPE& e){
    if(!isEmpty()){
        if(head->elem==e){
            removeFront();
        } else{
            Node<NODETYPE>* curr=head;
            Node<NODETYPE>* prev=nullptr;
            while(curr!=nullptr && curr->elem!=e){
                prev=curr;
                curr=curr->next;
            }
            if(curr==nullptr){
                throw std::runtime_error("Element not found");
            }
            else{
                prev->next=curr->next;
                delete[] curr;
            }
        }
    }
    return *this;
}
template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::addPosition(const int& p, const NODETYPE& e){
    if(p<0 || p>getLength()){
        throw std::runtime_error("Index out of bounds");
    }
    else{
        Node<NODETYPE>* curr=head;
        for(int j{0};j<p-1;++j){
            curr=curr->next;
        }
        Node<NODETYPE>* temp=curr->next;
        curr->next=new Node<NODETYPE>;
        curr->next->elem=e;
        curr->next->next=temp;
    }
    return *this;
}