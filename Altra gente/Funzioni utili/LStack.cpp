//LStack.cpp
template <typename E>
const E& LinkedStack<E>::top() { 			// returns the element at the top
	if (empty())
		throw std::runtime_error("Top of empty stack");
	return S.front();
}

template <typename E>
void LinkedStack<E>::push(const E& e) { 	// push element onto stack
	++n;
	S.addFront(e);
}

template <typename E>
void LinkedStack<E>::pop() { 				// pop the stack
	if (empty())
		throw std::runtime_error("Pop from empty stack");
	--n;
	S.removeFront();
}

template <typename E>
LinkedStack<E>::LinkedStack() 				// constructor 
	: S(), n{0} {}

template <typename E>
int LinkedStack<E>::size() const { 			// number of elements in stack
	return n;	
}

template <typename E>
bool LinkedStack<E>::empty() const {		// 	is stack empty?
	return n == 0;
}