//testInstrument.cpp
#include<vector>
#include<iostream>
#include"Instrument.h"
using std::cout;
using std::endl;

using std::vector;

void tune(Instrument& i) {
    i.play(middleC);
}

//Upcasting during array initialization

int main () {
    vector<Instrument*> Band;
    Wind flute;
    Percussion drum;
    Stringed violin;
    Brass flugelhorn;
    Woodwind alto;
    Woodwind tenor;
    cout<<"---Rehersal---"<<endl;

    tune(flute);
    tune (drum);
    tune(violin);
    tune(flugelhorn);
    tune(alto);
    tune(tenor);
    cout<<"---Let' gig together"<<endl;

//uso push_back, funzione della classe vector, per accodare oggetti al vettore 
    Band.push_back(&flute);
    Band.push_back(&drum);
    Band.push_back(&violin);
    Band.push_back(&flugelhorn);
    Band.push_back(&alto);
    Band.push_back(&tenor);

//versione compatta del for; è un for normale solo che la i non è un intero ma un elemento di Band
    for(Instrument* i : Band){
        tune(*i);
    }

}