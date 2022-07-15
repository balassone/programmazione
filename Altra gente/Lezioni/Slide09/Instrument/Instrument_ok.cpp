// Inheritance & upcasting

#include <iostream>
using std::cout;
using std::endl;
enum note {middleC, Csharp, Eflat } ; //etc

class Instrument {
public:
	virtual void play(note) const {
		cout << "instrument::play" << endl;
	}
};

// Wind objects are Instruments 
// because they have the same interface:
class Wind : public Instrument {
public:
	// Redefine interface function:
	void play(note) const{
		cout << "Wind::play" << endl;
	}
};

void tune(Instrument& i) {
	// this function will play a note for an given instrument
	i.play(middleC);
}

int main() {
	Wind flute;
	tune(flute);
}