//fileposition.cpp
#include<iostream>
#include<fstream>
using std::endl;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::ios;

int main() {
    char* buffer = NULL; int length=0;
    {
        ifstream is("hello.txt");
        if(!is){
            cout<<"Error opening file"<<endl;
            return 1;
        }
        is.seekg(0, ios::end); //move to *end* of file
        length=is.tellg(); //get my offset into file
        is.seekg(0,ios::beg); //move to *beginning* of file
        buffer=new char[length];
        is.read(buffer, length); //read files contents
    } //is goes out of scope and is closed
    {
        ofstream os("hello2.txt");
        if (!os){
            cout<<"Error opening file"<<endl;
            delete[] buffer;
            return 1;
        }
        os.write(buffer, length);
        delete[] buffer;
    } //os goes out of scope and is closed return 0;
}