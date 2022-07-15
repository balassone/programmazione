//copyingfile.cpp
#include<iostream>
#include<fstream>
#include<cstdlib> //for exit function
using std::ifstream;
using std::ofstream;
using std::ios;
using std::cout;
using std::endl;

int main() {
    char* buffer = NULL;
    int length = 0;
    {
        ifstream is("hello2.txt", ios::in);
        if (!is){
            std::cerr<<"File could not be opened"<<endl;
            exit(EXIT_FAILURE);
        }
        //understand how much to read
        is.seekg(0,ios::end);
        length = is.tellg();
        //returning to the begin
        is.seekg(0, ios::beg);
        //allocating in "buffer" quantity of memory calculated  in "length"
        buffer = new char[length];
        //reading file content
        is.read(buffer, length); 
    }
    {
        ofstream os("hello2.txt", ios::out);
        if (!os){
            std::cerr<<"File could not be opened"<<endl;
            delete[] buffer;
            exit(EXIT_FAILURE);
        }
        os.write(buffer, length);
        delete[] buffer;
    }

}