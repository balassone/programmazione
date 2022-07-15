//PoliambulatorioDriver.cpp

#include <iostream>
#include <vector>
#include <string>
#include "LinkedQueue.h"
#include "Dottore.h"
#include "Paziente.h"
#include "quickSort.h" // quickSort e swap

using std::vector;
using std::string;
void insertPatient(vector<Dottore*>&poliambulatorio, const Paziente& p);
void removePatient(vector<Dottore*>&poliambulatorio, const Dottore* d);
void printOrder(vector<Dottore*>&poliambulatorio); // stampa l'ordine all'interno dell'array
void printArray(vector<Dottore*>&poliambulatorio);  //stampa le code all'interno dell'array
void shiftLeft(vector<Dottore*>&poliambulatorio, const int leftDoc, const int RightDoc);
void shiftRight(vector<Dottore*>&poliambulatorio, const int leftDoc, const int RightDoc); // confrontare la dimensione tra il dottore precedente e successivo e, nel caso, effettuare lo swap 




int main(){

    vector<Dottore*>poliambulatorio;
   

    Dottore d1{"Mattia","Gambardella","MTGMB67","339598877"};
    Dottore d2{"Vincenzo","Capuano","VNCCPN87","339598877"};
    Dottore d3{"Andrea","Banco","NDRBNC65","339598877"};
    Dottore d4{"Rosaria","Adinolfi","RSRDNL76","339598877"};
    poliambulatorio.push_back(&d1);
    poliambulatorio.push_back(&d2);
    poliambulatorio.push_back(&d3);
    poliambulatorio.push_back(&d4);
    Paziente p1{"Giovanni", "Muciacia", "111222333444", &d1};
    Paziente p2{"Roberto", "Totototo", "111222333444", &d1};
    d1.nuovoPaziente(p1);
    d1.nuovoPaziente(p2);
    Paziente p3{"Antonio", "Capolongo", "111222333444", &d2};
    Paziente p4{"Vincenzo", "De Luca", "111222333444", &d2};
    Paziente p5{"Mattia", "Renzi", "111222333444", &d2};
    Paziente p6{"Teodoro", "Giovanni", "111222333444", &d2};
    Paziente p7{"Esmeralda", "Cara", "111222333444", &d2};
    d2.nuovoPaziente(p7);
    d2.nuovoPaziente(p5);
    d2.nuovoPaziente(p3);
    d2.nuovoPaziente(p6);
    d2.nuovoPaziente(p4);
    Paziente p8{"Antonia", "Di Pierno", "111222333444", &d3};
    Paziente p9{"Veronica", "Senterno", "111222333444", &d3};
    Paziente p10{"Maria", "Giovanna", "111222333444", &d3};
    Paziente p11{"Francesca", "Terracciano", "111222333444", &d3};
    d3.nuovoPaziente(p11);
    d3.nuovoPaziente(p10);
    d3.nuovoPaziente(p9);
    d3.nuovoPaziente(p8);
    Paziente p12{"Renata", "Ferenza", "11223344", &d4};
    d4.nuovoPaziente(p12);
    
     
    

    Paziente p13{"Loredana", "Giannitti", "11223344", &d4};
    Paziente p14{"Loredana", "Giannitti", "11223344", &d4};
    Paziente p15{"Loredana", "Giannitti", "11223344", &d4};

    quickSort(poliambulatorio);
    printOrder(poliambulatorio);

    insertPatient(poliambulatorio, p13);
    insertPatient(poliambulatorio, p14);
    insertPatient(poliambulatorio, p15);
    std::cout << "dopo inserimento \n";
    printOrder(poliambulatorio);
    removePatient(poliambulatorio,&d2);
    removePatient(poliambulatorio,&d2);
    removePatient(poliambulatorio, &d2);
    removePatient(poliambulatorio, &d2);
    std::cout << "dopo rimozione \n";
    printOrder(poliambulatorio);
    std::cout << "STAMPA CODA DOTTORI \n";
    printArray(poliambulatorio);
   
}

void printOrder(vector<Dottore*>&poliambulatorio ){
    for(int i = 0; i<poliambulatorio.size(); i++){
        std:: cout << poliambulatorio[i]->getNome()<< " " << poliambulatorio[i]->getCognome()<< " dimensione coda " << poliambulatorio[i]->dimensioneCoda()<<"\n";
    }
}

void insertPatient(vector<Dottore*>&poliambulatorio, const Paziente& p){
    bool insert = false;
    int i{0}; // saves position
    std::string nomeDottore;
    for(i = 0; i<poliambulatorio.size(); i++){
        if(p.getDottore() == poliambulatorio[i]){
            poliambulatorio[i]->nuovoPaziente(p);
            nomeDottore = poliambulatorio[i]->getNome() +" "+ poliambulatorio[i]->getCognome();
            insert = true;
            break;
        }
    }
    if(i!=0) 
            shiftLeft(poliambulatorio, i-1, i); // verifica se la posizione va cambiata
    (insert) ? std::cout << "paziente inserito correttamente al dottore "<<nomeDottore<<"\n": std::cout << "non è stato possibile inserire il paziente \n";
}
void removePatient(vector<Dottore*>&poliambulatorio, const Dottore* d){
    bool remove = false;
    std::string nomeDottore;
    int i{0};
    for(i = 0; i<poliambulatorio.size(); i++){
        if(d == poliambulatorio[i]){
            remove = true;
            poliambulatorio[i]->fineVisita();
            nomeDottore = poliambulatorio[i]->getNome() +" "+ poliambulatorio[i]->getCognome();
            break;
        }
    }
    if(i!=(poliambulatorio.size()-1)) 
    shiftRight(poliambulatorio, i, i+1); // verifica se la posizione va cambiata
    (remove) ? std::cout << "paziente rimosso correttamente al dottore "<<nomeDottore<<"\n": std::cout << "non è stato possibile rimuovere il paziente \n";
}

void shiftLeft(vector<Dottore*>&poliambulatorio, const int leftDoc, const int rightDoc){
    if(*(poliambulatorio[leftDoc])<*(poliambulatorio[rightDoc])){
        swap(poliambulatorio, leftDoc, rightDoc);
        if((leftDoc-1)!=0){
            shiftLeft(poliambulatorio,leftDoc-1, leftDoc);
        }
    }


}
void shiftRight(vector<Dottore*>&poliambulatorio, const int leftDoc, const int rightDoc){
    if(*(poliambulatorio[leftDoc])<*(poliambulatorio[rightDoc])){
        swap(poliambulatorio, leftDoc, rightDoc);
        if((rightDoc+1) != (poliambulatorio.size()))
        {
            shiftRight(poliambulatorio,rightDoc, rightDoc+1);
        }
        
    }


}

void printArray(vector<Dottore*>&poliambulatorio){
    for(int i = 0; i<poliambulatorio.size(); i++){
        std:: cout << poliambulatorio[i]->toString() << "\n";
    }
}







