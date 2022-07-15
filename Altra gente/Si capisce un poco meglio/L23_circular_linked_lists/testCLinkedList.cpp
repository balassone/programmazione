//testCLinkedList.cpp
#include<iostream>
#include"CircleLinkedList.h"
#include<string>
using std::string;

int main(){
    CircleList<string> playList;
    //tunes I should learn
    std::cout<<"Hey, this is our playList"<<std::endl;
    playList.add("Autumn leaves");
    playList.add("Mo' Better Blues");
    playList.add("Waltz for Debbie");
    playList.add("So What");
    playList.advance();
    playList.advance();
    std::cout<<playList.toString()<<std::endl;
    playList.add("Caravan");
    std::cout<<playList.toString()<<std::endl;
    return 0;
}
