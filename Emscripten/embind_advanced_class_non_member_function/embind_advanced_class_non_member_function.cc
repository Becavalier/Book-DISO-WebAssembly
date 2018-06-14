#include <emscripten/bind.h>

using namespace emscripten;

class xClass {
public:
	xClass(int x) : x(x) {};

	int getVal (void) const {
		return x;
	}

	void setVal (int val) {
		x = val;
	}

private:
	int x;
};

void add (xClass &i, int x) {
	i.setVal(i.getVal() + x);
}

EMSCRIPTEN_BINDINGS(module) {
  class_<xClass>("xClass")
    .constructor<int>()
    .function("getVal", &xClass::getVal)
    .function("add", &add);
}
