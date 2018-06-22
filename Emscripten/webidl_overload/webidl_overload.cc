class WebIDL {
public:
	WebIDL (int x) : x(x) {}
	int getValueXByValue (void) const {
		return x;
	}
	int operator[](int x) { 
		return x * 2; 
	}
	int x;
};


