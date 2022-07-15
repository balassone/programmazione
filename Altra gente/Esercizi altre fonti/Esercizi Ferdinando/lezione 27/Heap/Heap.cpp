#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void printArray(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
}

void swap(int A[],int i,int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}


void heapify(int A[],int n,int i){
    int largest=i;
    int l=2*i+1; //nodo figlio del sottoalbero di sx
    int r=(2*i)+2; //nodo filgio del sottoalbero di dx
    if(l<n && A[l]>A[largest]) largest=l;
    if(r<n && A[r]>A[largest]) largest=r;
    if(largest!=i){
        swap(A,i,largest);
        heapify(A,n,largest);
    }
}

void buildHeap(int A[],int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(A,n,i);
    }
}

void heapSort(int A[],int n){
    buildHeap(A,n);
    for(int i=n-1; i>0; i--){
        swap(A,0,i);
        heapify(A,i,0);
    }
}

int main(){
    int A[]={12,11,13,5,7,6};
    int n=sizeof(A)/sizeof(A[0]);

    heapSort(A,n);
    cout<<"L'array ordinato è: "<<endl;
    printArray(A,n); 

}