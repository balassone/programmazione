//testDList.cpp
#include"DList.h"
#include"iostream"
using std::cout;
using std::endl;

int main() {
    DList<int> a;
    a.addFront(1);
    a.addBack(2);
    for (int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"Aggiungo 3 in coda, 4 in testa\n";
    a.add(a.end(),3);
    a.add(a.begin(), 4);
    for (int i=0; i< a.size(); i++){
        cout<<a[i]<<" "; 
    }
    cout<<endl;

    cout<<"Rimuovo l'elemento in coda\n";
    a.removeBack();
    for (int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"Rimuovo l'elemento in testa\n";
    a.removeFront();
    for (int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }    
    cout<<endl;
    
    DList<int> b{a};
    cout<<"lista b copiata da a con il costr. di copia"<<endl;
    for (int i=0; i<b.size(); i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;

    DList<int> c = a;   
    cout<<"lista c copiata da a con l'operatore di assegnazione = "<<endl; 
    for (int i=0; i<c.size(); i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
}