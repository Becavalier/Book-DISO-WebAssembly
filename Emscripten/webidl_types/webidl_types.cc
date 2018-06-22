class WebIDL {
public:
	WebIDL () = default;
	bool returnBool () {
		return true;
	}
	float returnFloat () {
		return 1.5;
	}
	double returnDouble () {
		return 1.5;
	}
	char returnChar () {
		return 'A';
	}
	const char* returnString () {
		return "WebAssembly";
	}
	unsigned char returnUChar () {
		return 'B';
	}
	unsigned short int returnUSInt () {
		return 10;
	}
	unsigned short returnUShort () {
		return 10;
	}
	unsigned long returnLong () {
		return 10l;
	}
};


