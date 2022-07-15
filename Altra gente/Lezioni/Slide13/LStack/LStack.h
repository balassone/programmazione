//LStack.h

#ifndef LSTACK_H
#define LSTACK_H
#include "LinkedList.h"
#include <stdexcept>
template <typename E>
class LinkedStack {			// stack as a linked list
public:
	LinkedStack();			// constructor
	int size() const;		// number of items in the stack
	bool empty() const;		// is the stack empty?
	const E& top();			// the top element
	void push(const E& e);	// push the element onto stack
	void pop();				// pop the stack
private:					// member data
	LinkedList<E> S;		// linked list of elements
	int n;					// number of elements
	
};

#endif 
#include "LStack.cpp"