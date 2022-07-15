//LinkedList.cpp
//Implementation of the generic Linked list
//this file should be included in the client source file in order to avoid linking errors

template <typename NODETYPE> 
LinkedList<NODETYPE>::LinkedList()
    : head(nullptr){};                                              //constructor

template<typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const {                          //is list empty?
    return head==nullptr;
}

template<typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>:: front() const {              //return front element
    return head->elem;
}

template<typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList() {                                //destructor
    while (!empty()) {removeFront();}
}                                

template<typename NODETYPE>
void LinkedList<NODETYPE>:: addFront(const NODETYPE& e) {           //add to the front of list
    Node<NODETYPE>* v = new Node<NODETYPE>;
    v->elem = e;                                                    //store data
    v->next = head;                                                 //head now follows v
    head = v;                                                       //v is now the head
}

template<typename NODETYPE>
void LinkedList<NODETYPE>:: removeFront(){                          //remove front item
    if (head==nullptr){
        throw std::invalid_argument{"List is empty"};
    }
    
    Node<NODETYPE>* old = head;                                     //save the current head
    head=old->next;                                                 //skip over old head
    delete old;                                                     //delete old head
}
