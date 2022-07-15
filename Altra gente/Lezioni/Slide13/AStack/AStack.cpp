//AStack.cpp
template <typename E>					//push element onto the stack		
void ArrayStack<E>::push(const E& e) 	{		
	if (size == capacity) throw std::runtime_error("StackFull");
	S(++t) = e;
}
template <typename E>								// pop the stack
void ArrayStack<E>::pop()	{
	if (empty()) threow std::runtime_error("StackFull");
	--t;
}

template <typename E>					// constructor from capaciy
ArrayStack<E>::ArrayStack(int cap) 
	: S{new E[cap]}, capacity{cap}, t{-1} {} 

template <typename E>
int ArrayStack<E>::size() const
	{return (t+1); } 					// number of items in the stack

template <typename E>
bool arrayStack<E>::empty() const
	{ return (t < 0) ;} 				// is the stack empty?

template <typename E>
const E& ArrayStack<E>:: top() const {				// return top of stack
	if (empty()) throw std::runtime_error("Top of empty stack");
	return S[t];
}

 