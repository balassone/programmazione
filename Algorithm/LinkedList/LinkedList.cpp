#include <stdexcept>
#include <iostream>
#include <sstream>
template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList() : head{nullptr} {}

template <typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const {return head==nullptr;}

template <typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::front() const {return head->elem;}

template <typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList(){while(!empty()) removeFront();}

template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::addFront(const NODETYPE& e){
	Node <NODETYPE>* v = new Node<NODETYPE>;
	v->elem=e;
	v->next=head;
	head=v;
	return *this;
}

template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::removeFront(){
	if(head!=nullptr){
		Node<NODETYPE>* old = head;
		head = old->next;
		delete old;
	}
	return *this;
}

template <typename NODETYPE>
int LinkedList<NODETYPE>::size() const{
	if(!empty()){
		Node<NODETYPE>* curr = head;
		int count{0};
		while(curr!=nullptr){
			count++;
			curr=curr->next;
		}
		return count;
	}
	else return 0;
}

template <typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::operator[](const int& i){
	if(!empty()){
		Node <NODETYPE>* curr = head;
		for(int j{0}; j<i; ++j){
			curr=curr->next;
		}
		return curr->elem;
	}
}

template <typename NODETYPE>
int LinkedList<NODETYPE>::search(const NODETYPE& e) const{
	if(!empty()){
		int pos{0};
		Node<NODETYPE>* curr = head;
		while(curr!=nullptr){
			if(curr->elem==e){
				return pos;
			}
			curr=curr->next;
			pos++;
		}
		throw std::invalid_argument("Elemento Non Trovato!");
	}
}
template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::deleteNode(const NODETYPE& e){
	
	if(!empty()){
		
		Node<NODETYPE>* curr{head};
		Node<NODETYPE>* prec{nullptr};
		
		while(curr!=nullptr && e!=curr->elem){
			prec=curr;
			curr=curr->next;
		}
		if(prec==nullptr){
			head=curr->next;
			delete curr;
		}
		else if(curr!=nullptr){
			prec->next=curr->next;
			delete curr;
		}
		else{
			std::cout << "Non trovato\n";
		}
	}
	else{
		std::cout << "Lista vuota\n";
	}
	return *this;
}	
template <typename NODETYPE>
std::string LinkedList<NODETYPE>::toString() const{
	std::ostringstream out;
	Node<NODETYPE>* curr{head};
	while(curr!=nullptr){
		out << curr->elem;
		if(curr->next!=nullptr){
			out << "-->";
		}
		curr=curr->next;
	}
	return out.str();
}

template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::reverse(){
	Node <NODETYPE>* prec{nullptr};
	Node<NODETYPE>* curr{head};
	Node<NODETYPE>* succ{head->next};
	if(!empty()){
		while(curr!=nullptr){
			curr->next=prec;
			prec=curr;
			curr=succ;
			if(succ!=nullptr){
				succ=succ->next;
			}
		}
		head=prec;
		
	}
	return *this;
}

template <typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::operator=(const LinkedList<NODETYPE>& l){
	if(this!=&l){
		while(!empty()){
			removeFront();
		}
		Node<NODETYPE>* curr{l.head};
		while(curr!=nullptr){
			addFront(curr->elem);
			curr=curr->next;
		}
	}
	return *this;
}

template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList(const LinkedList<NODETYPE>& l){
	Node<NODETYPE>* curr{l.head};
	while(curr!=nullptr){
		addFront(curr->elem);
		curr=curr->next;
	}
	
}
