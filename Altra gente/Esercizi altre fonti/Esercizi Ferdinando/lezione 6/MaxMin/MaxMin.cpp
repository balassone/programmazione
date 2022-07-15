#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
    int x;
    int min;
    int max;

    cout<<"Inserisci i numeri dei quali vuoi calcolare il massimo ed il minimo"<<endl;
    cout<<"(Premi 0 quando hai terminato)"<<endl;
    cin>>x;
    min=x;
    max=x;
    while(x!=0){
        if(x<min) min=x;
        else if (x>max) max=x;
        cin>>x;
    }

    cout<<"Il massimo è: "<<max<<endl;
    cout<<"Il minimo è: "<<min;

    return 0;

}