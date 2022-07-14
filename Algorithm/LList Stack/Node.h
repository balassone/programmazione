template <typename NODETYPE> class LinkedList;

template <typename NODETYPE> class Node{
private:
	Node<NODETYPE>* next;
	NODETYPE elem;
	friend class LinkedList<NODETYPE>;
};
