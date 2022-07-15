#include <iostream> 
using std::cout;
using std::endl;

enum saxtype {SOPRANO, ALTO, TENOR, BARITONE};

class Saxophonist {
public:
	static int saxCount;
	static void print(const std::string& msg = "") {
		if (msg.size() != 0) cout << msg << ": "; cout << "saxCount = " << saxCount << endl;
	}
	// Constructor definition
	Saxophonist(std::string n, saxtype p): name{n}, plays {p}{
		cout << "Constructor called." << endl;
		// Increase every time object is created
		saxCount++;
	}
	~Saxophonist() {
		//cout << "~Saxophonist() called" << endl;
		print("~Saxophonist()");
		--saxCount;
	}
private:
	std::string name;			// musician name
	saxtype plays;				// type of sax played
};

int Saxophonist::saxCount{0};

Saxophonist f(Saxophonist s){
	s.print(" x argument inside f()");
	return s;
}

int main(void) {
	cout << "Number of available saxophonists before definition" <<Saxophonist::saxCount<<endl;
	{
		Saxophonist m1("John Coltrane", TENOR);		// Declare Musician1
		Saxophonist m2("Cannonball Hadderley", ALTO);		// Declare Musician2
		Saxophonist m3("Steve Lacy" , SOPRANO);			// Declare Musician 3

		// print total number of objects.
		cout << "Total objects in scope: " << Saxophonist::saxCount << endl;
	}
	cout << "Total objects outside the scope: " << Saxophonist::saxCount << endl;
	cout << "Check default copy constructor" << endl;
	Saxophonist m1("John Coltrane", TENOR);
	Saxophonist m2 = f(m1);
	Saxophonist::print("after call to f(): ");
	return 0;
}
	