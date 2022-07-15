//Dnode.h
template <typename T> class DLinkedList;	//forward declaration
class Studente;

template <typename T> 				// list element type
class DNode { 					// doubly linked list node
private:
	T elem; 				// node element value
	DNode *prev; 				// previous node in list
	DNode *next;				// next node in list
	friend class DLinkedList<T>; 		// allow DLinkedList access
	friend class Studente;
};


