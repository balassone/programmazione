//LinkedQueue.cpp
template <typename E>
LinkedQueue<E>::LinkedQueue() 				// constructor
	: C(), n{0} {}

template <typename E>
LinkedQueue<E>::LinkedQueue(const LinkedQueue<E>& lq){
	n = lq.n;
	CircleList<E> C(lq.C);
}

template <typename E>
LinkedQueue<E>& LinkedQueue<E>::operator=(const LinkedQueue<E>& lq){
	if(!(this == &lq)){
		n = lq.n;
		C = lq.C;
	}
	return *this;
}

template <typename E>
int LinkedQueue<E>::size() const { 			// number of items in the queue
	return n;
}

template <typename E>
bool LinkedQueue<E>::empty() const { 		// is the queue empty?
	return n == 0;
}

template <typename E>
const E& LinkedQueue<E>::front() {			// get the front element
	if(empty())
		throw std::runtime_error("front of empty queue");
	return C.front();						// list front is queue front
}

template <typename E>
void LinkedQueue<E>::enqueue(const E& e) {	// enqueue element at rear
	C.add(e);								// insert after cursor
	C.advance();							// ... and advance
	n++;
}

template <typename E>
void LinkedQueue<E>::dequeue() {			// dequeue element at front
	if (empty())
		throw std::runtime_error("dequeue of empty queue");
	C.remove();								//remove from list front
	n--;
}

template <typename E>
std::string LinkedQueue<E>::toString() const{
	return C.toString();
}

template<typename E>
bool operator==(const LinkedQueue<E>&lhs, const LinkedQueue<E> & rhs){return (lhs.n == rhs.n && lhs.n == rhs.n);}


	