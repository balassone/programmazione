#include "Date.h"
#include"LinkedList.h"
#include"Progetto.h"
#include"Programmatore.h"

using std::vector;
using std::cout;
using std::cin;

void insertProgrammatori(vector<Programmatore*>& , Programmatore&);



void quickSort(vector<Programmatore*>&,int,int);
int partition(vector<Programmatore*>&,int,int);
void swap(vector<Programmatore*>&,int,int);

Programmatore p1{"Matt Groening", 20};
Programmatore p2{"Sam Simon", 50};
Programmatore p3{"John Swartzwelder", 10};

LinkedList tsk;
Task regaloLisa{p1, "scena regalo Lisa", {27,05,2005}, 30};
Task regaloBart{p1, "scena regalo Bart", {21,05,2005}, 25};
Task costumeSalamandraStracciato{p2, "costume salamandra stracciato durante la lavatrice", {26,05,2005}, 25};
Task elezioniSalamandra{p1, "scena elezioni salamandra", {25,05,2005}, 25};
Task costumeSalamandra{p2, "creazione costume salamandra sicurezza", {24,05,2005}, 40};

std::string printVector(vector<Programmatore*>& A){
    std::ostringstream out;
    out<<"I Programmatori sono: \n";
    for(int i=0; i<A.size(); i++){
        out<<A[i]->toString()<<"\n";
    }
    return out.str();
}



int main(){
    vector<Programmatore*> vettore;
    tsk.print();
    tsk.addOrder(regaloLisa);
    tsk.addOrder(regaloBart);
    tsk.addOrder(costumeSalamandra);
    tsk.addOrder(costumeSalamandraStracciato);
    tsk.addOrder(elezioniSalamandra);
    cout << tsk.size();
    tsk.print();

    (regaloBart < regaloLisa) ? cout << "ok \n" : cout << "no \n";
    (regaloLisa >= regaloBart) ? cout << "ok \n" : cout << "no \n";

    Progetto salamandra{"Salamandra", "Homer Simpson", 350.00, {20,05,2005}, {12,03,2007}, tsk};
    cout <<salamandra.size();
    salamandra.print();
    insertProgrammatori(vettore, p2);
    insertProgrammatori(vettore, p1);
    insertProgrammatori(vettore, p3);

    cout << printVector(vettore);

    cout << "\n";
    cout << "calcolando le ore uomo di"<<p2.getNome();
    cout << "\n le ore uomo di "<<p2.getNome() << " sono "<<salamandra.workLoadDeveloper(p2);

    


    return 0;
}

void quickSort(vector<Programmatore*>& v1,int p,int r){
    if(p<r){ //passo base //ci sono almeno due elementi nel vettore
        int q=partition(v1,p,r);
        quickSort(v1,p,q);
        quickSort(v1,q+1,r);
    }
}

int partition(vector<Programmatore*>& v1,int p,int r){
    Programmatore* x=v1[p]; //elemento pivot //è il primo elemento del vettore
    int i=p-1;
    int j=r+1;
    while(true){
        do
            j=j-1;
        while(*v1[j]>*x);
        do      
            i=i+1;
        while(*v1[i]<*x);
        if(i<j){
            swap(v1,i,j);
        }
        else{
            return j;
        }
    }
}

void swap(vector<Programmatore*>& A,int x,int y){
    Programmatore* temp;
    temp=A[x];
    A[x]=A[y];
    A[y]=temp;
}


void insertProgrammatori(vector<Programmatore*>& A , Programmatore& p){
    A.push_back(&p);
    quickSort(A,0,A.size()-1);

}
    