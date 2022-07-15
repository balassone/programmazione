//testDestrctors.cpp
// Order in which constructors and destructors are called
#include <iostream> 
#include "CreateAndDestroy.h" // include CreateAndDestroy class definition
using std::cout; using std::endl;

void create(); //prototype

CreateAndDestroy first{1, "(Global before main)"}; // global function

int main(){
    cout << "\n MAIN FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy second {2, "(local in main)"};
    static CreateAndDestroy third{3, "(local static in main)"};

    create(); // call function to create objects

    cout << "\n MAIN FUNCTION: EXECUTION RESUMES" << endl;
    CreateAndDestroy fourth{4, "(local in main)"};
    cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;
}

// function to create objects
void create() {
    cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy fifth{5, "(local in create)"};
    static CreateAndDestroy sixth{6, "(local static in create)"};
    CreateAndDestroy seventh{7, "(local in create)"};
    cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
}