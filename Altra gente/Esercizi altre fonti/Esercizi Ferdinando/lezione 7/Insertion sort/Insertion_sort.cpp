#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
    int x;
    int indice=0;
    int numbers[100];
    cout<<"Inserisci i numeri da ordinare e premi 0 quando hai finito: "<<endl;
    cin>>x;
    while(x!=0){
        numbers[indice++]=x;
        cin>>x;
    }

    cout<<"I numeri inseriti sono:"<<endl;
    for(int i=0; i<indice; i++){
        cout<<numbers[i]<<" ";
    } 


    for(int j=1; j<indice;j++){
        int key=numbers[j];
        int i=j;
        while(i>0 && numbers[i-1]>key){
            numbers[i]=numbers[i-1];
            i--;
        }
        numbers[i]=key;
    }

    cout<<"I numeri ordinati sono:"<<endl;
    for(int i=0; i<indice; i++){
        cout<<numbers[i]<<" ";
    }

    return 0;





}
