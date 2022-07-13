#include <stdio.h>

// For simplicity.
#define N 10

int main(void) {
  int i;
  int p;
  int q;
  int t;

  // Array indexed by object names.
  int id[N];

  // Initialise the array.
  for (i = 0; i < N; i++) {
    id[i] = i;
  }

  while (scanf("%d %d", &p, &q) == 2) {
    if (id[p] == id[q]) {
      // Quick find: p and q are connected.
      continue;
    }

    // Connect p to q.
    for (t = id[p], i = 0; i < N; i++) {
      // Change all entries with id[p] to id[q].
      if (id[i] == t) {
        id[i] = id[q];
      }
    }

    // Output.
    printf(" %d %d\n", p, q);
  }
}
