#include "complex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592625

int main(int __attribute__((unused)) argc, char *argv[]) {
  int i;
  int j;
  int N = atoi(argv[1]);
  Complex t;
  Complex x;
  printf("%dth complex roots of unity\n", N);
  for (i = 0; i < N; i++) {
    float r = 2.0 * PI * i / N;
    t = Complex_init(cos(r), sin(r));
    printf("%2d %6.3f %6.3f ", i, Re(t), Im(t));
    for (x = t, j = 0; j < N - 1; j++) {
      x = Complex_mult(t, x);
    }
    printf("%6.3f %6.3f\n", Re(x), Im(x));
  }
}

// Usage:
// $ ./4_13 8
// 8th complex roots of unity
//  0  1.000  0.000  1.000  0.000
//  1  0.707  0.707  1.000  0.000
//  2 -0.000  1.000  1.000  0.000
//  3 -0.707  0.707  1.000  0.000
//  4 -1.000 -0.000  1.000  0.000
//  5 -0.707 -0.707  1.000 -0.000
//  6  0.000 -1.000  1.000  0.000
//  7  0.707 -0.707  1.000 -0.000
