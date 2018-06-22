
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

WebIDL* EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_WebIDL_2(int arg0, int arg1) {
  return new WebIDL(arg0, arg1);
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_getValueXByValue_0(WebIDL* self) {
  return self->getValueXByValue();
}

const WebIDL* EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_passThroughByReference_1(WebIDL* self, WebIDL* arg0) {
  return &self->passThroughByReference(*arg0);
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_get_x_0(WebIDL* self) {
  return self->x;
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_get_y_0(WebIDL* self) {
  return self->y;
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_set_y_1(WebIDL* self, int arg0) {
  self->y = arg0;
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL___destroy___0(WebIDL* self) {
  delete self;
}

// VoidPtr

void EMSCRIPTEN_KEEPALIVE emscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

}

