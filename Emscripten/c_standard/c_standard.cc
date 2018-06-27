#include <emscripten.h>
#include <cmath>
#include <iostream>

using namespace std;

extern "C" {
	int EMSCRIPTEN_KEEPALIVE m_sqrt (int x) {
		return sqrt(x);
	}

	double EMSCRIPTEN_KEEPALIVE m_asin (double x) {
		return asin(x);
	}

	void EMSCRIPTEN_KEEPALIVE m_print () {
		cout << "Hello, WebAssembly!" << endl;
	}
}