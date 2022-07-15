//dict.cpp
//definition of class Word
#include"dict.h"

Word::Word(std::string eng, std::string it) : 
engWord(eng), itWord(it) {}

std::string Word::getEngWord(){
    return engWord;
}
std::string Word::getItWord(){
    return itWord;
}

void Word::setEngWord(std::string word){
    engWord=word;
}
void Word::setItWord(std::string word){
    itWord=word;
}