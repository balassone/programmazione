template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList() : head{nullptr} {}

template <typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const {return head==nullptr;}

template <typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::front() const {return head->elem;}

template <typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList(){while(!empty()) removeFront();}

template <typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE& e){
	Node <NODETYPE>* v = new Node<NODETYPE>;
	v->elem=e;
	v->next=head;
	head=v;
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::removeFront(){
	if(head!=nullptr){
		Node<NODETYPE>* old = head;
		head = old->next;
		delete old;
	}
}
