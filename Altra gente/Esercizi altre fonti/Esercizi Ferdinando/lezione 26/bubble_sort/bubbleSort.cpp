#include "LinkedList.h"
#include <iostream>
using std::cout;

void bubbleSort(LinkedList<int>&);
void swap(LinkedList<int>&,int,int);


int main(){
    LinkedList<int> L;
    L.addFront(3);
    L.addFront(5);
    L.addFront(1);
    L.addFront(4);
    L.addFront(2);
    bubbleSort(L);
    cout<<L.toString();

}

void bubbleSort(LinkedList<int>& v){
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

void swap(LinkedList<int>& v,int i,int j){
    int temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}