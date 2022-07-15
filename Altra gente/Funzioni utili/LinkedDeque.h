//LinkedDeque.h
#include "DLinkedList.h"
template <typename T>
class LinkedDeque { // deque a doubly linked list
public:
	LinkedDeque();
	int size() const; 						// size of the deque
	bool empty() const; 					// is the deque empty?
	const T& front();						// the first element
	const T& back(); 						// the last element
	void insertFront(const Elem& e);		// insert new first element
	void insertBAck(const Elem& e);			// insert new last element
	void removeFront();						// remove last element
	void removeBack();						// remove last element
private:
	DLinkedList<T>D;
	int n;
};

#include "LinkedDeque.cpp"