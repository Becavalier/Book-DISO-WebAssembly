#include <emscripten/bind.h>

using namespace emscripten;

enum OldStyle {
  OLD_STYLE_ONE,
  OLD_STYLE_TWO
};

enum class NewStyle {
  ONE,
  TWO
};

EMSCRIPTEN_BINDINGS(module) {
  enum_<OldStyle>("OldStyle")
    .value("ONE", OLD_STYLE_ONE)
    .value("TWO", OLD_STYLE_TWO);
  enum_<NewStyle>("NewStyle")
    .value("ONE", NewStyle::ONE)
    .value("TWO", NewStyle::TWO);
}