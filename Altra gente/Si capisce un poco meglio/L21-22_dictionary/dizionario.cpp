//dizionario.cpp
//program to implement a simple english-italian dictionary
#include<iostream>
#include<vector>
#include"dict.h"
#include <fstream>
#include<iomanip>
#include<cstdlib>
#include<limits>
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::ios;


int binSearchWord(const string, const vector<Word>&);
void addWord(const string, const string,  vector<Word>&);
void loadDictionary(const string,  vector<Word>&);
void writeDictionary(const string, const vector<Word>&);

int main(){
    int choice{0};
    const string DICTIONARY{"eng_it.dict"};
    string word;
    vector<Word> words; //list of words

    //load dictionary from file
    loadDictionary(DICTIONARY, words);

    cout<<"\nWelcome to the English-Italian dictionary: "<<endl;

    while (true){
        //display menu
        cout<<"\nWhat would you like to do?\n"<<endl;
        cout<<"[1] Search"<<endl;
        cout<<"[2] Add a word"<<endl;
        cout<<"[3] View dictionary"<<endl;
        cout<<"[4] Quit"<<endl;
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:{ //search for word
                string word;
                cout<<"Enter English word to search in small letters";
                cin>>word;
                int pos=binSearchWord(word, words);
                if (pos<0){
                    cout<<"---\n"<<endl;
                    cout<<"\n'"<<word<<"'"<<" not found.\n";
                    cout<<"---\n"<<endl;
                }
                else {
                    Word w{words[pos]};
                    cout<<"---"<<endl;
                    cout<<"\n'"<<word<<"' means '"<<w.getItWord()<<"'\n"<<endl;
                    cout<<"---"<<endl;
                    }
            }
            break;
            case 2: {
                //add a word to dictionary
                string engWd, itWd;
                cout<<"Enter an english word";
                cin>>engWd;
                cout<<"Enter the Italian translation";
                cin>>itWd;
                int pos= binSearchWord(engWd, words);
                if (pos<0){
                    addWord(engWd,itWd,words);
                    cout<<"'"<<engWd<<"' added to dictionary."<<endl;
                }
                else {
                    cout<<"\n'"<<"' is already in the dictionary."<<endl;
                }
                break;
            }
            case 3: {    
                cout<<endl;
                cout<<"Dictionary contents:"<<endl;
                for (unsigned int i{0}; i<words.size();i++){
                    Word wd = words[i];
                    cout<<setw(12)<<left<<wd.getEngWord()<<setw(12)<<wd.getItWord()<<endl;
                }
            }
            break;
            
            case 4: {//quit
            writeDictionary(DICTIONARY, words);
            cout<<"Bye!"<<endl;
            exit(EXIT_SUCCESS);
            }
            break;
            
            default : {
                cout<<"\nWrong choice. Must be a number between 1--3."<<endl;
                cin.clear();
            }
        }
    }
    return 0;       
}

void loadDictionary(const string dictFile, vector<Word>& words){
    //loads dictionary words from a file into a vector
    string engWord, itWord;
    ifstream inFile(dictFile, ios::in);

    if(!inFile){
        cerr<<"File could not be opened."<<endl;
        exit(EXIT_FAILURE);
    }
    while(inFile>>engWord>>itWord){
        words.push_back(Word{engWord, itWord});
    }
    inFile.close();
}

int binSearchWord(const string searchWd, const vector<Word>& words){
    //searches the dictionary for a word
    //return an empty string if the word is not found
    //exercise: do a case-insensitive search

    string itWord, engWord;
    int n=words.size();
    int left=0;
    int right=n-1;

    while(left<=right){
        int mid=(right+left)/2;
        Word w{words[mid]};
        if(w.getEngWord()==searchWd){
            return mid;
        }
        if(w.getEngWord()<searchWd){
            left=mid+1;
        }
        else {
            right=mid-1;
        }
    }
    return -1;
}

void addWord(const string engWord, const string itWord, vector <Word>& dict){
    //VERY INEFFICIENT!!!!!!!!!!!!!!!!!!!!!!!!
    Word w{engWord, itWord};
    unsigned int i=0;
    while (i<dict.size()){
        Word c{dict[i]};
        if(c.getEngWord() < engWord){
            i++;
        }
        else break;
    }
    dict.insert(dict.begin()+i,w);
}

void writeDictionary(const string dictFile, const vector<Word>& words){
    //writes the content of vector words into file
    //should sort the words
    string engWord, itWords;
    ofstream outFile{dictFile, ios::out};
    
    if(!outFile){
        cerr<<"File could not be opened"<<endl;
        exit(EXIT_FAILURE);
    }

    string engWord;
    string itWord;
    for (unsigned int i{0}; i<words.size(); i++){
        Word wd=words[i];
        engWord=wd.getEngWord();
        itWord=wd.getItWord();
        outFile<<engWord<<"\t"<<itWord;
    }
    outFile.close();
}