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

  // For each object with id[i] == i, keep the number of nodes in the associated
  // tree.
  int sizes[N];

  // Initialise the arrays.
  for (i = 0; i < N; i++) {
    id[i] = i;
    sizes[i] = 1;
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
    if (sizes[i] < sizes[j]) {
      id[i] = j;
      sizes[j] += sizes[i];
    } else {
      id[j] = i;
      sizes[i] += sizes[j];
    }

    // Output.
    printf(" %d %d\n", p, q);
  }
}
