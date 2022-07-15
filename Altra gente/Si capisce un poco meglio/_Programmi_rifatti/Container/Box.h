//Box.h
#include<string>
#include<iostream>
#ifndef BOX_H
#define BOX_H


class Box {
    //overload >>
    friend std::istream& operator>>(std::istream&, Box&); 
    //overload <<
    friend std::ostream& operator<<(std::ostream&, const Box&);
    public:
        //constructor
        Box(const std::string& = " ", double = 0.0, double = 0.0, int = 0);
        
        //Set functions
        void setBoxID(const std::string&);
        void setBoxWeight(double);
        void setBoxValue(double);
        void setPerishable(int);

        //Get functions
        const std::string& getBoxID() const;
        double getBoxWeight() const;
        double getBoxValue() const;
        int getPerishable() const;

        bool operator==(const Box&) const;
 

    private:
        std::string box_id;
        double weight;
        double value;
        int perishable;
};

#endif