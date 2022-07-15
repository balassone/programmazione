//Stack.cpp
//implementation of Stack class functions

//constructor
template<typename E>
Stack<E>::Stack() : S(), n(0) {}

//size
template<typename E>
int Stack<E>::size() const {
    return n;
}

template<typename E>
bool Stack<E>::empty() const {
    return n==0;
}

template<typename E>
const E& Stack<E>::top() {
    return S.front();
}

template<typename E>
void Stack<E>::push(const E& e){
    S.addFront(e);
    ++n;
}

template<typename E>
void Stack<E>::pop() {
    --n;
    S.removeFront();
}


