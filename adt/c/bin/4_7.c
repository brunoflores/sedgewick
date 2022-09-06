#include "union_find.h"
#include <stdio.h>
#include <stdlib.h>

int main(int __attribute__((unused)) argc, char *argv[]) {
  int p;
  int q;
  int N = atoi(argv[1]);
  uf_init(N);
  while (scanf("%d %d\n", &p, &q) == 2) {
    if (!uf_find(p, q)) {
      uf_union(p, q);
      printf(" %d %d\n", p, q);
    }
  }
}
