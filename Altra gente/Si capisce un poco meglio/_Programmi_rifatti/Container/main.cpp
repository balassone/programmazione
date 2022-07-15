//main.cpp
#include"Queue.h"
#include"Container.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
using std::ifstream;
using std::ios;
using std::cout; using std::endl; using std::cerr;

DList<Box> clearance(Queue<Container>&, double);

int main(){
    ifstream inFile("containers.txt", ios::in);
    if (!inFile){
        cerr<<"File could not be opened."<<endl;
        exit(EXIT_FAILURE);
    }
    Queue<Container> q;
    Container c;
    while (inFile>>c){
        q.enqueue(c);
    }
    inFile.close();
    for (int i=0; i<q.size(); i++){
        cout<<q[i];
    }

    clearance(q, 1.1);

}

DList<Box> clearance(Queue<Container>& queue, double soglia){
    double v{0};
    double w{0};
    DList<Box> giacenza;
    for (int i=0; i<queue.front().getNBoxes(); i++){
        v+=queue.front().getBoxes().operator[](i).getBoxValue();
        w+=queue.front().getBoxes().operator[](i).getBoxWeight();
    }
        cout<<"total value: "<<v<<endl;
        cout<<"total weight: "<<w<<endl;

    if (v >= soglia) {
        for (int i=0; i<queue.front().getNBoxes(); i++){
            if (queue.front().getBoxes()[i].getPerishable()== 1){
                giacenza.addBack(queue.front().getBoxes()[i]);
            }
            else {
                queue.front().getBoxes().erase(queue.front().getBoxes()[i]);
            }
        }
        cout<<"\nLista di giacenza: "<<endl;
        for (int i=0; i<giacenza.size(); i++){
            cout<<giacenza[i];
        }
    }
    return giacenza;
}