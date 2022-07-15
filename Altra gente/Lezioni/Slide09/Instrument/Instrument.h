#include <iostream>
using std::cout;
using std::endl;
enum note {middleC, Csharp, Cflat }; 

class Instrument {
public:
	virtual void play(note) const {
		cout << "instrument::play" << endl;
	}
	std::string what() const {
		return "instrument";
	}
	// assume this wil modify the object:
	virtual void adjust(int) {}
};

// Wind objects are Instruments 
// because they have the same interface:
class Wind : public Instrument {
public:
	// Redefine interface function:
	void play(note) const{
		cout << "Wind::play" << endl;
	}
	std::string what() const {return "Wind"; }
	void adjust(int) {}
};

class Percussion : public Instrument {
public:
	void play(note) const {
		cout << "Percussion::play" << endl;
	}
	std::string what() const { return "Percussion"; }
	void adjust(int) {}
};

class Stringed : public Instrument {
public:
	void play(note) const {
		cout << "Stringed::play" << endl;
	}
	std::string what() const {return "Stringed"; }
	void adjust(int) {}
};

class Brass : public Wind{
public:
	void play(note) const {
		cout << "Brass::play" << endl;
	}
	std::string what() const { return "Brass"; }
};

class Woodwind : public Wind {
public: 
	void play(note) const {
	cout << "Woodwind::play" << endl;	
	}	
	
	std::string what() const {return "Woodwind"; }
};