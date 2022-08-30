#include <limits.h>

/*@
  requires \valid(a) && \valid(b);
  assigns *a, *b;
  ensures *a == \old(*b);
  ensures *b == \old(*a);
*/
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/*@
  requires INT_MIN < val;

  ensures \result >= 0;
  ensures (val >= 0 ==> \result == val) &&
          (val <  0 ==> \result == -val);
*/
int abs(int val) {
  if (val < 0)
    return -val;
  return val;
}

int main() {
  int a = 42;
  int b = 37;

  swap(&a, &b);
  //@ assert a == 37 && b == 42;

  int c = abs(-42);
  //@ assert got_42: c == 42;

  return 0;
}
