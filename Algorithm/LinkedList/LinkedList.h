#include "Node.h"
#include <iostream>
template <typename NODETYPE>
class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		bool empty() const;
		const NODETYPE& front() const;
		void addFront(const NODETYPE& e);
		void removeFront();
	private:
		Node<NODETYPE>* head;
};

#include "LinkedList.cpp"