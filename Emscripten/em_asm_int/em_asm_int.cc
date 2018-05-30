#include <emscripten.h>
#include <iostream>

using namespace std;

int main (int argc, char **argv) {
  int x = EM_ASM_INT({
    console.log('This value is from C++: ' + $0);
    return $0 + 1;
  }, 100);

  cout << x << endl;
  return 0;
}
