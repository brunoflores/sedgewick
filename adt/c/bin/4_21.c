// Driver program that uses the polynomial ADT. It takes an integer N and a
// floating-point number p from the command line, computes (x+1)^N, and checks
// the result by evaluating the resulting polynomial at x = p.

#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

int main(int __attribute__((unused)) argc, char *argv[]) {
  int N = atoi(argv[1]);
  float p = atof(argv[2]);
  Poly t;
  Poly x;
  int i;

  printf("Binomial coefficients\n");
  t = Poly_add(Poly_term(1, 1), Poly_term(1, 0));
  for (i = 0, x = t; i < N; i++) {
    x = Poly_mult(t, x);
    {
      char *s = Poly_show(x);
      printf("%s\n", s);
      free(s);
    }
  }
  printf("%f\n", Poly_eval(x, p));
}
