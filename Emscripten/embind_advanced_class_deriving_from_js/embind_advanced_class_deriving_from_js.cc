#include <emscripten/bind.h>
#include <string>

using namespace emscripten;

class Interface {
public:
	Interface() = default;
	// virtual std::string invoke(const std::string &str) = 0;
	virtual std::string invoke(const std::string &str) {
		return str + " - from 'C++'";
	}
};

// Glue between JavaScript and C/C++;
class DerivedClass : public wrapper<Interface> {
public:
	EMSCRIPTEN_WRAPPER(DerivedClass);
	std::string invoke(const std::string &str) override {
		return call<std::string>("invoke", str);
	}
};

EMSCRIPTEN_BINDINGS(module) {
    class_<Interface>("Interface")
    	// .function("invoke", &Interface::invoke, pure_virtual())
    	.function("invoke", optional_override([](Interface &self, const std::string &str){
    		return self.Interface::invoke(str);
    	}))
    	// "extend" && "implement"
    	.allow_subclass<DerivedClass>("DerivedClass");
}
