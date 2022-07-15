#include<iostream>
#include<fstream>
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::ios;

int main(int argc, char* argv[]){
    if (argc!=3){
        cerr<<"Usage: "<<argv[0]<< " file1, file2\n";
        exit(EXIT_FAILURE);
    }
    char* buffer=NULL; int length=0;
    {
        ifstream is(argv[1]);
        if(!is){
            cout<<"Error opening file"<<endl;
            return 1;
        }
        is.seekg(0,ios::end);
        length=is.tellg();
        is.seekg(0);
        buffer=new char[length];
        is.read(buffer, length);
    }
    {
        ofstream os(argv[2]);
        if(!os){
            cout<<"Error opening file"<<endl;
            delete[] buffer;
            return 1;
        }
        os.write(buffer, length);
        delete[] buffer;
    }
}