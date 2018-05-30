#include <emscripten.h>

int main (int argc, char **argv) {
  emscripten_run_script("console.log('Hello, WebAssembly!')");
  return 0;
}
