#include "complex_abstract.h"
#include <stdlib.h>

struct complex {
  float Re;
  float Im;
};

Complex Complex_init(float Re, float Im) {
  Complex t = malloc(sizeof *t);
  t->Re = Re;
  t->Im = Im;
  return t;
}

float Re(Complex z) { return z->Re; }
float Im(Complex z) { return z->Im; }

Complex Complex_mult(Complex a, Complex b) {
  return Complex_init(Re(a) * Re(b) - Im(a) * Im(b),
                      Re(a) * Im(b) + Im(a) * Re(b));
}
