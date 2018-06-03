#include <iostream>
#include <math.h>

using namespace std;

extern "C" {
  extern int custom_add (int x, int y);
}

int main () {
  int x = 10, y = 100;
  cout << custom_add(x, y) << endl;

  return 0;
}
