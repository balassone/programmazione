#include "Data.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    string x;
    int giorno;
    int mese;
    int anno;

    Data d1{4,2,2020};
    Data d2{1,4,2021};

    cout<<"La data d1 è: "<<d1.Display()<<endl;
    cout<<"La data d2 è: "<<d2.Display()<<endl;
    cout<<"Vuoi cambiare la data d1 o d2? "<<endl;
    cin>>x;
    if(x=="d1"){
        cout<<"Giorno: ";
        cin>>giorno;
        cout<<"Mese: ";
        cin>>mese;
        cout<<"Anno: ";
        cin>>anno;
        d1.setGiorno(giorno);
        d1.setMese(mese);
        d1.setAnno(anno);

        cout<<"\nLa nuova data è: "<<d1.Display();
    }
    else{
        cout<<"Giorno: ";
        cin>>giorno;
        cout<<"Mese: ";
        cin>>mese;
        cout<<"Anno: ";
        cin>>anno;
        d2.setGiorno(giorno);
        d2.setMese(mese);
        d2.setAnno(anno);

        cout<<"\nLa nuova data è: "<<d2.Display();

    }

return 0;


}