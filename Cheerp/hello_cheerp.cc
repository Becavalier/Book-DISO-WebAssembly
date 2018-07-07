#include <cheerp/clientlib.h>
#include <cheerp/client.h>

[[cheerp::genericjs]] void domOutput(const char* str) {
  client::console.log(str);
}

void webMain() {
  domOutput("Hello World");
}
