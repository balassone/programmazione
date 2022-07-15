//DList.h
#include"DNode.h"
#include"Iterator.h"
#ifndef DLIST
#define DLIST

template<typename T>
class DList{

    public:
        DList();                                 //empty constructor
        DList(const DList<T>&);                  //copy constructor
        DList& operator=(const DList&);          //operator = (assignment)
        ~DList();                                //destructor

        int size() const;                        //number of elements in list
        bool empty() const;                      //is list empty?
        Iterator<T> begin() const;                  //iterator to begin
        Iterator<T> end() const;                    //iterator to end

        void addFront(const T&);                 //add element in front
        void addBack(const T&);                  //add element as last 
        void removeFront();                      //remove from front
        void removeBack();                       //remove last element

        void add(const Iterator<T>&, const T&);  //add element before iterator specified
        void remove(const Iterator<T>&);         //remove element before iterator specified

        const T& operator[](int) const;                //operator [] to access to i-th element


    private:
        DNode<T>* header;
        DNode<T>* trailer;
        int n;
};

#include"DList.cpp"

#endif