//Box.h  - Box class interface
#ifndef BOX_H
#define BOX_H
#include<string>
#include<istream>
#include<sstream>
using std::istream;
using std::string;

class Box {
    friend istream& operator>>(istream&, Box&);
    public:
    
        Box(string&, double =0, double =0, short int = 0);       //constructor

        //set and get functions
        void setBoxID(std::string&);
        std::string getBoxID() const;
        
        void setWeight(double);
        double getWeight() const;
        
        void setValue(double);
        double getValue() const;
        
        void setPerishable(short int);
        short int getPerishable() const;

        string toString();
        

    private:
        string box_id;
        double weight;
        double value;
        short int perishable;

        
};

#endif