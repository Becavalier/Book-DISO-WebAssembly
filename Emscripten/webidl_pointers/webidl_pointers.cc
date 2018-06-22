class WebIDL {
public:
	WebIDL (int x) : x(x) {}
	int getValueXByValue (void) const {
		return x;
	}
	WebIDL* returnNull (void) const {
		return nullptr;
	}
	void* returnVoidPtr (WebIDL* t) const {
		return t;
	}
	void* returnAnyPtr (WebIDL* t) const {
		return t;
	}
	int x;
};


