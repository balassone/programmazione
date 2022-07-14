template <typename T> friend class DLinkedList;

template <typename T>
class DNode{
    private:
        T elem;
        DNode<T> *next;
        DNode<T> *prev;
        friend class DLinkedList<T>;
};