#include <emscripten/bind.h>
#include <string>

using namespace emscripten;

class baseClass {
  int age;
  std::string name;
 public:
	baseClass(int age, std::string name) : age(age), name(name) {};
	std::string getName() {
		return name;
	}
};


baseClass* makeClassFactory(int age, std::string name) {
	class xClass : public baseClass {
	 public:
		xClass (int age, std::string name) : baseClass(age, name) {}
  };
	return dynamic_cast<baseClass*>(new xClass(age, name));
}

EMSCRIPTEN_BINDINGS(module) {
    class_<baseClass>("xClass")
    	.constructor(&makeClassFactory, allow_raw_pointers())
    	.function("getName", &baseClass::getName);
}
