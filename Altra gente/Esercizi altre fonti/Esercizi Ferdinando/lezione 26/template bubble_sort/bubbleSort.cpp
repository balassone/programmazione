#include "LinkedList.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;

template <typename T> void bubbleSort(LinkedList<T>&);
template <typename T> void swap(LinkedList<T>&,int,int);


int main(){
    LinkedList<int> L;
    L.addFront(3);
    L.addFront(5);
    L.addFront(1);
    L.addFront(4);
    L.addFront(2);
    bubbleSort(L);
    cout<<L.toString()<<endl;
    LinkedList<string> S;
    S.addFront("tre");
    S.addFront("cinque");
    S.addFront("uno");
    S.addFront("quattro");
    S.addFront("due");
    bubbleSort(S);
    cout<<S.toString()<<endl;

}

template <typename T>
void bubbleSort(LinkedList<T>& v){
    int n=v.size();	 	  	 	      	   	 	  	    	 	
    int k=0;
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=0; i<(n-1-k); i++){
            if(v[i]>v[i+1]){
                swap(v,i,i+1);
                flag=true;
            }
        }
        k++;
    }
}

template <typename T>
void swap(LinkedList<T>& v,int i,int j){
    T temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}