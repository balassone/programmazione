//CLinkedList.cpp
#include <iostream>
#include <sstream>
template <typename T>
CircleList<T>::CircleList() 				// constructor
	: cursor{nullptr} { }

template <typename T>
CircleList<T>:: ~CircleList()				// destructor
	{ while (!empty()) remove();}

template <typename T>
bool CircleList<T>::empty() const 			// is list empty?
	{ return cursor == nullptr; }

template <typename T>
const T& CircleList<T>::back() const 		// element at cursor
	{ return cursor->elem; }

template <typename T>
const T& CircleList<T>::front() const 		// element following cursor
	{ return cursor->next->elem; }

template <typename T>
void CircleList<T>::advance() 				//advance cursor
	{ cursor = cursor->next; }


//add in a Circle Linked List

template <typename T>
void CircleList<T>::add(const T& e) {		//add after cursor
	CNode<T>* v = new CNode<T>;
	v->elem = e;
	if (cursor == nullptr) {				//list is empty?
		v->next = v;						// v points to itself
		cursor = v;							// cursor points to v
	}
	else{									//link is nonempty?
	v->next = cursor->next;					//link in v after cursor
	cursor->next = v;
	}
}

//remove in a Circular Linked List

template <typename T>
void CircleList<T>::remove() {				// remove node after cursor
	CNode<T>* old = cursor->next;			// the node being removed
	if (old == cursor)						// removing the only node?
		cursor = nullptr;					// list is now empty
	else
		cursor->next = old->next;			// link ot the old node
	delete old;								// delete the old node
}

//visit the list

template <typename T>
std::string CircleList<T>::toString() {
	std::ostringstream out;
	CNode<T>* u = cursor;
	out << "Cursor --> ";
	while (u->next != cursor) {
	out << u->elem << " --> ";
	u = u->next;	
	}
	out << "Cursor";
	return out.str();
}

