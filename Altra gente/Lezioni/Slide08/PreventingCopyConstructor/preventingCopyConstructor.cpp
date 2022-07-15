// Preventing copy construction
class NoCC {
	int i;
	NoCC(Const NoCC&); 	// no definition
public: 
	NoCC(int ii=0) : i(ii) {}
};

void f(NoCC);

int main() {
	NoCC n;
	//! f(n); Erroe:copy-constructor called
	//! NoCC n2 = n; // Error: c-c called
	//! NoCC n3(n); // Error: c-c called
}