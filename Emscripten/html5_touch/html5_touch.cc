#include <emscripten/html5.h>
#include <emscripten.h>
#include <vector>
#include <cmath>

#define DEFAULT_POINR_INDEX 0

using namespace std;

static vector<long> START_POINT;

double calMoveDistance (long x, long y) {
  return sqrt(abs(y * y - x * x));
}

EM_BOOL em_touchstart_event_callback (int eventType, const EmscriptenTouchEvent *e, void *userData) {
  START_POINT = vector<long>{
    e->touches[DEFAULT_POINR_INDEX].screenX, 
    e->touches[DEFAULT_POINR_INDEX].screenY
  };
  return EM_TRUE;
}

EM_BOOL em_touchend_event_callback (int eventType, const EmscriptenTouchEvent *e, void *userData) {
  long x = e->touches[DEFAULT_POINR_INDEX].screenX;
  long y = e->touches[DEFAULT_POINR_INDEX].screenY;
  double distance = calMoveDistance(y - START_POINT[1], x - START_POINT[0]);

  EM_ASM_({
    console.log(`Drag for "${$0.toFixed(2)}px"`);
  }, distance);

  return EM_TRUE;
}


int main (int argc, char **argv) {
  emscripten_set_touchstart_callback("#window", nullptr, EM_FALSE, &em_touchstart_event_callback);
  emscripten_set_touchend_callback("#window", nullptr, EM_FALSE, &em_touchend_event_callback);

  return 0;
}
