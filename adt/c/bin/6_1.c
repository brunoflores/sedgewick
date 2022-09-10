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

void insertion(Item a[], int l, int r) {
  int i;
  int j;
  for (i = l + 1; i <= r; i++) {
    for (j = i; j > l; j--) {
      // N^2
      compexch(a[j - 1], a[j]);
    }
  }
}

// This is an improvement over the above because:
//   a. it first puts the smallest element in the array into the first position,
//      so that that element can serve as a sentinel;
//   b. it does single assignment in the inner loop;
//   c. it terminates the inner loop when the element being inserted is in
//      position.
void insertion_6_3(Item a[], int l, int r) {
  int i;
  for (i = r; i > l; i--) {
    compexch(a[i - 1], a[i]);
  }
  for (i = l + 2; i <= r; i++) {
    int j = i;
    Item v = a[i];
    while (less(v, a[j - 1])) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
  }
}

void selection(Item a[], int l, int r) {
  int i;
  int j;
  for (i = l; i < r; i++) {
    int min = i;
    for (j = i + 1; j <= r; j++) {
      if (less(a[j], a[min])) {
        min = j;
      }
    }
    exch(a[i], a[min]);
  }
}

int main(int __attribute__((unused)) argc, char *argv[]) {
  int i;
  int N = atoi(argv[1]);
  int *a = malloc(N * sizeof(int));

  for (i = 0; i < N; i++) {
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
  }

  // insertion(a, 0, N - 1);
  selection(a, 0, N - 1);

  for (i = 0; i < N; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");

  return 0;
}
