//virtdtor.h
class Base{
public:

	Base() : base_memory(new char[1000]) { }
	~Base() {delete [] base_memory; }
	
private:
	char * base_memory;	
};

class Derived: public Base
public:
	Derived() : Base(), derived_memory(new char[1000]) { }
	~Derived() {delete []derived_memory; }
private:
	char *derived_memory;
}
