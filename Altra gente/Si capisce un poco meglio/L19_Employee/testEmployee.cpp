//testEmployee.cpp
#include<iomanip>
#include<iostream>
#include<vector>
#include"Employee.h"
#include"SalariedEmployee.h"
#include"CommissionEmployee.h"
#include"BasePlusCommissionEmployee.h"
using std::cout;
using std::vector;
void virtualViaPointer(const Employee* const); //prototype
void virtualViaReference(const Employee&); //prototype

int main(){
    cout<<std::fixed<<std::setprecision(2);

    SalariedEmployee salariedEmployee{"Paul", "Chambers", "111-11-11111", 800};

    CommissionEmployee commissionEmployee{"Bill", "Evans", "333-33-33333",10000, .06};
    
    BasePlusCommissionEmployee basePlusCommissionEmployee{"Miles","Davis","444-44-44444",5000,.04,300};

    cout<<"EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"<<
    salariedEmployee.toString()
    <<"\nearned $"<<salariedEmployee.earnings()<<"\n\n"
    <<commissionEmployee.toString()
    <<"\nearned $"<<commissionEmployee.earnings()<<"\n\n"
    <<basePlusCommissionEmployee.toString()
    <<"\nearned $"<<salariedEmployee.earnings()<<"\n\n";

    //create and initialize a vector of three base-class pointers
    vector<Employee *> employees{&salariedEmployee, &commissionEmployee, &basePlusCommissionEmployee};

    cout<<"EMPLOYEES PROCESSED POLYMORPHICALLY VIA DINAMIC BINDING\n\n";

    //call virtualViaPointer to print each Employee's information
    //and earnings using dynamic binding
    cout<<"VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n";

    for(const Employee* employeePtr : employees) {
        virtualViaPointer(employeePtr);
    }

    //call virtualViaReference to print each Employee's information
    //and earnings using dynamic binding

    cout<<"VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n";

    for(const Employee* employeePtr : employees){
        virtualViaReference(*employeePtr);
    }
}

//call Employee virtual functions toString() and earnings() off a
//base-class pointer using dynamic binding
void virtualViaPointer(const Employee* baseClassPtr){
    cout<<baseClassPtr->toString()
    <<"\nearned $"<<baseClassPtr->earnings()<<"\n\n";
}
//call Employee virtual functions toString() and earnings() off a
//base-class reference using dynamic binding
void virtualViaReference(const Employee& baseClassRef){
    cout<<baseClassRef.toString()
    <<" nearned $"<<baseClassRef.earnings()<<"\n\n";
}