//DLinkedList.h
#include "DNode.h"
#include <iostream>
template <typename T>
bool operator == (const DLinkedList<T>& lhs, const DLinkedList<T>&rhs);
template <typename T>
class DLinkedList {					// doubly linked list
friend bool operator ==  <> (const DLinkedList<T>& lhs, const DLinkedList<T>&rhs);
public:
	DLinkedList();					// constructor
	DLinkedList(const DLinkedList& dl); 	// copy constructor
	~DLinkedList();					// destructor
	DLinkedList& operator = (const DLinkedList & dl); // assignment operator
	T& operator [] (int i) const;
	int size() const;
	bool empty() const; 				// is list empty?
	const T& front() const;				// get front element
	const T& back() const;				// get back element
	void addFront(const T& e); 			// add to front of the list
	void addBack(const T& e); 			// add to back of the list
	void removeFront();				//remove from front
	void removeBack();				// remove from back
	void reversal();				//reversal
	std::string toString();
private:						// local type definitions
	DNode<T>* header;				// list sentinels
	DNode<T>* trailer;
protected:						// local utilites
	void add(DNode<T>* v, const T& e); 		// insert new node before v
	void remove(DNode<T>* v); 			// remove node v				
};

#include "DLinkedList.cpp"
