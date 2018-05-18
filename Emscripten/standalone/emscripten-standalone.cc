#include <emscripten.h>

#ifdef __cplusplus
extern "C" {
#endif

  EMSCRIPTEN_KEEPALIVE int add (int x, int y) {
    return x + y;
  }

#ifdef __cplusplus
}
#endif
