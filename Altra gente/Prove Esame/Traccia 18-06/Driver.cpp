#include "Prestito.h"
#include "Libro.h"
#include "Data.h"
#include <vector>
#include <string>
#include <list>
using std::list;
using std::string;
using std::vector;
using std::cout;
using std::endl;

void quickSort(vector<Libro>&,int,int);
int partition(vector<Libro>&,int,int);
void swap(vector<Libro>&,int,int);
void borrow(list<Prestito>&,Libro&,Data&);
int valueExpired(const list<Prestito>&,const Data&);
void stampa(Prestito);

int main(){

    vector<Libro> libri{};
    vector<string> a1{"Riccardo","Orsolini"};
    vector<string> a2{"Ciccarelli","Ferrante"};
    Libro l1{01,a1,"Una bella storia",1994,"A001",12.5};
    Libro l2{02,a2,"Il domani",1954,"A0015",13.0};
    Libro l3{03,a1,"Buongiorno",1995,"A0020",15.5};

    libri.push_back(l1);
    libri.push_back(l2);
    libri.push_back(l3);

    quickSort(libri,0,libri.size()-1);

    list<Prestito> prest{};
    Data d1{4,10,2021};
    Data d2{6,10,2021};
    Data d3{5,9,2021};
    Prestito p1{l1,d1};
    Prestito p2{l2,d2};
    Prestito p3{l3,d3};

    borrow(prest,l1,d1);
    borrow(prest,l2,d2);
    borrow(prest,l3,d3);

    cout<<"I libri prestati sono: "<<endl;
    list<Prestito> p=prest;
    while(!p.empty()){
        stampa(p.front());
        p.pop_front();
    }

    cout<<endl;
    Data dat{7,10,2021};
    cout<<"Il numero di libri prestati la cui data di restituzione è scaduta è: "<<valueExpired(prest,dat);
}

void quickSort(vector<Libro>& l,int p,int r){
    if(p<r){
        int q=partition(l,p,r);
        quickSort(l,p,q);
        quickSort(l,q+1,r);
    }
}

int partition(vector<Libro>& l,int p,int r){
    Libro x=l[p];
    int i=p-1;
    int j=j+1;
    while(true){
        do j=j-1;
        while(x<l[j]);
        do i=i+1;
        while(l[i]<x);
        if(i<j){
            swap(l,i,j);
        }
        else{
            return j;
        }
    }
}

void swap(vector<Libro>& l,int i,int j){
    Libro temp=l[i];
    l[i]=l[j];
    l[j]=temp;
}


void borrow(list<Prestito>& pre,Libro& l,Data& d){
    Prestito p{l,d};
    pre.push_front(p);
}

int valueExpired(const list<Prestito>& pre,Data& dat){
    list<Prestito> p=pre;
    int num=0;
    while(!p.empty()){
        if(dat<p.front().DataRestituzione()) num++;
        p.pop_front();
    }
    return num;
}

void stampa(Prestito p){
    cout<<p.getLibroPrestato()<<endl;
    cout<<"Data prestito: "<<p.getDataPrestito()<<endl;
    cout<<"Data restituzione"<<p.DataRestituzione()<<endl;
}