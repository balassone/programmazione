//Container.cpp
#include"Container.h"
using std::string;
using std::istream;
using std::ostream;

//constructor
Container::Container(const string& id, const string& state, const string& id_carr, const DList<Box>& pacchi, int n):
id_container(id), state_orig(state), id_carrier(id_carr), boxes(pacchi){
    setNBoxes(n);
}

//Set functions
void Container::setContainerID (const string& id){
    id_container = id;
}

void Container::setState_Orig(const string& state){
    state_orig = state;
}

void Container::setIDCarrier(const string& id){
    id_carrier = id;
}

void Container::setBoxes(const DList<Box>& list){
    boxes = list;
}

void Container::setNBoxes(int n) {
    if (n>=0){
        n_box = n;
    }
    else n_box = 0;
}

//Get functions
const string& Container:: getContainerID() const {
    return id_container;
}

const string& Container:: getIDCarrier() const {
    return id_carrier;
}

const string& Container:: getStateOrig() const {
    return state_orig;
}

DList<Box> Container:: getBoxes() const {
    return boxes;
}

int Container::getNBoxes() const {
    return n_box;
}

//overloading >>
istream& operator>>(istream& in, Container& con) {
    in>>con.id_container;
    in>>con.state_orig;
    in>>con.id_carrier;
    in>>con.n_box;
    Box b;
    for (int i=0; i<con.n_box; i++){
        in>>b;
        con.boxes.addBack(b);
    }
    return in;
}

//overloading <<
ostream& operator<<(std::ostream& out, const Container& cont) {
    out<<"\nID container: "<<cont.id_container
    <<"\nOriginary state: "<<cont.state_orig
    <<"\nID carrier: "<<cont.id_carrier
    <<"\nNumber of boxes: "<<cont.n_box<<"\n\nList of boxes:\n\n";
    for (int i=0; i<cont.boxes.size(); i++){
        out<<cont.boxes[i]<<"\n\n";
    }
    return out;
}
