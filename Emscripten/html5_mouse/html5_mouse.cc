#include <emscripten/html5.h>
#include <emscripten.h>

using namespace std;

EM_BOOL em_mouse_event_callback (int eventType, const EmscriptenMouseEvent *e, void *userData) {
  auto x = e->targetX;
  auto y = e->targetY;

  EM_ASM_({
    let x = $0;
    let y = $1;
    document.querySelector("body").style['backgroundColor'] = `#${x}${y}`;
  }, x, y);

  return EM_TRUE;
}

int main (int argc, char **argv) {
  emscripten_set_mousemove_callback("#window", nullptr, EM_FALSE, &em_mouse_event_callback);
  return 0;
}
