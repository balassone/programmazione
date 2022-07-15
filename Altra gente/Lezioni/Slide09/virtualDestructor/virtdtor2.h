//virtdtor.h
class Base{
public:

	Base() : base_memory(new char[1000]) { }
	virtual ~Base() {delete [] base_memory; } // now virtual
	
private:
	char * base_memory;	
};

class Derived: public Base
public:
	Derived() : Base(), derived_memory(new char[1000]) { }
	virtual ~Derived() {delete []derived_memory; } 	 // now virtual
private:
	char *derived_memory;
}
