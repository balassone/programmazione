#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool palindromo(int array[],int indice);

int main(){
    int array[20];
    int indice=0;
    int x;
    cout<<"Inserisci il numero e ti dirò se è palindromo"<<endl;
    cin>>x;
    while(x!=0){
        array[indice++]=x%10;
        x=x/10;
    }

    if(palindromo(array,indice)){
        cout<<"Il numero inserito è palindromo"<<endl;
    }
    else{
        cout<<"Il numero inserito non è palindromo"<<endl;
    }

}

bool palindromo(int array[],int indice){
    int i=0;
    while(i<indice/2){
        if(array[i]==array[indice-i-1]){
            i++;
        }
        else return false;
    }
    return true;
}