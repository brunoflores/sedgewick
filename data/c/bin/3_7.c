#include <stdio.h>
#include <stdlib.h>

int heads(void) { return rand() < RAND_MAX / 2; }

int main(int __attribute__((unused)) argc, char *argv[]) {
  int i;
  int j;
  int cnt = 0;
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  int *f = malloc((N + 1) * sizeof(int));
  for (j = 0; j <= N; j++) {
    f[j] = 0;
  }

  for (i = 0; i < M; i++, f[cnt]++) {
    for (cnt = 0, j = 0; j <= N; j++) {
      if (heads() == 1) {
        cnt++;
      }
    }
  }

  for (j = 0; j <= N; j++) {
    printf("%2d ", j);
    for (i = 0; i < f[j]; i += 10) {
      printf("*");
    }
    printf("\n");
  }
}
