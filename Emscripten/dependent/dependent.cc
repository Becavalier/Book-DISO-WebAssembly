#include <emscripten.h>
#include <iostream>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif
  // 函数定义，利用Emscripten提供的“宏”来防止函数被DCE处理掉；
  EMSCRIPTEN_KEEPALIVE void echo (int x) {
    cout << "The number you input is: " << x << endl;
  }

#ifdef __cplusplus
}
#endif

