#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
//Il merge sort è un algoritmo di ordinamento che si basa sulla ricicorsone e sul principio divide et impera.
void merge_sort(vector<int>&,int,int);
void merge(vector<int>&,int,int,int);

int main(){
    vector<int> v1{}; //Definisco un vettore di interi e lo inizializzo a 0
    int x;
    cout<<"Inserisci i numeri da ordinare (digita -1 quando hai terminato) :"<<endl;
    cin>>x;
    while(x!=-1){
        v1.push_back(x);
        cin>>x;
    }

    size_t l=v1.size();

    cout<<"Il vettore di numeri inserito è: "<<endl;
    for(size_t i=0; i<l; i++){
        cout<<v1[i]<<" ";
    }
    merge_sort(v1,0,l-1); //Invoco il merge sort sul vettore v1 e sugli elementi che vanno dalla posizone 0 alla posizione l-1 dove l è il numero di elementi nel vettore

    cout<<"\nIl vettore di numeri ordinato è: "<<endl;
    for(size_t i=0; i<l;i++){
        cout<<v1[i]<<" ";
    }
}

void merge_sort(vector<int>& A,int p,int r){ //A è il vettore di interi che è passato per riferimento, p ed r fanno riferimento agli estermi del vettore da ordinare
    int q; //definisco una variabile q intera
    if(p<r){ //inizialmente p=0 e q=n-1. //dire che p<r significa che nel vettore ci sono almeno due elementi da ordinare //se nel vettore ci fosse un solo elemento questo sarebbe già ordinato //dunque la condiizone dell'if è il passo base
        q=(p+r)/2; //divido il vettore a metà. Questo è il passo divide
        merge_sort(A,p,q); //passo impera. Applico ricorsivamente il merge sort in maniera tale da risolvere un problema più piccolo (metà vettore)
        merge_sort(A,q+1,r); //passo impera. Applico ricorsivamente il merge sort in maniera tale da risolvere un problema più piccolo (altra metà del vettore)
        merge(A,p,r,q); //Passo combina per ottenere il vettore risultante
    }
}

void merge(vector<int>& A,int p,int r,int q){
    int i=p; //indice che scorre il la prima metà del vettore
    int j=q+1; //indice che scorre la seconda metà del vettore
    int k=p; //indice che scorre il vettore risultante B
    static vector<int>B(A.size()); //definisco questo vettore static perchè la funzione merge viene richiamata parecchie volte dal merge_sort e si vuole evitare di andare ad allocare ogni volta un nuovo vettore in memoria. Un'altra soluzione sarebbe stata quella di definire il vettore globale
    //Il vettore B deve avere la stessa dimensione del vettore A
    while(i<=q && j<=r){
        if(A[i]>A[j]){ 
            B[k]=A[j];
            k++;
            j++;
        }
        else{
            B[k]=A[i];
            k++;
            i++;
        }
    }
    //ad un certo punto il primo while fallià perchè o sono stati scorsi tutti gli elementi del primo vettore o sono stati scorsi tutti gli elementi del secondo vettore
    while(i<=q){ 
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=r){
        B[k]=A[j];
        k++;
        j++;
    }
    for(i=p;i<k;i++){
        A[i]=B[i];
    }
}