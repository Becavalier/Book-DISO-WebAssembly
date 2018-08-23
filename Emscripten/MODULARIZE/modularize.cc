#include <emscripten.h>
#include <iostream>

using namespace std;

int main (int argc, char **argv) {
  cout << "Hello, Emscripten!" << endl;
  return 0;
}

extern "C" int EMSCRIPTEN_KEEPALIVE add (int x, int y) {
	return x + y;
}