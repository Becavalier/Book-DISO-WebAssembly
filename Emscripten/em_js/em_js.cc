#include <emscripten.h>
#include <iostream>

using namespace std;

EM_JS(int, add, (int x, int y), {
	console.log(x, y);
  return x + y;
});

int main(int argc, char** argv) {
  cout << add(1, 2) << endl;
  return 0;
}

/*

#define EM_JS(ret, name, params, ...)          \
   _EM_JS_CPP_BEGIN                             \
   ret name params;                             \
   __attribute__((used, visibility("default"))) \
   const char* __em_js__##name() {              \
     return #params "<::>" #__VA_ARGS__;        \
   }                                            \
   _EM_JS_CPP_END

 #endif // __em_js_h__

*/
