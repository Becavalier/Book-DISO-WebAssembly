class WebIDL {
public:
	WebIDL (int x, int y) : x(x), y(y) {}
	int getValueXByValue (void) const {
		return x;
	}

	const WebIDL& passThroughByReference (WebIDL &i) const {
		return i;
	}

	const int x;
	int y;
};