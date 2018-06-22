
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

WebIDL* EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_WebIDL_0() {
  return new WebIDL();
}

bool EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_returnBool_0(WebIDL* self) {
  return self->returnBool();
}

float EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_returnFloat_0(WebIDL* self) {
  return self->returnFloat();
}

double EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_returnDouble_0(WebIDL* self) {
  return self->returnDouble();
}

char EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_returnChar_0(WebIDL* self) {
  return self->returnChar();
}

const char* EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_returnString_0(WebIDL* self) {
  return self->returnString();
}

unsigned char EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_returnUChar_0(WebIDL* self) {
  return self->returnUChar();
}

unsigned short EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_returnUSInt_0(WebIDL* self) {
  return self->returnUSInt();
}

unsigned short EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_returnUShort_0(WebIDL* self) {
  return self->returnUShort();
}

unsigned int EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL_returnLong_0(WebIDL* self) {
  return self->returnLong();
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_WebIDL___destroy___0(WebIDL* self) {
  delete self;
}

// VoidPtr

void EMSCRIPTEN_KEEPALIVE emscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

}

