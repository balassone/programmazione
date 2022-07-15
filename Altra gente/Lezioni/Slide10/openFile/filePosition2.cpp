#include <iostream>
#include <fstream>
using std::endl;
using std::cout;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::ios;
int main(int argc, char* argv[]) {
	if (argc != 3 ){
		cerr << "Usage: " << argv[0] << "file 1 file2\n";
		exit(EXIT_FAILURE);
	}
	char *buffer = NULL; int length = 0;
	{
		ifstream is(argv[1]);
		if(!is) {
			cout << "Error opening file" << endl;
			return 1;
		}
		is.seekg(0, ios::end); 	 // move to *end* of file
		length = is.tellg();  	 // get my offset into file
		is.seekg(0, ios::beg); 	  // move to *beginning* of file
		buffer = new char[length];
		is.read(buffer, length); 	// read file contents 
	} // is going out of scope and is closed
	
	{
		ofstream os(argv[2]);
		if(!os) {
			cout << "Error opening file" << endl;
			delete[] buffer;
			return 1;
		}
		
		os.write(buffer, length);
		delete[] buffer;
	} // os goes out of scope and is closed return 0;
}