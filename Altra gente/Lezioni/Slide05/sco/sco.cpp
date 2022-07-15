// sco.cpp
// Scoping example

#include <iostream>
using std::cout;
using std::endl;

void useLocal(); // function prototype
void useStaticLocal();  // function prototype 
void useGlobal(); // function prototype 

int x{1}; // global variable
int main(){
    cout << "global x in main is " << x << endl ;

    int x{5}; // local variable to main

    cout << "local x in main's outer scope is " << x<< endl;

    { // block starts a new scope
        int x{7}; // hides both x in outer scope and global x
        
        cout << "local x in main's inner scope is " << x << endl;
    }

    cout << "local x in main's outer scope is " << x << endl;
    useLocal(); // useLocal has local x
    useStaticLocal() ; // useStaticLocal has static local x
    useGlobal(); // useGlobal uses global x
    useLocal(); // useLocal reinitializes its local x
    useStaticLocal(); // static local x retains tis prior value
    useGlobal(); // global x also retains ita prior value

    cout << "\n local x in main is " << x << endl;
}
// useLocal reinitializes local variable x during each call
void useLocal(){
    int x{25};

    cout << " \nlocal x is " << x << " on entering useLocal" << endl;
    ++x;
    cout << " local x is " << x << " on exiting useLocal" << endl;
}
// useStaticLoacl initializes static local variable x only
// the first time the function is called;
// value if x is saved between calls to this funcion
void useStaticLocal(){
    static int x{50}; // initialized first time useStaticLocal is called

    cout << "\nlocal static x is " << x << " on entering useStaticLocal" << endl;
    ++x;
    cout << "local static x is " << x << " on exiting useStaticLocal" << endl;
} 

//useGlobal modifies global variable x during each call
void useGlobal(){
    cout << "\nglobal x is " << x << " on entering useGlobal" << endl;
    x *= 10;
    cout << " global x is " << x << " on exiting useGlobal" << endl;
}