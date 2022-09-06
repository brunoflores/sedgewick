#include "item.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

int main(int argc __attribute((unused)), char *argv[]) {
  char *a = argv[1];
  int i;
  int N = strlen(a);
  stack_init(N);
  for (i = 0; i < N; i++) {
    if (a[i] == '+') {
      stack_push(stack_pop() + stack_pop());
    }
    if (a[i] == '*') {
      stack_push(stack_pop() * stack_pop());
    }
    if ((a[i] >= '0') && (a[i] <= '9')) {
      stack_push(0);
    }
    while ((a[i] >= '0') && (a[i] <= '9')) {
      stack_push((10 * stack_pop()) + (a[i++] - '0'));
    }
  }
  printf("%d \n", stack_pop());
}

// Usage:
// $ ./4_2 "41 1 +"
// 42
