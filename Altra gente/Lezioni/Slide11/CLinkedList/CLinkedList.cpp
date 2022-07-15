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
	CNode<T>* u = cursor->next;
	out << "First --> ";
	do{
		out << u->elem << " --> ";
		u = u->next;	
	}while(u != cursor->next);
	out << "Cursor";
	return out.str();
}

template <typename T>
void CircleList<T>::reverse() {
	CNode<T> *current, *prev, *next;
	CNode<T> *hold = cursor->next;
	current = cursor;
	prev = nullptr;
	if(cursor != nullptr){
		do{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}while(current != cursor);
		cursor->next = prev;
		cursor = hold;
	}

}

template <typename T>
int CircleList<T>::size(){
	int count = 0;
	CNode<T> *i = cursor;
	if(cursor != nullptr){
		do{
			count++;
			i= i->next;
		}while(i != cursor);
	}
	return count;
}

template <typename T>
const T& CircleList<T>::operator[](int i){
	if (i>=0 && i<size()){
		CNode<T> *ref = cursor;
		for(int j = 0; j<i; j++){ref = ref->next;}
		return ref->elem;
	}
	else{
		throw std::invalid_argument("the given number is not valid");
	}
}
template <typename T>
/*CircleList<T>::CircleList(const CircleList<T> &cl){
	CNode<T>* temp = nullptr;
	if(cl.cursor == nullptr){cursor= nullptr;}
	else{
		cursor = new CNode<T>;
		cursor->elem = cl.cursor->elem;
		temp = cl.cursor->next;
		
		while (temp != cl.cursor)
		{
			add(temp->elem);
			temp=temp->next;
		}
	}
}*/


CircleList<T>::CircleList(const CircleList& cl){

		cursor = new CNode<T>;
		cursor->elem = cl.cursor->elem;
		cursor->next = cursor;
		CNode<T>* y= cl.cursor->next;
		
		while(y!=cl.cursor){
			addBack(y->elem);
			y=y->next;
		}
		advance();
	

}


template<typename T>
void CircleList<T>::addBack(const T& e){
	if(cursor != nullptr){
		CNode<T>* v = new CNode<T>;
		CNode<T>* u = cursor->next;
		v->elem = e;
		while(u->next != cursor){u=u->next;}
		u->next = v;
		v->next = cursor;

		
	}
	else{
		cursor->elem = e;
		cursor->next = cursor;
	}

}
template<typename T>
CircleList<T>& CircleList<T>::operator=(const CircleList<T>& cl){
	if(!(&cl==this)){
		while (!empty()) remove();
		cursor = new CNode<T>;
		cursor->elem = cl.cursor->elem;
		cursor->next = cursor;
		CNode<T>* y= cl.cursor->next;
		
		while(y!=cl.cursor){
			addBack(y->elem);
			y=y->next;
		}
	}
	return *this;
}

template<typename T>
bool operator==(CircleList<T> &lhs, CircleList<T> & rhs) {
	if (lhs.size() != rhs.size()){
		return false;
	}
	CNode<T>* x = lhs.cursor;
	CNode<T>* y = rhs.cursor;
	do{
		if(x->elem != y->elem){
			return false;
		}
		x = x->next;
		y = y->next;
	}while(x != lhs.cursor || y != rhs.cursor);
	return true;
}
template<typename T>
bool CircleList<T>::find(const T&e){
    CNode<T>* v = cursor;
    if(empty())return false;
    else{
        do {
            if(v->elem == e){
                return true;
            }
            v=v->next;
        } while (v != cursor);
        return false;
    }
}