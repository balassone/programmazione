//main.cpp
#include "Box.h"
#include"Container.h"
#include"ContainerDerived.h"
#include<iostream>
#include<fstream>
#include"LinkedQueue.h"
#include<vector>
#include<list>

using std::ifstream;
using std::ios;
using std::cerr;
using std::vector;
using std::list;

void clearance(LinkedQueue<Container>&);

int main() {
    //read containers.txt
    ifstream inFile("containers.txt", ios::in);
    if (!inFile){
        cerr<<"File could not be opened"<<std::endl;
        exit(EXIT_FAILURE);
    }
    vector<Container> container;
    vector<Box> box;
    
    LinkedQueue<Container> containers;
    LinkedQueue<Box> boxes;

    int i=0;
    while (inFile>>container[i]>>box[i]){
        containers.enqueue(container[i]);
        
        i++;        
    }
    inFile.close();


}


void clearance(LinkedQueue<Container>& c, double soglia){
    double totalWeight=0.0;
    double totalValue=0.0;
    Container A = c.front();
    list<Box>* myList = &(A.getBoxList());
    list<Box> giacenza;
    for(list<Box>::iterator it = myList->begin(); it != myList->end(); it++){
        totalWeight+=it->getWeight();
        totalValue+=it->getValue();
    }
    if (totalValue>soglia){
        for (list<Box>::iterator i = myList->begin(); i != myList->end(); i++){
            if (i->getPerishable() == 1){
                giacenza.push_front(*i);
            }
        }
    }
    c.dequeue();
    
}