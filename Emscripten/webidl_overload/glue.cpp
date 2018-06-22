
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

WebIDL* EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_WebIDL_1(int arg0) {
  return new WebIDL(arg0);
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_getValueXByValue_0(WebIDL* self) {
  return self->getValueXByValue();
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_doubleNum_1(WebIDL* self, int arg0) {
  return ((*self)[arg0]);
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_get_x_0(WebIDL* self) {
  return self->x;
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_set_x_1(WebIDL* self, int arg0) {
  self->x = arg0;
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL___destroy___0(WebIDL* self) {
  delete self;
}

// VoidPtr

void EMSCRIPTEN_KEEPALIVE emscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

}

