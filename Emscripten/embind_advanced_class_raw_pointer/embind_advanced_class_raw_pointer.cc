#include <emscripten/bind.h>

using namespace emscripten;

class xClass {
public:
	xClass(int x) : x(x) {}

	inline int getX () const {
		return x;
	}
	inline void setX(int val) {
		x = val;
	}
private:
	int x;
};


xClass* passThrough(xClass* ptr) { 
	return ptr; 
}

EMSCRIPTEN_BINDINGS(module) {
    class_<xClass>("xClass")
    	.constructor<int>()
    	.property("x", &xClass::getX, &xClass::setX);

    function("passThrough", &passThrough, allow_raw_pointers());
}
