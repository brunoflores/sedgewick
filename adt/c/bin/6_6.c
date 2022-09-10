#include "array.h"
#include "item.h"
#include <stdlib.h>

int main(int __attribute__((unused)) argc, char *argv[]) {
  int N = atoi(argv[1]);
  int sw = atoi(argv[2]);
  Item *a = malloc(N * sizeof(Item));
  if (sw) {
    randinit(a, N);
  } else {
    scaninit(a, &N);
  }
  sort(a, 0, N - 1);
  show(a, 0, N - 2);
}
