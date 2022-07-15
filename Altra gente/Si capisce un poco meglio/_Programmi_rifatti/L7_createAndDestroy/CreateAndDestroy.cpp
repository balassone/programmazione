//CreateAndDestroy.cpp
#include"CreateAndDestroy.h"
#include<iostream>
using std::cout; using std::endl;
using std::string;

//constructor
CreateAndDestroy::CreateAndDestroy(int ID, string mess) : objectID{ID}, message{mess} {
    cout<<"Object "<<objectID<<"Constructor runs "<<message<<endl;
} 
//destructor
CreateAndDestroy::~CreateAndDestroy() {
    cout<<"Object "<<objectID<<"Destructor runs"<<message<<endl;
}