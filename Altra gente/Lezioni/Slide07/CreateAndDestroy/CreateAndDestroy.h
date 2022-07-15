// createAndDestroy.h
// CreateAndDestroy class definition
#include <string> 

#ifndef CREATE_H
#define CREATE_H

class CreateAndDestroy {
    public:
    CreateAndDestroy (int, std::string); // constructor
    ~CreateAndDestroy(); // destructor
    private:
    int objectID; // ID number for object
    std::string message; // message describing object
};

#endif