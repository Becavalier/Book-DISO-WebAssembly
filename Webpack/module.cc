#include <emscripten.h>

extern "C" int EMSCRIPTEN_KEEPALIVE add (int a, int b) {
	return a + b;
}