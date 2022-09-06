#include "item.h"
#include "stack.h"
#include <stdlib.h>

static Item *s;
static int N;

void stack_init(int maxN) {
  s = malloc(maxN * sizeof(Item));
  N = 0;
}

int stack_empty(void) { return N == 0; }

void stack_push(Item item) { s[N++] = item; }

Item stack_pop(void) { return s[--N]; }
