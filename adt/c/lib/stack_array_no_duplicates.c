// This pushdown-stack assumes integer items between 0 and maxN-1.

#include "item.h"
#include "stack.h"
#include <stdlib.h>

static int *s;
static int *t;
static int N;

void stack_init(int maxN) {
  s = malloc(maxN * sizeof(int));
  t = malloc(maxN * sizeof(int));
  for (int i = 0; i < maxN; i++) {
    t[i] = 0;
  }
  N = 0;
}

int stack_empty(void) { return !N; }

void stack_push(int item) {
  if (t[item] == 1) {
    return;
  }
  s[N++] = item;
  t[item] = 1;
}

int stack_pop(void) {
  N--;
  t[s[N]] = 0;
  return s[N];
}
