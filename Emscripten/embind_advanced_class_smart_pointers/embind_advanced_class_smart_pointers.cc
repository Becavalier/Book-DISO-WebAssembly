#include <emscripten/bind.h>
#include <memory>

using namespace emscripten;


class Class {
public:
  Class(int x) : x(x) {}

  inline int getX () const {
    return x;
  }
  inline void setX(int val) {
    x = val;
  }
private:
  int x;
};


std::shared_ptr<Class> passThrough(Class *ptr) {
  return std::shared_ptr<Class>(ptr);
}


std::unique_ptr<int> passToUniquePtr (int v) {
  return std::unique_ptr<int>(new int(v));
}



EMSCRIPTEN_BINDINGS(module) {
  class_<Class>("Class")
  	.constructor<int>()
  	.smart_ptr<std::shared_ptr<Class>>("shared_ptr<Class>")
    .property("x", &Class::getX, &Class::setX);

  function("passThrough", &passThrough, allow_raw_pointers());
  function("passToUniquePtr", &passToUniquePtr);
}


/*
EMSCRIPTEN_BINDINGS(module) {
  class_<Class>("Class")
  	.smart_ptr_constructor("shared_ptr<Class>", &std::make_shared<Class, int>)
    .property("x", &Class::getX, &Class::setX);
*/