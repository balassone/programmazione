#include <iostream>
#include "CLinkedList.h"

using std::string;
int main(){
    CircleList<std::string> playList;
    std::cout << "Hey, this is our playList" << std::endl;
    playList.add("Autumn leaves");
    playList.add("Mo' Better Blues");
    playList.add("Waltz for Debbie");
    playList.add("So What");
    playList.advance();
    playList.advance();
    std::cout << playList.toString() << std::endl;
    playList.remove();
    playList.add("Caravan");
    std::cout << playList.toString() << std::endl;
    return 0;
}