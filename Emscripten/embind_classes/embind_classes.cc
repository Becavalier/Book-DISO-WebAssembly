#include <emscripten/bind.h>
#include <string>

using namespace std;
using namespace emscripten;

class xClass {
public:
	// 构造方法；
	xClass (int x, string y): x(x), y(y) {}

	// 成员函数；
	void incrementX () {
		x += 1;
	}

	// [GETTER]
	int getValueX () const {
		return x;
	}	
	// [SETTER]
	void setValueX (int val) {
		x = val;
	}

	// 静态方法；
	static string getStringValue (const xClass& instance) {
		return instance.y;
	}

private:
	int x;
	string y;
};

EMSCRIPTEN_BINDINGS(module) {
	class_<xClass>("xClass")
		.constructor<int, string>()
		.function("incrementX", &xClass::incrementX)
		.property("x", &xClass::getValueX, &xClass::setValueX)
		.class_function("getStringValue", &xClass::getStringValue);
}