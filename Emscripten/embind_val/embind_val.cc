#include <emscripten/val.h>
#include <emscripten/bind.h>
#include <string>
#include <iostream>

using namespace emscripten;

val getDefaultStrValue (void) {
	return val("YHSPY");
}

val getDefaultIntValue (void) {
	int _t = 10;
	return val(_t);
}

void manipulateDOM (val content) {
	val documentInstance = val::global("document");
	if (!documentInstance.as<bool>()) {
		std::cout << "No 'window.document' object found!" << std::endl;
		return;
	}
	documentInstance.call<void>("write", content);
	return;
}

void mountTime () {
	val moduleInstance = val::global("Module");
	val DateContext = val::global("Date");
	if (!moduleInstance.as<bool>()) {
		std::cout << "No 'Module' object found!" << std::endl;
		return;
	}
	val dateInstance = DateContext.new_();
	moduleInstance.set("currentTimestamp", dateInstance.call<val>("getTime"));
	return;
}


EMSCRIPTEN_BINDINGS(module) {
  function("getDefaultStrValue", &getDefaultStrValue);
  function("getDefaultIntValue", &getDefaultIntValue);
  function("manipulateDOM", &manipulateDOM);
  function("mountTime", &mountTime);
}
