#include <emscripten/bind.h>

using namespace emscripten;

double add (double x, double y) {
  return x + y;
}

EMSCRIPTEN_BINDINGS(module) {
  function("add", &add);
}

