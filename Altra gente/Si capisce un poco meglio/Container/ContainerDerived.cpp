//ContainerDerived.cpp
#include<sstream>
#include"ContainerDerived.h"
using std::ostringstream;

ContainerDerived::ContainerDerived(string& id, string& state, string& id_carr, int num_boxes, list<Box>& boxList, int num_cont) {
    Container(id,state,id_carr,num_boxes,boxList);
    num_container = num_cont;
}

//set & get functions
void ContainerDerived::setNumberContainer(int num){
    num_container=num;
}
int ContainerDerived::getNumberContainer() const {
    return num_container;
}

string ContainerDerived::toString() {
    ostringstream out;
    out<<Container::toString()<<"Container's number: "<<num_container<<"\n";
    return out.str();
}