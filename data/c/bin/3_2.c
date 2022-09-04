#include "Num.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void avg(int);

int main(int argc, char *argv[]) {
  int index;
  for (index = optind; index < argc; index++) {
    avg(atoi(argv[index]));
  }
  return 0;
}

void avg(int const N) {
  printf("Called with %d\n", N);

  int i;
  float m1 = 0.0;
  float m2 = 0.0;
  Number x;

  for (i = 0; i < N; i++) {
    x = randNum();
    m1 += ((float)x) / N;
    m2 += ((float)x * x) / N;
  }

  printf("Average: %f\n", m1);
  printf("Std. deviation: %f\n", sqrt(m2 - (m1 * m1)));
}
