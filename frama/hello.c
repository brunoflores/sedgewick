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

  assigns \nothing;

  ensures \result >= 0;
  ensures (val >= 0 ==> \result == val) &&
          (val <  0 ==> \result == -val);
*/
int abs(int val) {
  if (val < 0)
    return -val;
  return val;
}

/*@
  requires \valid(q);
  requires \valid(r);
  requires \separated(q, r);
  requires y != 0;

  assigns *q, *r;

  ensures div: (*q) * y + (*r) == x;
  ensures rem: (*r) < y;
*/
void div_rem(unsigned x, unsigned y, unsigned *q, unsigned *r) {
  *q = x / y;
  *r = x % y;
}

/*@
  requires \valid_read(a);
  requires *a <= INT_MAX - 5;

  assigns \nothing;

  ensures \result == *a + 5;
*/
int plus_5(int *a) { return *a + 5; }

/*@
  requires \valid(a) && \valid_read(b);
  requires \separated(a, b);
  requires *a >= 0 && *b >= 0;
  requires (*a + *b) < INT_MAX;
  assigns *a;
  ensures *a == \old(*a) + *b;
  ensures *b == \old(*b);
*/
void incr_a_by_b(int *a, int const *b) { *a += *b; }

int h = 42;

/*@ assigns \nothing; */
int main() {
  int a = 42;
  int b = 37;

  //@ assert h == 42;
  swap(&a, &b);
  //@ assert a == 37 && b == 42;
  //@ assert h == 42;

  int c = abs(-42);
  //@ assert got_42: c == 42;

  unsigned div = 0;
  unsigned rem = 0;
  div_rem(4, 2, &div, &rem);
  //@ assert div == 2;

  return 0;
}
