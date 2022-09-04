#include "Point.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float randFloat(void) { return 1.0 * rand() / RAND_MAX; }

int main(int __attribute__((unused)) argc, char *argv[]) {
  float d = atof(argv[2]);
  int i;
  int j;
  int cnt = 0;
  int N = atoi(argv[1]);
  point *a = malloc(N * sizeof(*a));

  for (i = 0; i < N; i++) {
    a[i].x = randFloat();
    a[i].y = randFloat();
  }

  for (i = 0; i < N; i++) {
    for (j = i + 1; j < N; j++) {
      if (distance(a[i], a[j]) < d) {
        cnt++;
      }
    }
  }

  free(a);

  printf("%d edges shorter than %f\n", cnt, d);
}
