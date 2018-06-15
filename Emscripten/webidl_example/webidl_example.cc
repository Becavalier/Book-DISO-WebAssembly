class WebIDL {
public:
	WebIDL (int x, std::string str) : x(x), str(str) {}
	int getValueX (void) const {
		return x;
	}
	const char* getValueStr (void) const {
		return str.c_str();
	}
private:
	int x;
	std::string str;
};