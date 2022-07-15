//LinkedQueue.cpp



template<typename E>
LinkedQueue<E>::LinkedQueue() : C(), n{0} {}

template<typename E>
int LinkedQueue<E>::size() const {
    return n;
}

template<typename E>
bool LinkedQueue<E>:: empty() const{
    return n==0;
}

template<typename E>
const E& LinkedQueue<E>::front(){
    if (empty()){
        throw std::runtime_error("front of empty queue");
    }
    return C.front() ;
}

template<typename E>
void LinkedQueue<E>::enqueue(const E& e){
    C.add(e);                                   //insert element after cursor
    C.advance();                                //advance cursor
    n++;
}

template<typename E>
void LinkedQueue<E>::dequeue(){
    if (empty()){
        throw std::invalid_argument("Trying to dequeue an element from an empty queue");
    }
    C.remove();
    n--;
}

