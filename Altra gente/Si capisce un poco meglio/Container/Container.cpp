//Container.cpp
#include"Container.h"
#include"Box.h"
#include<sstream>
using std::string;
using std::list;
using std::ostringstream;

//Constructor
Container::Container(string& id, string& state, string& id_carr, int num_boxes, list<Box>& boxList) {
    setIDContainer(id);
    setStateOrig(state);
    setIDCarrier(id_carr);
    setNBoxes(num_boxes);
    setBoxList(boxList);
}
//Constructor
Container::Container() :
id_container(" "), state_orig(" "), id_carrier(" "), n_boxes(0) {}


//Set & get
void Container::setIDContainer(string& id){
    id_container=id;
}
string Container::getIDContainer() const {
    return id_container;
}

void Container::setStateOrig(string& state) {
    state_orig=state;

}
string Container::getStateOrig() const {
    return state_orig;
}

void Container::setIDCarrier(string& carr) {
    id_carrier=carr;
}
string Container::getIDCarrier() const {
    return id_carrier;
}

void Container::setNBoxes(int n){
    if (n<0){
        n_boxes=0;
    }
    else n_boxes=n;
}
int Container::getNBoxes() const {
    return n_boxes;
}

void Container::setBoxList(list<Box>& boxList){
    box_list=boxList;
}

string Container::toString() {
    ostringstream out;
    out<<"  Container: ";
	out<<"\n  Id container: "<< id_container;
	out<<"\n  Provenience: "<< state_orig;
	out<<"\n  Id carrier: "<< id_carrier;
	out<<"\n  Num boxes: "<< n_boxes << "\n";
    return out.str();    
}

istream& operator>>(istream& in, Container& c){
    in>>c.id_container>>c.state_orig>>c.id_carrier>>c.n_boxes;
    return in;
}
