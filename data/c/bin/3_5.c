#include <stdio.h>
#include <stdlib.h>

int main(int __attribute__((unused)) argc, char *argv[]) {
  int i;
  int j;
  int N = atoi(argv[1]);

  int *a = malloc(N * sizeof(int));
  if (a == NULL) {
    printf("Insufficient memory.\n");
    return 1;
  }

  for (i = 2; i < N; i++) {
    a[i] = 1;
  }

  for (i = 2; i < N; i++) {
    if (a[i] == 1) {
      for (j = i; i * j < N; j++) {
        a[i * j] = 0;
      }
    }
  }

  for (i = 2; i < N; i++) {
    if (a[i] == 1) {
      printf("%4d ", i);
    }
  }
  printf("\n");

  free(a);
}
