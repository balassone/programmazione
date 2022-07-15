//Saxophonist.cpp
#include<iostream>
using std::cout;
using std::endl;

enum saxtype {SOPRANO, ALTO, TENOR, BARITONE};
class Saxophonist {
    public: 
        static int saxCount;
        //constructor definition
        Saxophonist (std::string n, saxtype p): name{n}, plays{p} {
            cout<<"Constructor called"<<endl;
            //increase every time object is created
            saxCount++;
        }
        ~Saxophonist() {
            cout<<"Destructor called"<<endl;
            --saxCount;
        }
        
        int getCount() {
            return saxCount;
        }
    private:
        std::string name; //musician name
        saxtype plays; //type of sax played
};

int Saxophonist::saxCount{0};

int main(void){
    cout<<"Number of available saxophonists before definition "<<Saxophonist::saxCount<<endl;
    {
        Saxophonist m1("John Coltrane", TENOR); //declare musician 1
        Saxophonist m2("Cannonball Hadderley", ALTO); //declare musician 2
        Saxophonist m3("Steve Lacy", SOPRANO); //declare musician 3

        //print total number of objects
        cout<<"Total objects in scope: "<<Saxophonist::saxCount<<endl;
    }
    cout<<"Total objects outside scope: "<<Saxophonist::saxCount<<endl;
    return 0;
}