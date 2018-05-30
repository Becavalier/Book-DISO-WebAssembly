#include <emscripten.h>

int main (int argc, char **argv) {
  int x = 100;
  EM_ASM_({
    console.log("This value is from C++: ", $0);
  }, x);

  return 0;
}
