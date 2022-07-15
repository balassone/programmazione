//testCLinkedList
#include <iostream>
#include "CLinkedList.h"
using std::string;
int main(){
	CircleList<std::string> playList;
	//tunes I should learn
	std::cout << "Hey, this is our playList"<< std::endl;
	playList.add("Autumn leaves");
	playList.add("Mo' Better Blues");
	playList.add("Waltz for Debbie");
	playList.add("So What");
	playList.advance();
	playList.advance();
	std::cout<< playList.toString() << std::endl;
	playList.remove();
	playList.add("Caravan");
	std::cout << playList.toString() << std::endl;
	playList.reverse();
	std::cout << "Reverse \n" << playList.toString() << std::endl;
	std::cout << "\n size of the Playlist is " << playList.size();
	std::cout << "\n first element of the Playlist is "<< playList[0] << "cursor elem is " <<playList.front();
	std::cout << "\n last element of the Playlist is "<< playList[playList.size()-1]<< "cursor elem is " <<playList.back()<<std::endl;
	std::cout << playList.toString()<< std::endl;
	CircleList<std::string> trapboy(playList);
	std::cout << "Costruttore di copia \n" << trapboy.toString()<<std::endl;
	if(trapboy == playList)
	std::cout << "le due liste sono uguali" <<std::endl;
	trapboy.addBack("Magazine");
	if(trapboy == playList)
	std::cout << "le due liste sono uguali" <<std::endl;
	else std::cout << "le due liste sono diverse" << std::endl;
	std::cout << trapboy.toString()<<std::endl;
	return 0;
}