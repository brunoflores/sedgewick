#include <stdlib.h>

void **malloc2d(int r, int c, unsigned long s) {
  void **t = malloc(r * s);
  for (int i = 0; i < r; i++) {
    t[i] = malloc(c * s);
  }
  return t;
}

float randFloat(void) { return 1.0 * rand() / RAND_MAX; }
