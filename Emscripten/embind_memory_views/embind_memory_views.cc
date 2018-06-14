#include <emscripten/bind.h>

#include <emscripten/val.h>

using namespace emscripten;

unsigned char _t [] = {'a', 'b', 'c'};

unsigned char *byteBuffer = _t;
size_t bufferLength = sizeof(_t) / sizeof(unsigned char);

val getBytes() {
  return val(typed_memory_view(bufferLength, byteBuffer));
}

EMSCRIPTEN_BINDINGS(module) {
    function("getBytes", &getBytes);
}
