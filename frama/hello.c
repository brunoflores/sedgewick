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

// Reset its first parameter if and only if the second is true.
/*@
  requires \valid(a) && \valid_read(b);
  requires \separated(a, b);

  assigns *a;

  ensures \old(*b) ==> *a == 0;
  ensures ! \old(*b) ==> *a == \old(*a);
  ensures *b == \old(*b);
*/
void reset_1st_if_2nd_is_true (int *a, int const *b) {
  if (*b) *a = 0;
}

// Receive two pointers and returns the sum of the pointed values.
/*@
  requires \valid_read(p) && \valid_read(q);
  requires INT_MIN <= *p + *q <= INT_MAX;

  assigns \nothing;

  ensures \result == *p + *q;
*/
int add(int *p, int *q) { return *p + *q; }

/*@
  requires \valid_read(a) && \valid_read(b);

  assigns \nothing;

  ensures *a < *b ==> \result == *b;
  ensures *a >= *b ==> \result == *a;
  ensures \result == *a || \result == *b;
*/
int max_ptr(int *a, int *b) { return (*a < *b) ? *b : *a; }

/*@
  requires \valid(a) && \valid(b) && \valid(c);
  requires \separated(a, b, c);

  assigns *a, *b, *c;

  ensures *a <= *b <= *c;
  ensures { *a, *b, *c } == \old({ *a, *b, *c });

  ensures \old(*a == *b == *c) ==> *a == *b == *c;
  ensures \old(*a == *b < *c || *a == *c < *b || *b == *c < *a) ==> *a == *b;
  ensures \old(*a == *b > *c || *a == *c > *b || *b == *c > *a) ==> *b == *c;
*/
void order_3 (int *a, int *b, int *c) {
  int tmp;
  if (*a > *b) {
    tmp = *b; *b = *a; *a = tmp;
  }
  if (*a > *c) {
    tmp = *c; *c = *a; *a = tmp;
  }
  if (*b > *c) {
    tmp = *b; *b = *c; *c = tmp;
  }
}

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

  int aa = 5;
  int const x = 0;
  //@ assert aa == 5;
  reset_1st_if_2nd_is_true(&aa, &x);
  //@ assert aa == 5;
  //@ assert x == 0;
  int const bb = 1;
  reset_1st_if_2nd_is_true(&aa, &bb);
  //@ assert aa == 0;
  //@ assert bb == 1;

  int p = 24;
  int q = 42;
  int xx;
  xx = add(&p, &q);
  //@ assert xx == p + q;
  //@ assert xx == 66;
  xx = add(&p, &p);
  //@ assert xx == p + p;
  //@ assert xx == 48;

  int aaa = 24;
  int bbb = 42;
  int xxx = max_ptr (&aaa, &bbb);
  //@ assert xxx == 42;

  int a1 = 5;
  int b1 = 3;
  int c1 = 4;
  order_3(&a1, &b1, &c1);
  //@ assert a1 == 3 && b1 == 4 && c1 == 5;

  int a2 = 2;
  int b2 = 2;
  int c2 = 2;
  order_3(&a2, &b2, &c2);
  //@ assert a2 == b2 == c2 == 2;

  int a3 = 4;
  int b3 = 3;
  int c3 = 4;
  order_3(&a3, &b3, &c3);
  //@ assert a3 == 3 && (b3 == c3 == 4);

  int a4 = 4;
  int b4 = 5;
  int c4 = 4;
  order_3(&a4, &b4, &c4);
  //@ assert (a4 == b4 == 4) && c4 == 5;

  return 0;
}
