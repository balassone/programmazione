//Container.h
#include"Box.h"
#include"DList.h"
#include<string>
#include<iostream>
#ifndef CONTAINER_H
#define CONTAINER_H

class Container {
    //overloading >>
    friend std::istream& operator>>(std::istream&,  Container&);
    //overloading<<
    friend std::ostream& operator<<(std::ostream&, const Container&);
    public:
        //Constructor
        Container(const std::string& = " ", const std::string& = " ", const std::string& = " ", const DList<Box>& = DList<Box>(), int = 0);
        
        //Set functions
        void setContainerID(const std::string&);
        void setState_Orig(const std::string&);
        void setIDCarrier(const std::string&);
        void setBoxes(const DList<Box>&);
        void setNBoxes(int n);

        //Get functions
        const std::string& getContainerID() const;
        const std::string& getStateOrig() const;
        const std::string& getIDCarrier() const;
        DList<Box> getBoxes() const;
        int getNBoxes() const;
        
    private:
        std::string id_container;
        std::string state_orig;
        std::string id_carrier;
        DList<Box> boxes;
        int n_box;
};

#endif