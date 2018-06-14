#include <emscripten/bind.h>
#include <string>

using namespace emscripten;

class OverloadClass {
public:
	OverloadClass() = default;
	std::string foo () const {
		return "Signature: ()";
	}

	std::string foo (int x) {
		return "Signature: (int x)";
	}

	std::string foo (int x, int y) {
		return "Signature: (int x, int y)";
	}
};

EMSCRIPTEN_BINDINGS(module) {
  class_<OverloadClass>("OverloadClass")
  	.constructor<>()
  	.function("foo_v", select_overload<std::string(void) const>(&OverloadClass::foo))
  	.function("foo_i", select_overload<std::string(int)>(&OverloadClass::foo))
  	.function("foo_ii", select_overload<std::string(int, int)>(&OverloadClass::foo));
}
