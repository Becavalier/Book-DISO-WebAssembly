#include <emscripten.h>

int main (int argc, char **argv) {
  EM_ASM(
    console.log("Hello WebAssembly! #1");
  );
  EM_ASM(
    console.log("Hello WebAssembly! #2");
  );
  return 0;
}
