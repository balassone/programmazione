//test.cpp
#include<iostream>
#include"CreateAndDestroy.h"
using std::cout; using std::endl;

void create();

CreateAndDestroy first(1, "global before main");

int main(){
    cout<<"\nMAIN FUNCTION: EXECUTION BEGINS"<<endl;
    CreateAndDestroy second {2, "(local in main)"};
    static CreateAndDestroy third{3, "(local static in main)"};

    create();

    cout<<"\nMAIN FUNCTION: EXECUTION RESUMES"<<endl;
    CreateAndDestroy fourth{4, "(local in main)"};
    cout<<"\nMAIN FUNCTION: EXECUTION ENDS"<<endl;
}

void create() {
    cout<<"\nCREATE FUNCTION: EXECUTION BEGINS"<<endl;
    CreateAndDestroy fifth{5, "(local in create)"};
    static CreateAndDestroy sixth{6, "(local static in create)"};
    CreateAndDestroy seventh{7,"(local in create)"};
    cout<<"\nCREATE FUNCTION: EXECUTION ENDS"<<endl;
}