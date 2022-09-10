#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)                                                             \
  {                                                                            \
    Item t = A;                                                                \
    A = B;                                                                     \
    B = t;                                                                     \
  }
#define compexch(A, B)                                                         \
  if (less(B, A))                                                              \
  exch(A, B)

// Intertion sort.
void sort(Item a[], int l, int r) {
  int i;
  int j;
  for (i = l + 1; i <= r; i++) {
    for (j = i; j > l; j--) {
      compexch(a[j - 1], a[j]);
    }
  }
}

int main(int __attribute__((unused)) argc, char *argv[]) {
  int i;
  int N = atoi(argv[1]);
  int *a = malloc(N * sizeof(int));

  for (i = 0; i < N; i++) {
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
  }

  sort(a, 0, N - 1);

  for (i = 0; i < N; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");

  return 0;
}
