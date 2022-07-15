#include "Account.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
    double withdrow;
    Account a1{"Ferdinando",3500};
    Account a2{"Antonio",5000};

    cout<<"Account a1:"<<endl;
    cout<<a1.getName()<<endl;
    cout<<a1.getBalance()<<endl;

    cout<<"How much do you want to withdraw from account a1?"<<endl;
    cin>>withdrow;
    a1.Withdrow(withdrow);
    cout<<"The new balance of account a1 is : "<<a1.getBalance();

    return 0;

}