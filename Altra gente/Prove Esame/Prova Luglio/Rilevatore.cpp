#include"Rilevatore.h"
#include "RilevList.h"
#include "Rilevamento.h"

Rilevatore::Rilevatore(int i, int x, int y, RilevList& lista){
    setId(i);
    setCx(x);
    setCy(y);
    setList(lista);
}



Rilevatore::Rilevatore(const Rilevatore& r){
    this->id=r.id;
    this->coordx=r.coordx;
    this->coordy=r.coordy;
    this->rilevamenti=r.rilevamenti;

}

Rilevatore::~Rilevatore(){
    while(!rilevamenti.empty()){
    rilevamenti.remove();
    }

}

Rilevatore& Rilevatore::operator=(const Rilevatore& r){
    this->id=r.id;
    this->coordx=r.coordx;
    this->coordy=r.coordy;
    this->rilevamenti=r.rilevamenti;

    return *this;
}

void Rilevatore::addMeasurement(const Rilevamento& r){
    rilevamenti.insertBack(r);
    quickSort(rilevamenti, 0, rilevamenti.size()-1);   
}


 void quickSort(RilevList& v1, int p, int r){
     int q= partition(v1, p, r);
     quickSort(v1, p, q);
     quickSort(v1, q+1, r);

 }

 
 int partition(RilevList& v1,int p,int r){
    Rilevamento x=v1[p]; //elemento pivot //è il primo elemento del vettore
    int i=p-1;
    int j=r+1;
    while(true){
        do
            j=j-1;
        while(v1[j].getData()>x.getData());
        do      
            i=i+1;
        while(v1[i].getData()<x.getData());
        if(i<j){
            swap(v1,i,j);
        }
        else{
            return j;
        }
    }
}

void swap(RilevList& A,int x,int y){
    Rilevamento temp=A[x];
    A[x]=A[y];
    A[y]=temp;
}


Rilevatore& Rilevatore::operator[](int i){
    for(int j=0; j<i; j++){
        
    } 
}

double Rilevatore::meanCO2Rilevator(Date d1, Date d2){
    int countRilevator = 0;
    double averageppm = 0.0;
    for(int i = 0; i<rilevamenti.size(); i++){
        if((rilevamenti[i].getData()>=d1) && (rilevamenti[i].getData()<=d2)){
            countRilevator++;
            averageppm += rilevamenti[i].getPPM();
    
    }


}