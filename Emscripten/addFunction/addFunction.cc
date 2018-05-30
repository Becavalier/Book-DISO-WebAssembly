#include <iostream>
#include <emscripten.h>

using namespace std;

extern "C" void EMSCRIPTEN_KEEPALIVE wrapper(int fp) {
  cout << "The function pointer is: " << fp << endl;
  void (*f)(int) = reinterpret_cast<void (*)(int)>(fp);
  f(7);
  EM_ASM_(Module.removeFunction($0), f);
}
