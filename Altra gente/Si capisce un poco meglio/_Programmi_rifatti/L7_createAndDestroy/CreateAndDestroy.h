//CreateAndDestroy.h


#include<string>
#ifndef CeD_H
#define CeD_H

class CreateAndDestroy {
    public: 
        CreateAndDestroy(int, std::string);     //Constructor
        ~CreateAndDestroy();                    //Destructor
    
    private:
        int objectID;
        std::string message;
};
#endif