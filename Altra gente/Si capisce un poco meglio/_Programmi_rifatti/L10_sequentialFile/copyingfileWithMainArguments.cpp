//copyingfileWithMainArguments.cpp
#include<iostream>
#include<fstream>
#include<cstdlib>
using std::ifstream;
using std::ofstream;
using std::ios;
using std::cout;
using std::endl;

int main(int argc, char* argv[] ) {
    if (argc != 3){
        std::cerr<<"Usage: "<<argv[0]<<" file1 file2\n";
        exit(EXIT_FAILURE);
    }
    char* buffer = NULL;
    int length = 0;
    {
        ifstream is(argv[1], ios::in);
        if (!is){
            std::cerr<<"File could not be opened"<<endl;
            exit(EXIT_FAILURE);
        }
        is.seekg(0, ios::end);
        length = is.tellg();
        is.seekg(0, ios::beg);
        is.read(buffer, length);
        is.clear();
    }
    {
        ofstream os(argv[2], ios::out);
        if (!os){
            std::cerr<<"File could not be opened"<<endl;
            delete[] buffer;
            exit(EXIT_FAILURE);
        }
        os.write(buffer, length);
        delete[] buffer;
        os.clear();
    }
}