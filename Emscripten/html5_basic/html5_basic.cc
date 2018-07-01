#include <iostream>
#include <emscripten/html5.h>

using namespace std;
EM_BOOL em_keyboard_event_callback (int eventType, const EmscriptenKeyboardEvent *e, void *userData) {
  cout << e->key << endl;
  return EM_TRUE;
}

int main (int argc, char **argv) {
  emscripten_set_keypress_callback("#window", nullptr, EM_FALSE, &em_keyboard_event_callback);

  // unsupported feature;
  EmscriptenBatteryEvent *emscriptenBatteryEvent;
  EMSCRIPTEN_RESULT result = emscripten_get_battery_status(emscriptenBatteryEvent);
  if (result == EMSCRIPTEN_RESULT_NOT_SUPPORTED) {
  	cerr << "[Battery] Feature not support!" << endl;
  }
  fflush(stdout);
  return 0;
}
