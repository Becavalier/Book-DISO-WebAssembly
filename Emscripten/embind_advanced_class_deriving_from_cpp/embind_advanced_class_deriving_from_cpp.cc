#include <emscripten/bind.h>
#include <string>

using namespace emscripten;

class BaseClass {
public:
	BaseClass() = default;
	// virtual std::string invoke(const std::string &str) = 0;
	virtual std::string invoke(const std::string &str) {
		return str + " - from 'BaseClass'";
	}
};

class DerivedClass : public BaseClass {
public:
	DerivedClass() = default;
	std::string invoke(const std::string &str) override {
		return str + " - from 'DerivedClass'";
	}
};

EMSCRIPTEN_BINDINGS(module) {
  class_<BaseClass>("BaseClass")
  	.constructor<>()
  	.function("invoke", &BaseClass::invoke);
  class_<DerivedClass, base<BaseClass>>("DerivedClass")
  	.constructor<>()
  	.function("invoke", &DerivedClass::invoke);
}
