#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::vector; 


void swap(vector<Account*> &a, int i, int j){
    Account *temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(vector<Account*> &a, int l, int r){
    int i = l-1;
    int j = r+1;
    Account *x = a[l];
    do{
        i++;
    }while (*x<*a[i]);
    do{
        j--;
    }while(*a[j] < *x);
    if(i < j){
        swap(a,i,j);
    }
    else 
    return j;

    
}


void quickSort(vector<Account*> &a, int l, int r){
    int l = 0;
    int r = a.size()-1;
    int q = partition(a, l, r);
    quickSort(a, l, q);
    quickSort(a, q+1, r);
}



int main(){

vector<Account*> accounts;

Account Account1("TizioCaio", 50.00);
SavingsAccount Account2("Sempronio", 70.00);
CheckingAccount Account3("Boh", 60.0);

accounts.push_back(&Account1);
accounts.push_back(&Account2);
accounts.push_back(&Account3);

quickSort(accounts, 0, accounts.size()-1);







}