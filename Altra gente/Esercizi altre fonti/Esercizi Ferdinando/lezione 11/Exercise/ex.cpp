/*Scrivere un programma che legga numeri interi dalla tastiera fino a
EOF e memorizza i valori in un vettore
• Prima di aggiungere un elemento al vettore controlla se il valore è
già nel vettore, se è presente il valore non si aggiunge
• Al termine il programma emette il numero di valori memorizzati nel
vettore e i valori
• Se sono stati immessi n numeri m di cui sono diversi, potete
calcolare l'analisi del caso peggiore?
• Qual è la complessità computazionale se si mantiene ordinato il vettore?
(assumete che l'operazione di inserimento sia costante, anche se non lo è!
*/

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

void quickSort(vector<int>&,int,int);
int partition(vector<int>&,int,int);
void swap(vector<int>&,int,int);
bool check(vector<int>,int); //In questo caso non passo il riferimento perchè voglio fare solo un check; se avesi passato il riferimento al vettore allora dato che la funzione check
                             //invoca la funzione quicksort, il vettore A si sarebbe ordinato. Io voglio che l'ordine del vettore A sia quello dovuto all'inserimento dei caratteri. Se 
                             //avessi passato il vettore A per riferimento, questo si sarebbe anche ordinato.


int main(){
    int num;
    vector<int> A{};
    cout<<"Inserisi i numeri: "<<endl;
    cin>>num;
    while(!cin.eof()){
        if(!check(A,num)){
            A.push_back(num);
        }
        cin>>num;
    }

    cout<<"I numeri inseriti sono: "<<A.size()<<" e sono: "<<endl;
    for(size_t i=0; i<A.size();i++){
        cout<<A[i]<<" ";
    }
}

void quickSort(vector<int>& A,int p,int r){
    if(p<r){
        int q=partition(A,p,r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}

int partition(vector<int>& A,int p,int r){
    int x=A[p];
    int i=p-1;
    int j=r+1; 
    while(true){
        do
        {
            j=j-1;
        } while (A[j]>x);
        do
        {
            i=i+1;
        } while (A[i]<x);
        if(i<j){
            swap(A,i,j);
        }
        else{
            return j;
        }
    }
}

void swap(vector<int>& A,int i,int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

bool check(vector<int> A,int num){ //Il check lo posso fare solo su un vettore ordinato perche la binary search si basa su un vettore ordinato
    int p=0;
    int r=A.size()-1;
    quickSort(A,p,r);
    while(p<=r){
        int mid=(p+r)/2;
        if(A[mid]==num){
            return true;
        }
        else if(num>A[mid]){
            p=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return false;
}