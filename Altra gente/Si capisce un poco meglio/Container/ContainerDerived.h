//ContainerDerived.h

#ifndef CONTAINERDERIVED_H
#define CONTAINERDERIVED_H

#include"Container.h"
#include"Box.h"

class ContainerDerived : public Container {
    
    public: 
        explicit ContainerDerived (string&, string&, string&, int, list<Box>&, int);

        void setNumberContainer(int);
        int getNumberContainer() const;

        string toString();
    private:
        int num_container;
};

#endif