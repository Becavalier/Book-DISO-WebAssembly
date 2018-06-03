#include <iostream>
#include <emscripten.h>

using namespace std;

int main (int argc, char **argv) {
  int x = 100;
  double y;
  y = EM_ASM_DOUBLE({
    return $0 + 100.1;
  }, x);

  cout << y << endl;
  return 0;
}
