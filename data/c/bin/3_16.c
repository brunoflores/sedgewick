#include <stdlib.h>

int **malloc2d(int r, int c) {
  int **t = malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++) {
    t[i] = malloc(c * sizeof(int));
  }
  return t;
}

int main(void) { return 0; }

// Allocate an M-by-N array of integers:
// int **a = malloc2d(M, N);
