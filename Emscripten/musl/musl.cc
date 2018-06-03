#include <stdio.h>
#include <math.h>

double wrap_cos (double f) {
  return cos(f);
}

int main (int argc, char **argv) {
  printf("%f\n", wrap_cos(10));
  return 0;
}
