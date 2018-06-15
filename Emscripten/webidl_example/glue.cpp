
#include <emscripten.h>

extern "C" {

// Not using size_t for array indices as the values used by the javascript code are signed.
void array_bounds_check(const int array_size, const int array_idx) {
  if (array_idx < 0 || array_idx >= array_size) {
    EM_ASM({
      throw 'Array index ' + $0 + ' out of bounds: [0,' + $1 + ')';
    }, array_idx, array_size);
  }
}

// WebIDL

WebIDL* EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_WebIDL_2(int arg0, char* arg1) {
  return new WebIDL(arg0, arg1);
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_getValueX_0(WebIDL* self) {
  return self->getValueX();
}

const char* EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_getValueStr_0(WebIDL* self) {
  return self->getValueStr();
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL___destroy___0(WebIDL* self) {
  delete self;
}

// VoidPtr

void EMSCRIPTEN_KEEPALIVE emscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

}

