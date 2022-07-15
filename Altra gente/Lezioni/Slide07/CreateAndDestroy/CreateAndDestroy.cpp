// CreateAndDestroy.cpp
// CreateAndDestroy class member-function definitions.
#include <iostream> 
#include "CreateAndDestroy.h" // include CreateAndDestroy class definition
using std::cout; using std::endl; using std::string;

//constructior sets object's ID number and descriptive message
CreateAndDestroy::CreateAndDestroy(int ID, string messageString) : objectID{ID}, message{messageString} {
    cout << "Object " << objectID << "  constructor runs    " << message << endl;

}

//destructior
CreateAndDestroy::~CreateAndDestroy(){
    //output newline for certain objects; helps readability
    cout << "Object " << objectID << "      destructior runs     " << message << endl;

}

