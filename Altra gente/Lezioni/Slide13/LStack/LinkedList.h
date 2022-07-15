//LinkedList.h
//A generic LinkedList class template
#include "Node.h"
#include <iostream>

template<typename NODETYPE>
class LinkedList { 							// a singly linked list
	public:
		LinkedList();						//empty list constructor
		~LinkedList();						//destructor
		bool empty() const;					//is list empty?
		const NODETYPE& front() const;			//return front element
		void addFront(const NODETYPE& e); 		//add to front of list
		void removeFront();						// remove front item list
	private:	
		Node<NODETYPE>* head; 				 //head of the list 
};

#include "LinkedList.cpp"
