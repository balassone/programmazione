#include "List.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main(){

    List<string> l{};
    l.insertOrder("barca");
    l.insertOrder("auto");
    l.insertOrder("divano");
    l.insertOrder("casa");

    for(string i: l){
        cout<<i<<endl;
    }
}