//AStack.h
#ifndef ASTACK_H
#define ASTACK_H
#include <iostream>
#include <stdexept>
template <typename E>
class ArrayStack {
	static const int DEF_CAPACITY{10};		//default stack capacity
public:
	ArrayStack(int cap = DEF_CAPACITY);		// constructor from capacity
	int size() const; 						// number of items in the stack
	bool empty() const; 					// is the stack empty?
	const E& top() const;					// get the top element
	void push(const E& e);					// push element onto the stack
	void pop();								// pop the stack
	// ... housekeeping functions omitted
private:									// member data
	E* S;									// array of stack elements
	int capacity; 							// stack capacity
	int t;									// index of the top of the stack
};

#include "AStack.cpp"