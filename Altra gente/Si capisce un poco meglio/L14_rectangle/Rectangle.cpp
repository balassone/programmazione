//Rectangle.cpp
 #include<iostream>
 #include<iomanip>
 #include<cmath>
 #include<stdexcept>
 #include"Rectangle.h"
 using std::cout;
 using std::invalid_argument;

 Rectangle::Rectangle(Point a, Point b, Point c, Point d, char fillChar, char perimeterChar) {
     setCoord(a,b,c,d);
     setFillCharacter(fillChar);
     setPerimeterCharacter(perimeterChar);
 }

 void Rectangle::setCoord(Point p1, Point p2, Point p3, Point p4) {
    // Arrangement of points
    // p4..........p3
    //  .          .
    //  .          .
    // p1..........p2

    //verify points form a rectangle
    if (!(p1.getY() == p2.getY() && p1.getX() == p4.getX() && p2.getX() == p3.getX() && p3.getY() == p4.getY())) {
        throw invalid_argument("Coordinates do not form a rectangle!\n");
    }
    point1=p1;
    point2=p2;
    point3=p3;
    point4=p4;
 }

 double Rectangle::height() const {
     return fabs(point4.getY() - point1.getY());
 }
 
 double Rectangle::width() const {
     return fabs(point4.getX()-point3.getX());
 }

 double Rectangle:: perimeter() const {
     return 2*(height()+width());
 }

 double Rectangle::area() const {
     return (height()*width());
 }

 bool Rectangle::square() const {
     return (height()==width());
 }

 //draw rectangle
 void Rectangle::draw() const {
     for (double y{25.0}; y>=0; --y) {
         for (double x{0.0}; x<=25.0; ++x) {
             if((point1.getX()== x && point1.getY()==y)|| point4.getX()==x && point4.getY()==y) {
                 //print horizontal perimeter of rectangle
                 while (x < point2.getX()) {
                     cout<<perimeterCharacter;
                     ++x;
                 }
                 cout<<'.'; //print remainder of quadrant
             }
             else if((x<=point4.getX() && x >= point1.getX() && point4.getY() >= y && point1.getY() <=y)) {
                 cout<<perimeterCharacter;
                 ++x;
            
             
                //fill inside of rectangle
                for(++x; x<point2.getX();){
                     cout<<fillCharacter;
                     ++x;
                }
                cout<<perimeterCharacter;
            }
            else {
                cout<<'.';  //print quadrant background
            }
         }
         cout<<"\n";
     }
 }

 //set fill character
 void Rectangle::setFillCharacter(char fillChar){
     fillCharacter = fillChar;
 }

 //set perimeter character
 void Rectangle::setPerimeterCharacter(char perimeterChar){
     perimeterCharacter = perimeterChar;
 }