//Containers.h
#ifndef     CONTAINER_H
#define     CONTAINER_H
#include "Box.h"
#include <list>
#include<sstream>
#include<string>
using std::list;
using std::string;
using std::istream;
using std::ostream;

class Container {
    friend istream& operator>>(istream&, Container&);
    public:
        explicit Container(string&, string&, string&, int, list<Box>&);        //constructor
        Container();
 
        //set & get functions
        void setIDContainer(string&);
        string getIDContainer() const;

        void setStateOrig(string&);
        string getStateOrig() const;

        void setIDCarrier(string&);
        string getIDCarrier() const;

        void setNBoxes(int);
        int getNBoxes() const;

        void setBoxList(list<Box>&);
        list<Box> getBoxList() const;

        virtual string toString();


    private:
        string id_container;
        string state_orig;
        string id_carrier;
        int n_boxes;
        list<Box> box_list;
       

};

#endif
