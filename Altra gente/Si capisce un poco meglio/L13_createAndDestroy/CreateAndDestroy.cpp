//CreateAndDestroy.cpp
//CreateAndDestroy class member-functions definitions.
#include<iostream>
#include "CreateAndDestroy.h"
using std::cout;
using std::endl;
using std::string;

//constructor sets object's ID number and descriptive message
CreateAndDestroy::CreateAndDestroy(int ID, string messageString)
    : objectID{ID}, message{messageString} {
        cout<<"Object "<<objectID<<" constructor runs "<<message<<endl;
}

//destructor
CreateAndDestroy::~CreateAndDestroy(){
    cout<<"Object "<<objectID<<" destructor runs    "<<message<<endl;
}
