#include "ListaStack.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main(){

    ListaStack<string> myArray;

    myArray.push("uno");
    myArray.push("due");
    myArray.push("tre");
    myArray.push("quattro");
    myArray.pop();
    cout<<"La dimesione è: "<<myArray.size()<<endl;
    cout<<"L'elemento in cima allo stack è: "<<myArray.top();




}