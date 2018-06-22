
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

// VoidPtr

void EMSCRIPTEN_KEEPALIVE oemscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

// xClass

xClass* EMSCRIPTEN_KEEPALIVE oemscripten_bind_xClass_xClass_1(int arg0) {
  return new xClass(arg0);
}

void EMSCRIPTEN_KEEPALIVE oemscripten_bind_xClass___destroy___0(xClass* self) {
  delete self;
}

// xClass_zEnum
xClass_zEnum EMSCRIPTEN_KEEPALIVE emscripten_enum_xClass_zEnum_c_enum_val1() {
  return xClass::c_enum_val1;
}
xClass_zEnum EMSCRIPTEN_KEEPALIVE emscripten_enum_xClass_zEnum_c_enum_val2() {
  return xClass::c_enum_val2;
}

// xEnum
xEnum EMSCRIPTEN_KEEPALIVE emscripten_enum_xEnum_enum_val1() {
  return enum_val1;
}
xEnum EMSCRIPTEN_KEEPALIVE emscripten_enum_xEnum_enum_val2() {
  return enum_val2;
}

// WebAssembly_yEnum
WebAssembly_yEnum EMSCRIPTEN_KEEPALIVE emscripten_enum_WebAssembly_yEnum_ns_enum_val1() {
  return WebAssembly::ns_enum_val1;
}
WebAssembly_yEnum EMSCRIPTEN_KEEPALIVE emscripten_enum_WebAssembly_yEnum_ns_enum_val2() {
  return WebAssembly::ns_enum_val2;
}

}

