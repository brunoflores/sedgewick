#include <stdio.h>

// For simplicity.
#define N 10

int main(void) {
  int i;
  int j;
  int p;
  int q;

  // Array indexed by object names.
  int id[N];

  // Initialise the array.
  for (i = 0; i < N; i++) {
    id[i] = i;
  }

  while (scanf("%d %d", &p, &q) == 2) {
    // Find.
    for (i = p; i != id[i]; i = id[i])
      ;
    for (j = q; j != id[j]; j = id[j])
      ;
    if (i == j)
      continue;

    // Union.
    id[i] = j;

    // Output.
    printf(" %d %d\n", p, q);
  }
}
