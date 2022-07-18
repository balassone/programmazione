#include "Node.h"
#include "Pacco.h"
#include <stdexcept>
class LinkedList{
    public:
        LinkedList() : head{nullptr} {}
        bool empty() const {return head==nullptr;}
        int size() const {
            int count{0};
            Node* curr=head;
            while(curr!=nullptr){
                curr=curr->next;
                count++;
            }
            return count;
        }
        
        LinkedList& addOrder(Pacco* p){
            if(empty()){
                head=new Node;
                head->elem=p;
                head->next=nullptr;
            } else {
                Node* prev=nullptr;
                Node* curr=head;
                while(curr!=nullptr && curr->elem->getDate()<p->getDate()){
                    prev=curr;
                    curr=curr->next;
                }
                if(curr!=nullptr){
                    if(curr==head){
                        Node* actual=new Node;
                        actual->elem=p;
                        actual->next=head;
                        head=actual;
                    }
                    else{
                        prev->next=new Node;
                        prev->next->elem=p;
                        prev->next->next=curr;
                    }
                } else{
                    prev->next=new Node;
                    prev->next->elem=p;
                    prev->next->next=nullptr;
                }
            }
            return *this;
        }
        
        Pacco* operator[](int i){
            if(i<0 || i>size()){
                throw std::runtime_error("Out of range!");
            } else{
                Node* curr=head;
                for(int j{0}; j<i; ++j){
                    curr=curr->next;
                }
                return curr->elem;
            }
        }
    void removeFront(){
        if(!empty()){
            Node* curr=head;
            head=head->next;
            delete[] curr;
        }
    }
    ~LinkedList(){
        while(!empty()){
            removeFront();
        }
    }

    private:
        Node* head;
};