#include <cmath>
#include <emscripten.h>

extern "C" {
  double EMSCRIPTEN_KEEPALIVE doubleSqrt(double x) {
    return sqrt(x);
  }

  // 参数为“C-style”字符串；
  unsigned char* EMSCRIPTEN_KEEPALIVE capitalize (unsigned char *string) {
    int i = 0;
    while (1) {
      // 获取每个位置字符的 ASCII 编码值；
      char _current_pos = *(string + i);

      // 转换为对应的大写字符；
      if (_current_pos >= 0x61 && _current_pos <= 0x7a) {
        *(string + i) = _current_pos - 32;
      }

      // 如果处理到字符串结尾退出循环；
      if (_current_pos == '\0') {
        break;
      }

      i++;
    }

    return string;
  }

  // 将数组内的所有元素值均重置为“1”；
  char* EMSCRIPTEN_KEEPALIVE increment (char array[], int length) {
    for (int i = 0; i < length; i++) {
      array[i] = array[i] + 2;
    }
    return array;
  }
}
