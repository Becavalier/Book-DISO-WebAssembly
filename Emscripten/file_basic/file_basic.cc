#include <stdio.h>

int main(int argc, char **argv) {
  FILE *file = fopen("data/core_data.txt", "rb");
  if (!file) {
    printf("Cannot open this file!\n");
    return 1;
  }
  while (!feof(file)) {
    char c = fgetc(file);
    if (c != EOF) {
      putchar(c);
    }
  }
  fclose (file);
  return 0;
}