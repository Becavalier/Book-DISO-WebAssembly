
#include <emscripten.h>

class ImplXClass : public xClass {
public:
  int virtualFunc(int arg0) {
    return EM_ASM_INT({
      var self = Module['getCache'](Module['ImplXClass'])[$0];
      if (!self.hasOwnProperty('virtualFunc')) throw 'a JSImplementation must implement all functions, you forgot ImplXClass::virtualFunc.';
      return self['virtualFunc']($1);
    }, (int)this, arg0);
  }
  void __destroy__() {
    EM_ASM_INT({
      var self = Module['getCache'](Module['ImplXClass'])[$0];
      if (!self.hasOwnProperty('__destroy__')) throw 'a JSImplementation must implement all functions, you forgot ImplXClass::__destroy__.';
      self['__destroy__']();
    }, (int)this);
  }
};

extern "C" {

// Not using size_t for array indices as the values used by the javascript code are signed.
void array_bounds_check(const int array_size, const int array_idx) {
  if (array_idx < 0 || array_idx >= array_size) {
    EM_ASM({
      throw 'Array index ' + $0 + ' out of bounds: [0,' + $1 + ')';
    }, array_idx, array_size);
  }
}

// xClass

int EMSCRIPTEN_KEEPALIVE emscripten_bind_xClass_virtualFunc_1(xClass* self, int arg0) {
  return self->virtualFunc(arg0);
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_xClass_runVirtualFunc_2(xClass* self, xClass* arg0, int arg1) {
  return self->runVirtualFunc(arg0, arg1);
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_xClass___destroy___0(xClass* self) {
  delete self;
}

// VoidPtr

void EMSCRIPTEN_KEEPALIVE emscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

// ImplXClass

ImplXClass* EMSCRIPTEN_KEEPALIVE emscripten_bind_ImplXClass_ImplXClass_0() {
  return new ImplXClass();
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_ImplXClass_virtualFunc_1(ImplXClass* self, int arg0) {
  return self->virtualFunc(arg0);
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_ImplXClass___destroy___0(ImplXClass* self) {
  delete self;
}

}

