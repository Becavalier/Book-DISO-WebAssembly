#include <emscripten/bind.h>
#include <string>

using namespace emscripten;

class baseClass {
public:
	baseClass() = default;
	virtual std::string getName() = 0;
};


baseClass* makeClassFactory(int age, std::string name) { 
	class xClass : public baseClass {
	public:
		xClass (int age, std::string name) : age(age), name(name) {}
		virtual std::string getName() {
			return name;
		}

	private:
		int age;
		std::string name;
	};

	return dynamic_cast<baseClass*>(new xClass(age, name));
}

EMSCRIPTEN_BINDINGS(module) {
    class_<baseClass>("xClass")
    	.constructor(&makeClassFactory, allow_raw_pointers())
    	.function("getName", &baseClass::getName);
}
