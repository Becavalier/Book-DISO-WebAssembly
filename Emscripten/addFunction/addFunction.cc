#include <iostream>
#include <emscripten.h>

using namespace std;

void fack (int y) {
  ;
}

extern "C" void EMSCRIPTEN_KEEPALIVE wrapper(int fp) {
  using fpt = void (*)(int);

  fpt fackp = fack;
  fackp(10);

  cout << "The function pointer is: " << fp << endl;
  fpt f = reinterpret_cast<fpt>(fp);
  f(7);
  EM_ASM_({
    Module.removeFunction($0);
  }, f);
}
