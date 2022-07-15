#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

//Ricerca binaria per iterazione
int binary_search(vector<int>&,int);

int main(){
    //La ricerca binaria si basa su un array già ordinato.
    //Ha una complessità computazionale che nel caso peggiore è o(log(n)) a differenza della ricerca sequenziale che ha una complessità computazionale che nel caso peggiore è o(n);
    vector<int> A{10,20,30,40,50,60,70,80,90};
    int x;

    cout<<"Qual'è il numero che vuoi carcare nel vettore? "<<endl;
    cin>>x;
    cout<<"Il numero "<<x<<" si trova in posizione "<<binary_search(A,x)<<" del vettore A"<<endl;
    
}

int binary_search(vector<int>& v1,int num){
    int p=0;
    int r=v1.size()-1;
    while(p<=r){
        int mid=(p+r)/2;
        if(num==v1[mid]){
            return mid;
        }
        else if(num>v1[mid]){
            p=mid+1;
        }
        else{
            r=mid-1;
        } 
    }
    return -1;
}